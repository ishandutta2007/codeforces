#include <iostream>
#include <fstream>
#define MAXN 200200
#define lc 2*node
#define rc 2*node+1
#define mid (l+r)/2
using namespace std;
typedef long long ll;
ll tree[3*MAXN], lazy[3*MAXN];
ll w[MAXN]; ll prefix[MAXN]; ll p[MAXN], invp[MAXN]; ll ans;
int N;
void buildtree(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = prefix[l];
    }
    else
    {
        buildtree(lc, l, mid); buildtree(rc, mid+1, r);
        tree[node] = min(tree[lc], tree[rc]);
    }
}
void propagate(int node)
{
    lazy[lc] += lazy[node]; lazy[rc] += lazy[node];
    tree[lc] += lazy[node]; tree[rc] += lazy[node];
    lazy[node] = 0;
}
void update(int node, int l, int r, int ql, int qr, ll q)
{
    if(l != r)
    {
        propagate(node);
    }
    if(l > qr || r < ql)
    {
        return;
    }
    else if(ql <= l && r <= qr)
    {
        tree[node] += q;
        lazy[node] += q;
        return;
    }
    else
    {
        update(lc, l, mid, ql, qr, q); update(rc, mid+1, r, ql, qr, q);
        tree[node] = min(tree[lc], tree[rc]);
    }
}
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>p[i];
        invp[p[i]] = i;
    }
    for(int i=1; i<=N; i++)
    {
        cin>>w[i];
    }
    for(int i=1; i<=N; i++)
    {
        prefix[i] = prefix[i-1]+w[invp[i]];
    }
    ans = w[1];
    buildtree(1, 0, N);
    for(int i=1; i<N; i++)
    {
        update(1, 0, N, 0, p[i]-1, w[i]);
        update(1, 0, N, p[i], N, -w[i]);
        ans = min(ans, tree[1]);
    }
    cout<<ans<<endl;
}