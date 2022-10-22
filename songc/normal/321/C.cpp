#include <bits/stdc++.h>
using namespace std;

int N;
int S[101010];
bool del[101010];
char ans[101010];
vector<int> L[101010];

void Size(int u, int p){
    S[u] = 1;
    for (int v : L[u]) {
        if (del[v] || v == p) continue;
        Size(v, u);
        S[u] += S[v];
    }
}

int center(int u, int root, int p){
    for (int v : L[u]){
        if (del[v] || v == p) continue;
        if (S[v] > S[root]/2) return center(v, root, u);
    }
    return u;
}

void DnC(int u, char r){
    Size(u, 0);
    u = center(u, u, 0);
    ans[u] = r, del[u] = true;
    for (int v : L[u]) {
        if (del[v]) continue;
        DnC(v, r+1);
    }
}

int main(){
    int u, v;
    scanf("%d", &N);
    for (int i=1; i<N; i++){
        scanf("%d %d", &u, &v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    DnC(1, 'A');
    for (int i=1; i<=N; i++) printf("%c ", ans[i]);
    return 0;
}