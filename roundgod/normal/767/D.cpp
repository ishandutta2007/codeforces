#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m,k;
ll f[MAXN];
P s[MAXN];
ll cnt[MAXN];
bool cmp(P x,P y)
{
	return x.F>y.F;
}
bool C(ll x)
{
	memset(cnt,0,sizeof(cnt));
	for(ll i=0;i<n;i++)
		if(f[i]<=1000000) cnt[f[i]]++;
	for(ll i=0;i<x;i++)
		if(s[i].F<=1000000) cnt[s[i].F]++;
	for(ll i=1;i<=1000000;i++)
		cnt[i]+=cnt[i-1];
	for(ll i=0;(i+1)*k<=1000000;i++)
		if(cnt[i]>(i+1)*k) return false;
	return true;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&f[i]);
	for(ll i=0;i<m;i++)
	{
		scanf("%I64d",&s[i].F);
		s[i].S=i+1;
	}
	sort(f,f+n);
	sort(s,s+m,cmp);
	ll l=-1,r=m+1;
	while(r-l>1)
	{
		ll mid=(l+r)/2;
		if(C(mid)) l=mid; else r=mid;
	}
	if(l==-1) puts("-1");
	else
	{
		printf("%I64d\n",l);
		for(ll i=0;i<l;i++)
			printf("%I64d ",s[i].S);
		puts("");
	}
	return 0;
}