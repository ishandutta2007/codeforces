#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int NICO = 200002;
int n;
ll x[NICO];
struct edge
{
    int v, nxt;
    ll w;
} e[NICO*2];
struct Node
{
    int dep, id;
}node[NICO*2];
int head[NICO], tot;
int s[NICO], tp, par[NICO];
ll d[NICO];
int f[NICO];
bool cmp(const Node& a, const Node& b)
{
    return a.dep > b.dep;
}
void addedge(int u, int v, ll w)
{
    e[tot].w = w;
    e[tot].v = v;
    e[tot].nxt = head[u];
    head[u] = tot++;
}
void init()
{
    for(int i=1;i<=n;i++) scanf("%I64d", &x[i]);
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(f,0,sizeof(f));
    for(int i=1;i<n;i++)
    {
        int u; ll v;
        scanf("%d %I64d", &u, &v);
        addedge(i+1, u, v);
        addedge(u, i+1, v);
    }
    tp = 0;
    for(int i=1;i<=n;i++) node[i].id = i;
}
void dfs(int u, int fa, ll dis, int depth)
{
    d[u] = d[fa] + dis;
    s[tp++] = u;
    par[u] = fa;
    node[u].dep = depth;
    int l=0, r=tp-1;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(d[u] - d[s[mid]] > x[u]) l = mid+1;
        else r=mid;
    }
    f[s[tp-2]] += 1;
    if(r) f[s[r-1]] -= 1;
    for(int i=head[u]; i!=-1 ;i=e[i].nxt)
    {
        edge& ed = e[i];
        int v = ed.v;
        ll w = ed.w;
        if(fa == v) continue;
        dfs(v,u,w,depth+1);
    }
    tp--;
}
void solve()
{
    sort(node+1,node+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int& fa = par[node[i].id];
        f[fa] += f[node[i].id];
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d%c", f[i], i==n?'\n':' ');
    }
}
int main()
{
    scanf("%d", &n);
    init();
    dfs(1,0,0,0);
    solve();
}