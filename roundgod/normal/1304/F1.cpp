#include<bits/stdc++.h>
#define MAXN 55
#define MAXM 20005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int a[MAXN][MAXM],sum[MAXN][MAXM];
int dp[MAXN][MAXM];
struct segtree
{
    int maxi[4*MAXM],lazy[4*MAXM];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++)
        {
            maxi[i]+=lazy[k];
            lazy[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0; maxi[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            lazy[k]+=v;
            maxi[k]+=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 0;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int get_sum(int i,int j)
{
    int ret=sum[i][j+k-1]-sum[i][j-1];
    if(i!=n) ret+=sum[i+1][j+k-1]-sum[i+1][j-1];
    return ret;
}
P get_interval(int x)
{
    int r=min(m-k+1,x);
    int l=max(1,x-k+1);
    return P(l,r);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
        for(int j=1;j<=m;j++) sum[i][j]=sum[i][j-1]+a[i][j];
    }
    for(int i=1;i<=m-k+1;i++) dp[1][i]=get_sum(1,i);
    for(int i=2;i<=n;i++)
    {
        seg.build(1,1,m-k+1);
        for(int j=1;j<=m-k+1;j++) seg.update(1,1,m-k+1,j,j,dp[i-1][j]);
        for(int j=1;j<=m-k+1;j++)
        {
            int l=max(j,1),r=min(j+k-1,k);
            if(l<=r) 
            {
                seg.update(1,1,m-k+1,j,j,-(sum[i][r]-sum[i][l-1]));
            }
        }
        for(int j=1;j<=m-k+1;j++)
        {
            dp[i][j]=seg.query(1,1,m-k+1,1,m-k+1)+get_sum(i,j);
            P p=get_interval(j);
            seg.update(1,1,m-k+1,p.F,p.S,a[i][j]);
            if(j!=m-k+1)
            {
                p=get_interval(j+k);
                seg.update(1,1,m-k+1,p.F,p.S,-a[i][j+k]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m-k+1;i++) ans=max(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}