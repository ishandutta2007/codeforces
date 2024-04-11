#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, R, B, ans;
int C[303030];
vector<int> L[303030];

pii dfs(int u, int p){
    pii k = {0, 0};
    if (C[u] == 1) k.first++;
    if (C[u] == 2) k.second++;
    for (int v : L[u]){
        if (v == p) continue;
        pii ret = dfs(v, u);
        k.first += ret.first;
        k.second += ret.second;
    }
    if ((R-k.first && B-k.second) || (k.first && k.second)) ans--;
    return k;
}

int main(){
    int u, v;
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &C[i]);
        if (C[i] == 1) R++;
        if (C[i] == 2) B++;
    }
    for (int i=1; i<N; i++){
        scanf("%d %d", &u, &v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    ans = N;
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}