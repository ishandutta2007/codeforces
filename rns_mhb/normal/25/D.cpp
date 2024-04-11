#include<bits/stdc++.h>
using namespace std;

#define fr first
#define se second
#define pb push_back

#define inf 1e9
#define INF 1e18

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

#define N 1010

bool vis[N], c[N];
int b[N];
vi adj[N], id[N];
pii e[N];

void dfs(int u) {
    int i, v;
    vis[u] = 1;
    for(i = 0; i < adj[u].size(); i ++) {
        v = adj[u][i];
        if(vis[v]) continue;
        c[id[u][i]] = 1;
        dfs(v);
    }
}

int main() {
    int n, i, u, v, m = 0;
    scanf("%d", &n);
    for(i = 1; i < n; i ++) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
        id[u].pb(i);
        id[v].pb(i);
        e[i] = pii(u, v);
    }
    for(i = 1; i <= n; i ++) if(vis[i] == 0) {
        b[m ++] = i;
        dfs(i);
    }
    printf("%d\n", m - 1);
    for(i = 1, m = 0; i < n; i ++) if(c[i] == 0) printf("%d %d %d %d\n", e[i].fr, e[i].se, b[m], b[m ++]);
}