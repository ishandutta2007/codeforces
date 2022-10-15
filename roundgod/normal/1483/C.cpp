#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n;
int h[MAXN],b[MAXN];
int L[MAXN],R[MAXN];
int st[MAXN];
ll dp[MAXN],pre[MAXN];
struct segtree
{
    ll val[4*MAXN];
    void pushup(int k)
    {
        val[k]=max(val[k*2],val[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        val[k]=-INF;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int pos,ll v)
    {
        if(l==r) 
        {
            val[k]=v;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return val[k];
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
multiset<ll> ms;
vector<P> upd[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    int t=0;
	for(int i=1;i<=n;i++)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=n;i>=1;i--)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}
    seg.build(1,1,n+1); 
    seg.update(1,1,n+1,1,0);
    for(int i=1;i<=n;i++)
    {
        int l=L[i],r=R[i];
        ll res=seg.query(1,1,n+1,l+1,i)+b[i];
        upd[i].push_back(make_pair(res,1));
        upd[r].push_back(make_pair(res,-1));
        for(auto p:upd[i])
        {
            if(p.S==1) ms.insert(p.F);
            else ms.erase(ms.find(p.F));
        }
        res=(ms.size()?*(--ms.end()):-INF);
        seg.update(1,1,n+1,i+1,res);
    }
    printf("%lld\n",seg.query(1,1,n+1,n+1,n+1));
    return 0;
}