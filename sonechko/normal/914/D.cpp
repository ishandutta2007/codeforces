#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 5e5 + 11;

int a[N],v[N*4];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t); else update(i*2+1,mid+1,r,x,t);
    v[i]=__gcd(v[i*2],v[i*2+1]);
}
int kol;

void ks(int i, int l, int r, int x)
{
    if (kol>1) return;
    if (l==r)
    {
        if (v[i]%x!=0) kol++;
        return;
    }
    int mid=(l+r)/2;
    if (v[i*2]%x!=0&&v[i*2+1]%x!=0) {kol=2; return;}
    if (v[i*2]%x!=0) ks(i*2,l,mid,x); else
        ks(i*2+1,mid+1,r,x);
}

void get(int i, int l, int r, int tl, int tr, int x)
{
    if (kol>1) return;
    if (tl<=l&&r<=tr)
    {
        if (v[i]%x==0) return;
        if (kol==1) {kol++; return;}
        ks(i,l,r,x);
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    get(i*2,l,mid,tl,tr,x);
    get(i*2+1,mid+1,r,tl,tr,x);
}

void build(int i, int l, int r)
{
    if (l==r) {v[i]=a[l]; return;}
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    v[i]=__gcd(v[i*2],v[i*2+1]);
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
        int k;
        cin>>k;
        if (k==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            kol=0;
            get(1,1,n,l,r,x);
            if (kol<=1) cout<<"YES\n"; else cout<<"NO\n";
        } else
        {
            int x,y;
            cin>>x>>y;
            update(1,1,n,x,y);
        }
    }
}