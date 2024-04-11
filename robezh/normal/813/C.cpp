#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)2e5 + 500;

int n,x,a,b;
int res = 0;
int dis[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];

void dfs1(int v){
    vis[v] = true;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            dis[nxt] = dis[v] + 1;
            dfs1(nxt);
        }
    }
}

void dfs2(int v, int cur){
    res = max(res, 2*dis[v]);
    vis[v] = true;
    for(int nxt : G[v]){
        if(dis[nxt] > cur+1 && !vis[nxt]){
            dfs2(nxt, cur+1);
        }
    }
}

int main(){
    scanf("%d%d", &n, &x);
    x--;
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fill(vis, vis+n, 0);
    dfs1(0);
    fill(vis, vis+n, 0);
    dfs2(x,0);
    cout << res << endl;
}