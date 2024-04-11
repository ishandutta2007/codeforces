#include <iostream>
#include <fstream>
#include <algorithm>
#define lc 2*node
#define rc 2*node+1
#define mid (l+r)/2
#define MAXN 100100
using namespace std;
struct cow
{
    int index, val, nval;
    cow()
    {
        index = val = nval = 0;
    }
    bool operator <(const cow &rhs) const
    {
        return val < rhs.val;
    }
};
bool comp(cow a, cow b)
{
    return a.index < b.index;
}
bool comp2(cow a, cow b)
{
    return a.index > b.index;
}
int DP[MAXN];
int NP[MAXN];
int N, M;
int ql, qr;
int tree[4*MAXN];
cow a[MAXN];
void update(int node, int l, int r)
{
    if(l > qr || r < ql)
    {
        return;
    }
    else if(ql <= l && r<= qr)
    {
        tree[node]++;
        return;
    }
    else
    {
        update(lc, l, mid);
        update(rc, mid+1, r);
    }
}
int query(int node, int l, int r, int q)
{
    if(l > q || r < q)
    {
        return 0;
    }
    else if(l==q&&r==q)
    {
        return tree[node];
    }
    else
    {
        return tree[node] + query(lc, l, mid, q) + query(rc, mid+1, r, q);
    }
}
int query2(int node, int l, int r, int q)
{
    if(r <= q)
    {
        return tree[node];
    }
    else if(l>q)
    {
        return 0;
    }
    else
    {
        return max(query2(2*node, l, (l+r)/2, q), query2(2*node+1, (l+r)/2+1, r, q));
    }
}
void update2(int node, int l, int r, int q, int qq)
{
    if(l==q && r==q)
    {
        tree[node] = qq;
        return;
    }
    else if(l > q || r < q)
    {
        return;
    }
    else
    {
        update2(2*node, l, (l+r)/2, q, qq);
        update2(2*node+1, (l+r)/2+1, r, q, qq);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>ql>>qr;
        update(1, 1, M);
    }
    for(int i=1; i<=M; i++)
    {
        a[i-1].val = query(1, 1, M, i);
        a[i-1].index = i;
    }
    for(int i=0; i<4*MAXN; i++)
    {
        tree[i] = 0;
    }
    sort(a, a+M);
    a[0].nval = 1;
    for(int i=1; i<M; i++)
    {
        if(a[i].val == a[i-1].val)
        {
            a[i].nval = a[i-1].nval;
        }
        else
        {
            a[i].nval = a[i-1].nval + 1;
        }
    }
    sort(a, a+M, comp);
    for(int i=0; i<M; i++)
    {
        DP[i] = query2(1, 1, M, a[i].nval)+1;
        update2(1, 1, M, a[i].nval, query2(1, 1, M, a[i].nval)+1);
    }
    for(int i=0; i<4*MAXN; i++)
    {
        tree[i] = 0;
    }
    sort(a, a+M, comp2);
    for(int i=0; i<M; i++)
    {
        NP[M-i-1] = query2(1, 1, M, a[i].nval)+1;
        update2(1, 1, M, a[i].nval, query2(1, 1, M, a[i].nval)+1);
    }
    int ans = 0;
    for(int i=0; i<M; i++)
    {
        ans = max(ans, DP[i] + NP[i] - 1);
    }
    cout<<ans<<endl;
}