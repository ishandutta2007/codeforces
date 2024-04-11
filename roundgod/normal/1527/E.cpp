#include<bits/stdc++.h>
#define MAXN 35005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN],ndp[MAXN];
int last[MAXN],pre[MAXN];
struct segtree
{
    int mini[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void add(int k,int v)
    {
        mini[k]+=v;
        lazy[k]+=v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            mini[k]=dp[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) 
        {
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return mini[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(last,-1,sizeof(last));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        pre[i]=last[a[i]];
        last[a[i]]=i;
        dp[i]=dp[i-1];
        if(pre[i]!=-1) dp[i]+=i-pre[i];
    }
    for(int i=2;i<=k;i++)
    {
        seg.build(1,1,n);
        memset(ndp,0,sizeof(ndp));
        for(int j=1;j<=i-1;j++) ndp[j]=INF;
        for(int j=i;j<=n;j++)
        {
            if(pre[j]!=-1) seg.update(1,1,n,1,pre[j]-1,j-pre[j]);
            ndp[j]=seg.query(1,1,n,1,j-1);
        }
        swap(dp,ndp);
    }
    printf("%d\n",dp[n]);
    return 0;
}