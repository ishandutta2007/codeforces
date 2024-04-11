#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

typedef pair <int,int> pii;
#define x first
#define y second

pii a[sz];

bool cmp(pii one, pii two)
{
    return (one.y-one.x) < (two.y-two.x);
}

vector <int> g[sz];

int inv[sz<<1], id[sz<<1], rnk[sz<<1], big[sz<<1];

int root(int x)
{
    if(id[x]!=x) id[x]=root(id[x]);
    return id[x];
}

void join(int r)
{
    int x=root(r-1), y=root(r), z=max(big[x],big[y]);
    if(rnk[x]>rnk[y]) rnk[x]+=rnk[y], id[y]=x, big[x]=z;
    else rnk[y]+=rnk[x], id[x]=y, big[y]=z;
}

int par[sz];
bool yes=1;

void dfs(int u, int p)
{
    if(par[u]) {
        if(par[u]!=p) yes=0;
        return;
    }
    par[u]=p;
    for(int v : g[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d %d", &a[i].x, &a[i].y);
    sort(a,a+n,cmp);
    for(int i=1; i<=2*n; i++) id[i]=i, big[i]=i, rnk[i]=1;
    for(int i=0; i<n; i++) inv[a[i].x]=i+1, inv[a[i].y]=i+1;

    vector <int> cnt;
    int m=0;
    for(int i=0; i<n && m<n; i++) {
        int x=a[i].x, y=a[i].y;

        int r=big[root(x)]+1;
        while(r<y && ++m<n) {
            g[i+1].push_back(inv[r]);
            g[inv[r]].push_back(i+1);
            r=big[root(r)]+1;
        }

        join(x);
        join(y);
    }

    if(m<n) dfs(1,1);
    else yes=0;
    for(int i=1; i<=n; i++) if(!par[i]) yes=0;

    if(yes) puts("YES");
    else puts("NO");
}