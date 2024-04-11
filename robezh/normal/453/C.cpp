#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,m;
vector<int> G[N];
int num[N];
bool vis[N];
vector<int> res;

int dfs(int v){
    vis[v] = true;
    int res = (num[v] == 1 ? v : -1);
    for(int nxt : G[v]){
        if(!vis[nxt]) res = max(res, dfs(nxt));
    }
    return res;
}

void go_to(int v){
    num[v] = !num[v];
    res.push_back(v);
}

void dfs(int v, int par){
    vis[v] = true;
    go_to(v);

    bool left = false;
    bool first = true;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            if(first) first = false;
            else go_to(v);

            left = true;
            dfs(nxt, v);
        }
    }
    if(left && !(par == -1 && num[v] == 0)) go_to(v);
    if(num[v] == 1){
        go_to(par);
        go_to(v);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    fill(vis, vis+n, 0);
    int p = -1;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            int cur = dfs(i);
            if(cur != -1){
                if(p != -1) return !printf("-1");
                else p = cur;
            }
        }
    }
    if(p == -1){
        return !printf("0");
    }
    fill(vis, vis+n, 0);
    dfs(p, -1);
    printf("%d\n", res.size());
    for(int x : res) printf("%d ", x + 1);
}