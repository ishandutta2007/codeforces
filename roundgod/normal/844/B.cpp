#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN][MAXN];
ll pow2(ll x)
{
	ll s=1;
	for(ll i=0;i<x;i++)
		s*=2;
	return s-1;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			scanf("%I64d",&a[i][j]);
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		ll cnt=0;
		for(ll j=0;j<m;j++)
			if(a[i][j]==0) cnt++;
		ans+=pow2(cnt)+pow2(m-cnt);
	}
	for(ll i=0;i<m;i++)
	{
		ll cnt=0;
		for(ll j=0;j<n;j++)
			if(a[j][i]==0) cnt++;
		ans+=pow2(cnt)+pow2(n-cnt);
	}
	printf("%I64d\n",ans-n*m);
	return 0;
}