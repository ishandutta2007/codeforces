#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int done[sz], prnt[sz], spar[sz][20];
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
    memset(done, 0, sizeof done);
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

int dist(int x, int y)
{
    int l=lca(x,y);
    return abs(done[l]-done[x])+abs(done[l]-done[y]);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    table(n);

    int q;
    cin >> q;
    while(q--) {
        int x,y,a,b,k;
        scanf("%d %d %d %d %d", &x, &y, &a, &b, &k);

        bool yes=0;

        int ease=dist(a,b);
        if(ease<=k && (k-ease)%2==0) yes=1;
        else {
            int hardx=dist(a,y)+1+dist(x,b);
            int hardy=dist(a,x)+1+dist(y,b);
            if(hardx<=k && (k-hardx)%2==0) yes=1;
            if(hardy<=k && (k-hardy)%2==0) yes=1;
        }

        if(yes) puts("YES");
        else puts("NO");
    }
}