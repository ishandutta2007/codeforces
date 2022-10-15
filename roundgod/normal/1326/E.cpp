#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p[MAXN],q[MAXN],a[MAXN],pos[MAXN];
vector<P> v;
struct segtree
{
    int maxi[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(int k)
    {
        for(int i=k*2;i<=k*2+1;i++)
        {
            lazy[i]+=lazy[k];
            maxi[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0; maxi[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k); 
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
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
        v.push_back(P(p[i],i));
    }
    sort(v.begin(),v.end(),greater<P>());
    for(int i=1;i<=n;i++) scanf("%d",&q[i]);
    seg.build(1,1,n);
    int now=1;
    for(int i=n;i>=1;i--)
    {
        seg.update(1,1,n,1,pos[i],1);
        while(now<=n&&seg.query(1,1,n,1,n)>0)
        {
            ans[now-1]=i;
            seg.update(1,1,n,1,q[now],-1);
            now++;
        }
    }
    for(int i=n-1;i>=0;i--) ans[i]=max(ans[i],ans[i+1]);
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}