#include <iostream>
#include <iomanip>
#define MAXN 263000
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
using namespace std;
int N, Q;
double tree[MAXN];
double lazy1[MAXN], lazy2[MAXN];
double a[MAXN];
int t, l1, r1, l2, r2;
double c, d;
void buildtree(int node, int l, int r)
{
    lazy1[node] = 1;
    if(l==r)
    {
        tree[node] = a[l];
        return;
    }
    else
    {
        buildtree(lc, l, mid);
        buildtree(rc, mid+1, r);
        tree[node] = tree[lc] + tree[rc];
    }
}
void propagate(int node, int l, int r)
{
    tree[lc] = tree[lc]*lazy1[node]+lazy2[node]*(mid-l+1);
    tree[rc] = tree[rc]*lazy1[node]+lazy2[node]*(r-mid);
    lazy1[lc] *= lazy1[node];
    lazy2[lc] = lazy2[lc]*lazy1[node]+lazy2[node];
    lazy1[rc] *= lazy1[node];
    lazy2[rc] = lazy2[rc]*lazy1[node]+lazy2[node];
    lazy1[node] = 1;
    lazy2[node] = 0;
}
double query(int node, int l, int r, int ql, int qr)
{
    if(l!=r)
    {
        propagate(node, l, r);
    }
    if(ql<=l && r<=qr)
    {
        return tree[node];
    }
    else if(l>qr||r<ql)
    {
        return 0;
    }
    else
    {
        return query(lc, l, mid, ql, qr) + query(rc, mid+1, r, ql, qr);
    }
}
void update1(int node, int l, int r, int ql, int qr, double q)
{
    if(l>qr||r<ql)
    {
        return;
    }
    if(l!=r)
    {
        propagate(node, l, r);
    }
    if(ql<=l && r<=qr)
    {
        tree[node] *= ((q-1)/q);
        lazy1[node] *= ((q-1)/q);
        lazy2[node] *= ((q-1)/q);
        return;
    }
    update1(lc, l, mid, ql, qr, q);
    update1(rc, mid+1, r, ql, qr, q);
    tree[node] = tree[lc] + tree[rc];
}
void update2(int node, int l, int r, int ql, int qr, double q)
{
    if(l>qr||r<ql)
    {
        return;
    }
    if(l!=r)
    {
        propagate(node, l, r);
    }
    if(ql<=l && r<=qr)
    {
        tree[node] += (q*(r-l+1));
        lazy2[node] += q;
        return;
    }
    update2(lc, l, mid, ql, qr, q);
    update2(rc, mid+1, r, ql, qr, q);
    tree[node] = tree[lc] + tree[rc];
}
int main()
{
    cin>>N>>Q;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
    }
    buildtree(1, 1, N);
    for(int i=0; i<Q; i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>l1>>r1>>l2>>r2;
            c = query(1, 1, N, l1, r1)/(r1-l1+1)/(r2-l2+1);
            d = query(1, 1, N, l2, r2)/(r1-l1+1)/(r2-l2+1);
            update1(1, 1, N, l1, r1, (r1-l1+1));
            update2(1, 1, N, l1, r1, d);
            update1(1, 1, N, l2, r2, (r2-l2+1));
            update2(1, 1,N, l2, r2, c);
        }
        if(t==2)
        {
            cin>>l1>>r1;
            c = query(1, 1, N, l1, r1);
            cout <<setprecision(7)<<c<< '\n';
        }
    }
}