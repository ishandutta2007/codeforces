#include<bits/stdc++.h>
#define MAXN 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,a[MAXN],f[MAXN],g[MAXN],cnt[MAXN];
ll pow_mod(ll a,ll i)
{
	ll s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i=i>>1;
	}
	return s;
}
ll bit(ll x)
{
	if(x==0) return 0;
	return bit(x>>1)+(x&1);
}
int main()
{
	scanf("%I64d",&n);
	memset(a,0,sizeof(a));
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		cnt[a[i]]++;
	}
	for(ll i=0;i<=(1<<20);i++)
		f[i]=cnt[i];
	for(ll i=0;i<20;i++) 
	{
		for(ll mask=0;mask<=(1<<20);mask++)
			if(mask&(1<<i))
				f[mask^(1<<i)]+=f[mask];
	}
	//for(ll mask=0;mask<1<<20;mask++) printf("%I64d %I64d\n",mask,f[mask]);
	ll ans=0;
	for(ll mask=0;mask<=(1<<20);mask++)
	{
		ll flag=(bit(mask)&1)?-1:1;
		ans=(ans+flag*(pow_mod(2,f[mask])-1)+MOD)%MOD;
		//printf("%I64d\n",ans);
	}
	printf("%I64d\n",ans);
	return 0;
}