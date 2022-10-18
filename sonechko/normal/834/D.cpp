#include<bits/stdc++.h>
using namespace std;

const int N = 35000 + 11;

int a[N],kol[N];
int dp[N][52];
int v[N*4],w[N*4];

void build(int i, int l, int r, int p)
{
    if (l==r) {v[i]=dp[l-1][p]; w[i]=0; return;}
    int mid=(l+r)/2;
    build(i+i,l,mid,p);
    build(i+i+1,mid+1,r,p);
    v[i]=max(v[i+i],v[i+i+1]);
    w[i]=0;
}

void push(int i)
{
    w[i+i]+=w[i];
    w[i+i+1]+=w[i];
    v[i+i]+=w[i];
    v[i+i+1]+=w[i];
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, int t)
{
    if (tl<=l&&r<=tr)
    {
        v[i]+=t;
        w[i]+=t;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr,t);
    update(i+i+1,mid+1,r,tl,tr,t);
    v[i]=max(v[i+i],v[i+i+1]);
}

int maxi(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return max(maxi(i+i,l,mid,tl,tr),maxi(i+i+1,mid+1,r,tl,tr));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int r=0;
    for (int i=1; i<=n; i++)
    {
        if (kol[a[i]]==0) r++;
        kol[a[i]]=1;
        ///cout<<i<<" "<<1<<" = "<<r<<endl;
        dp[i][1]=r;
    }
    for (int p=2; p<=k; p++)
    {
        for (int i=1; i<=n; i++)
            kol[i]=0;
        build(1,1,n,p-1);
        for (int i=1; i<=n; i++)
        {
            update(1,1,n,1,kol[a[i]],-1);
            kol[a[i]]=i;
            update(1,1,n,1,kol[a[i]],1);
            dp[i][p]=maxi(1,1,n,1,i);
            ///cout<<i<<" "<<p<<" = "<<dp[i][p]<<endl;
        }
    }
    cout<<dp[n][k]<<endl;
}