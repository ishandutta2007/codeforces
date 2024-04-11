#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,l,r,k;
P a[MAXN];
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&l,&r,&k,&n);
	ll t=0,res,ans;
	ll least=INF;
	for(ll i=0;i<n;i++)
	{
		ll x;
		scanf("%I64d",&x);
		least=min(least,x-1);
		if(i==0) {res=l-x+1; ans=x-1;}
		if(i==0||x!=a[t-1].F) a[t++]=P(x,1);
		else a[t-1].S++;
	}
	if(n==0||least>=l)
	{
		printf("%I64d\n",l);
		return 0;
	}
	if(res<=0)
	{
		printf("%I64d\n",ans);
		return 0;
	}
	ll now=l+a[0].S*k;
	for(ll i=1;i<t;i++)
	{
		ll nxt=a[i].F-1;
		if(now+k-1>=r) break;
		if(max(0LL,now-nxt)<res)
		{
			res=max(0LL,now-nxt);
			ans=nxt;
		}
		now=max(now,nxt+1)+a[i].S*k;
	}
	if(now+k-1<r) printf("%I64d\n",now); else printf("%I64d\n",ans);
	return 0;
}