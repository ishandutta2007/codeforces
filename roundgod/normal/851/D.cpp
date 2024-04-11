#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 2000005
#define INF 1000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,x,y,a[MAXN],sum[MAXM],cnt[MAXM];
int main()
{
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		cnt[a[i]]++;
		sum[a[i]]+=a[i];
	}
	for(ll i=2;i<MAXM;i++)
	{
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	ll ans=INF;
	for(ll i=2;i<=1000000;i++)
	{
		ll res=0;
		for(ll j=0;j<1000000;j+=i)
		{
			ll k=j+i,f=max(j,(k*y-x)/y);
			res+=(cnt[f]-cnt[j])*x+(k*(cnt[k]-cnt[f])-(sum[k]-sum[f]))*y;
		}
		ans=min(ans,res);
	}
	printf("%I64d\n",ans);
	return 0;
}