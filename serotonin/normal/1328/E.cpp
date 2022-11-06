#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int a[sz], done[sz], prnt[sz], spar[sz][20];
vector <int> g[sz];

void dfs(int u, int p, int lvl)
{
    done[u]=lvl;
    prnt[u]=p;
    for(int i=0; i<g[u].size(); i++) {
        int v=g[u][i];
        if(!done[v]) dfs(v,u,lvl+1);
    }
}

void table(int n)
{
    memset(spar, -1, sizeof(spar));

    dfs(1,-1,1);

    for(int i=1; i<=n; i++) spar[i][0]=prnt[i];

    for(int j=1; 1<<j < n; j++) {
        for(int i=1; i<=n; i++) {
            if(spar[i][j-1]!=-1) {
                spar[i][j]=spar[spar[i][j-1]][j-1];
            }
        }
    }
}

int lca(int x, int y)
{
    if(done[x]<done[y]) swap(x,y);

    int big;
    for(int j=0; 1<<j <= done[x]; j++) big=j;

    for(int j=big; j>=0; j--) {
        if(done[x]-(1<<j) >= done[y]) {
            x=spar[x][j];
        }
    }

    if(x==y) return x;

    for(int j=big; j>=0; j--) {
        if(spar[x][j]!=spar[y][j]) {
            x=spar[x][j], y=spar[y][j];
        }
    }
    return prnt[x];
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    table(n);

    while(m--) {
        int k, mx=0, who;
        scanf("%d", &k);
        for(int i=0; i<k; i++) {
            scanf("%d", &a[i]);
            int x = done[a[i]];
            if(x > mx) mx = x, who = a[i];
        }
        bool ok=1;
        for(int i=0; i<k; i++) {
            int up = lca(who, a[i]);
            if(abs(done[up]-done[a[i]])>1) ok=0;
        }
        if(ok) puts("YES");
        else puts("NO");
    }
}