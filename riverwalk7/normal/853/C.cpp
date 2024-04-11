#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <cstdio>
#define MAXN 200200
using namespace std;
typedef long long ll;
struct rectangle
{
    ll l, d, r, u, id;
    rectangle()
    {
        l = d = r = u = id = 0;
    }
    bool operator <(const rectangle &rhs) const
    {
        return l < rhs.l;
    }
};
bool comp(rectangle a, rectangle b)
{
    return a.r > b.r;
}
ll N; int Q;
ll total;
ll complimentary[MAXN];
rectangle x[MAXN];
int p[MAXN];
ll s;
ll tree[525000];
void update(int node, int l, int r, int q)
{
    if(l==r&&r==q)
    {
        tree[node]++;
        return;
    }
    else if(l>q||r<q)
    {
        return;
    }
    else
    {
        update(2*node, l, (l+r)/2, q);
        update(2*node+1, (l+r)/2+1, r, q);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
ll query(int node, int l, int r, int ql, int qr)
{
    if(ql<=l&&r<=qr)
    {
        return tree[node];
    }
    else if(l>qr||r<ql)
    {
        return 0;
    }
    else
    {
        return query(2*node, l, (l+r)/2, ql, qr) + query(2*node+1, (l+r)/2+1, r, ql, qr);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin>>N>>Q;
    total = N*(N-1)/2;
    for(int i=1; i<=N; i++)
    {
        cin>>p[i];
    }
    for(int i=0; i<Q; i++)
    {
        cin>>x[i].l>>x[i].d>>x[i].r>>x[i].u;
        x[i].id = i;
        complimentary[i] += ((x[i].l-1)*(x[i].l-2)/2);
        complimentary[i] += ((N-x[i].r)*(N-x[i].r-1)/2);
        complimentary[i] += ((x[i].d-1)*(x[i].d-2)/2);
        complimentary[i] += ((N-x[i].u)*(N-x[i].u-1)/2);
    }
    sort(x, x+Q);
    for(int i=0; i<Q; i++)
    {
        if(i!=0)
        {
            for(int j=x[i-1].l; j<x[i].l; j++)
            {
                update(1, 1, N, p[j]);
            }
        }
        else
        {
            for(int j=1; j<x[i].l; j++)
            {
                update(1, 1, N, p[j]);
            }
        }
        s = query(1, 1, N, 1, x[i].d-1);
        complimentary[x[i].id] -= ((s*(s-1))/2);
        s = query(1, 1, N, x[i].u+1, N);
        complimentary[x[i].id] -= ((s*(s-1))/2);

    }
    for(int i=0; i<525000; i++)
    {
        tree[i] = 0;
    }
    sort(x, x+Q, comp);
    for(int i=0; i<Q; i++)
    {
        if(i!=0)
        {
            for(int j=x[i-1].r; j>x[i].r; j--)
            {
                update(1, 1, N, p[j]);
            }
        }
        else
        {
            for(int j=N; j>x[i].r; j--)
            {
                update(1, 1, N, p[j]);
            }
        }
        s = query(1, 1, N, 1, x[i].d-1);
        complimentary[x[i].id] -= ((s*(s-1))/2);
        s = query(1, 1, N, x[i].u+1, N);
        complimentary[x[i].id] -= ((s*(s-1))/2);
    }
    for(int i=0; i<Q; i++)
    {
        cout<<total-complimentary[i]<<'\n';
    }
}