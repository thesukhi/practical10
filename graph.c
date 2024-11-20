#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Adjacency List Node
struct Node {
    int vertex;
    struct Node* next;
};

// Adjacency List Representation
struct Node* adjList[MAX_VERTICES];

// Function to create a new adjacency list node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdgeList(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;  // For undirected graph
}

// Depth-First Search (DFS) for Adjacency List
void DFSList(int vertex, int visited[MAX_VERTICES]) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    struct Node* temp = adjList[vertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFSList(temp->vertex, visited);
        }
        temp = temp->next;
    }
}

// Breadth-First Search (BFS) for Adjacency List
void BFSList(int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        struct Node* temp = adjList[current];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

// Main function to test the graph
int main() {
    // Initialize adjacency list
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjList[i] = NULL;
    }

    addEdgeList(0, 1);
    addEdgeList(0, 2);
    addEdgeList(1, 3);
    addEdgeList(2, 4);

    printf("DFS Traversal: ");
    int visited[MAX_VERTICES] = {0};
    DFSList(0, visited);
    printf("\n");

    printf("BFS Traversal: ");
    BFSList(0);
    printf("\n");

    return 0;
}