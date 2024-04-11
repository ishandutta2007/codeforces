#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 11;
int v[22][N*4],a[N],w[22][N*4];
void build(int h, int i, int l, int r)
{
    if (l==r) {if ((a[l]&(1<<h))>0) v[h][i]=1; else v[h][i]=0; return;}
    int mid=(l+r)/2;
    build(h,i+i,l,mid);
    build(h,i+i+1,mid+1,r);
    v[h][i]=v[h][i+i]+v[h][i+i+1];
}
void push(int h, int i, int l, int r)
{
    if (w[h][i]==0) return;
    w[h][i]=0;
    int mid=(l+r)/2;
    w[h][i+i]=1-w[h][i+i];
    w[h][i+i+1]=1-w[h][i+i+1];
    v[h][i+i]=mid-l+1-v[h][i+i];
    v[h][i+i+1]=r-mid-v[h][i+i+1];
}
void update(int h, int i, int l, int r, int tl, int tr)
{
    if (l>=tl&&r<=tr) {v[h][i]=r-l+1-v[h][i]; w[h][i]=1-w[h][i]; return;}
    if (l>tr||r<tl) return;
    int mid=(l+r)/2;
    push(h,i,l,r);
    update(h,i+i,l,mid,tl,tr);
    update(h,i+i+1,mid+1,r,tl,tr);
    v[h][i]=v[h][i+i]+v[h][i+i+1];
}
int get(int h, int i, int l, int r, int tl, int tr)
{
    if (l>=tl&&r<=tr) return v[h][i];
    if (l>tr||r<tl) return 0;
    int mid=(l+r)/2;
    push(h,i,l,r);
    return get(h,i+i,l,mid,tl,tr)+get(h,i+i+1,mid+1,r,tl,tr);
}
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=0; i<=20; i++){
        build(i,1,1,n);
    }
    int m;
    cin>>m;
    for (int j=1; j<=m; j++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int l,r;
            ll ans=0;
            cin>>l>>r;
            for (int i=0; i<=20; i++)
            ans+=get(i,1,1,n,l,r)*1LL*(1LL<<i);
            cout<<ans<<"\n";
        } else
        {
            int l,r,x;
            cin>>l>>r>>x;
            for (int i=0; i<=20; i++)
                if ((x&(1<<i))>0) update(i,1,1,n,l,r);
        }
    }
}