#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;
typedef pair<int, int> P;

int n,a;
set<int> G[N];
bool vis[N];
vector<int> res;
int depth[N], par[N];
priority_queue<P> pque;

int dfs(int v, int d){
    vis[v] = true;
    depth[v] = d;
    for(int nxt : G[v]){
        if(!vis[nxt]) dfs(nxt, d+1), par[nxt] = v;
    }
}

int dedfs(int v){
    vis[v] = 1;
    res.push_back(v);
    for(int nxt : G[v]){
        if(!vis[nxt] && nxt != par[v]) dedfs(nxt);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        if(a != 0) G[a].insert(i), G[i].insert(a);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        if(G[i].size() % 2 == 0) pque.push({depth[i], i});
    }
    fill(vis, vis+N, 0);

    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        int i = p.second;
        if(vis[i] || G[i].size() % 2 != 0) continue;
        //cout << i;
        dedfs(i);
        if(par[i] != 0) G[par[i]].erase(i);
        if(par[i] != 0 && G[par[i]].size() % 2 == 0) pque.push({depth[par[i]], par[i]});
    }
    if(res.size() != n) return !printf("NO");

    printf("YES\n");
    for(int x : res) printf("%d ", x);


}