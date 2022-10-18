#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 11;

ll a[N],v[N*4],w[N*4];

void build(int i, int l, int r)
{
    if (l==r) {v[i]=a[l]; return;}
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    v[i]=max(v[i*2],v[i*2+1]);
}
void push(int i)
{
    if (w[i]==0) return;
    w[i*2]=w[i];
    w[i*2+1]=w[i];
    v[i*2]=w[i];
    v[i*2+1]=w[i];
    w[i]=0;
}
ll maxi(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    push(i);
    return max(maxi(i*2,l,mid,tl,tr),maxi(i*2+1,mid+1,r,tl,tr));
}
void update(int i, int l, int r, int tl, int tr, ll t)
{
    if (tl<=l&&r<=tr) {v[i]=t; w[i]=t; return;}
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i*2,l,mid,tl,tr,t);
    update(i*2+1,mid+1,r,tl,tr,t);
    v[i]=max(v[i*2],v[i*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    build(1,1,n);
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        ll l,r;
        cin>>l>>r;
        ll d=maxi(1,1,n,1,l);
        cout<<d<<"\n";
        update(1,1,n,1,l,d+r);
    }
}