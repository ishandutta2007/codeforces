#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

vector <int> g[sz];
int id[sz<<1], rnk[sz<<1], big[sz<<1], vis[sz], vend[sz];

int root(int x)
{
    if(id[x]!=x) id[x]=root(id[x]);
    return id[x];
}

void join(int r)
{
    int x=root(r-1), y=root(r);
    if(rnk[x]>rnk[y]) rnk[x]+=rnk[y], id[y]=x, big[x]=max(big[x],r);
    else rnk[y]+=rnk[x], id[x]=y, big[y]=max(big[y],r);
}

void dfs(int u, int p)
{
    int r=vis[u];
    for(int v : g[u]) {
        if(v!=p) {
            vis[v]=r=big[root(r)]+1;
            join(r);
        }
    }
    vend[u]=r=big[root(r)]+1;
    join(r);

    reverse(g[u].begin(), g[u].end());
    for(int v : g[u]) {
        if(v!=p) {
            dfs(v,u);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=2*n; i++) id[i]=i, rnk[i]=1, big[i]=i;
    vis[1]=1;
    dfs(1,1);

    for(int i=1; i<=n; i++) printf("%d %d\n", vis[i], vend[i]);
}