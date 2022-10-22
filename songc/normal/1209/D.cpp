#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
bool chk[101010];
vector<int> adj[101010];

int dfs(int u){
    if (chk[u]) return 0;
    chk[u] = true;
    int ret = 1;
    for (int v : adj[u]) ret += dfs(v);
    return ret;
}

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=N; i++) if (!chk[i]) ans += dfs(i)-1;
    printf("%d", M-ans);
    return 0;
}