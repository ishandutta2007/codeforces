#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,d,k;
ll a[MAXN],sum[MAXN],add[MAXN];
bool C(ll x)
{
	memset(add,0,sizeof(add));
	ll t=k;
	sum[0]=0;
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll mult=0;
	for(ll i=1;i<=n;i++)
	{
		if(add[i]>0) mult-=add[i];
		ll l=max(1LL,i-d),r=min(n,i+d);
		ll res=sum[r]-sum[l-1]+mult;
		if(res<x)
		{
			if(t<x-res) return false;
			t-=x-res;
			mult+=x-res;
			if(i+2*d+1<=n) add[i+2*d+1]+=x-res;
		}
	}
	return true;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&d,&k);
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	ll l=0,r=k+n*1000000000+1;
	while(r-l>1)
	{
		ll mid=(l+r)/2;
		if(C(mid)) l=mid; else r=mid;
	}
	printf("%I64d\n",l);
	return 0;
}