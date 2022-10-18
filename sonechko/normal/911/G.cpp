#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int v[N*4][101],a[N];

void build(int i, int l, int r)
{
    for (int p=1; p<=100; p++)
        v[i][p]=p;
    if (l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}

void push(int i)
{
    for (int p=1; p<=100; p++)
    {
        v[i*2][p]=v[i][v[i*2][p]];
        v[i*2+1][p]=v[i][v[i*2+1][p]];
    }
    for (int p=1; p<=100; p++)
        v[i][p]=p;
}

void update(int i, int l, int r, int tl, int tr, int x, int y)
{
    if (tl<=l&&r<=tr)
    {
        for (int d=1; d<=100; d++)
            if (v[i][d]==x) v[i][d]=y;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i*2,l,mid,tl,tr,x,y);
    update(i*2+1,mid+1,r,tl,tr,x,y);
}

int get(int i, int l, int r, int x, int y)
{
    if (l==r) return v[i][y];
    int mid=(l+r)/2;
    push(i);
    if (x<=mid) return get(i*2,l,mid,x,y); else return get(i*2+1,mid+1,r,x,y);
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int m;
    cin>>m;
    build(1,1,n);
    for (int d=1; d<=m; d++)
    {
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        update(1,1,n,l,r,x,y);
    }
    for (int c=1; c<=n; c++)
    {
        cout<<get(1,1,n,c,a[c])<<" ";
    }
    cout<<endl;
}