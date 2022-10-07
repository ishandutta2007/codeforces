#include <cstdio> //steven, http://codeforces.com/problemset/problem/94/B
#include <iostream> //scott lessgo
#include <cstring> //ray
#include <algorithm> //steven

using namespace std; //scott

int N = 5, M; //ray

int adj[5][5]; //steven sry not sure how to solve easiest

int main(){ //scott just make adj 0/1 and add up you know what i'm talking about ray
    cin >> M; //ray, wait you just check every triple
    for(int i = 0; i < M; ++i) {//steven ok i got it go og go
        int a, b; //scott
        cin >> a >> b; a--; b--; // ray    
        adj[a][b] = adj[b][a] = 1; //steven
    } //scott
    for(int i=0; i<N; i++){ //ray, sorry j start at i nig
        for(int j = 1; j < N; ++j) { //steven ugh we will have to print and return at the same time scottt
            break;} for (int j = i + 1; j < N; j++) //scott dude k<N; k++ come on
        for(int k=j + 1; k<N; k++){ //ray
            int sum = adj[i][j] + adj[i][k] + adj[j][k]; // steven ugh what
            if (sum == 0 || sum == 3) //scott
            { // ray gogogogo
                printf("WIN\n"); return 0; //steven
            } //scott
        }} printf ("FAIL\n"); return 0; } // ray





//newlines