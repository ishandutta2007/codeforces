#include<bits/stdc++.h>
#define MAXN 300005
#define INF 8000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int n,q,t;
int x[MAXN],w[MAXN];
int L[MAXN],R[MAXN];
int st[MAXN];
vector<P> add[MAXN];
vector<P> query[MAXN];
ll ans[MAXN];
ll bit[MAXN];
ll sum(int i)
{
    ll s=INF;
    while(i>0)
    {
        s=min(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void update(int i,ll x)
{
    while(i<=n)
    {
        bit[i]=min(bit[i],x);
        i+=i&-i;
    }
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&w[i]);
	}
	t=0;
	for(int i=1;i<=n;i++)
	{
		while(t>0&&w[st[t-1]]>w[i]) t--;
		L[i]=t==0?0:st[t-1];
		st[t++]=i;
	}
	t=0;
	for(int i=n;i>=1;i--)
	{
		while(t>0&&w[st[t-1]]>w[i]) t--;
		R[i]=t==0?n+1:st[t-1];
		st[t++]=i;
	}

	for(int i=1;i<=n;i++)
	{
		if(L[i]!=0) add[i].push_back(P(L[i],1LL*(x[i]-x[L[i]])*(w[i]+w[L[i]])));
		if(R[i]!=n+1) add[R[i]].push_back(P(i,1LL*(x[R[i]]-x[i])*(w[i]+w[R[i]])));	
	}
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		query[r].push_back(P(l,i));
	}
	for(int i=1;i<=n;i++) bit[i]=INF;
	for(int i=1;i<=n;i++)
	{
		for(auto p:add[i]) update(n-p.F+1,p.S);
		for(auto p:query[i]) ans[p.S]=sum(n-p.F+1);
	}
	for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
	return 0;
}