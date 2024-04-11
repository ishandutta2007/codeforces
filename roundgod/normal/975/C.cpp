#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,q,a[MAXN],k[MAXN],sum[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&q);
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(ll i=1;i<=q;i++)
		scanf("%I64d",&k[i]);
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll s=0;
	for(ll i=1;i<=q;i++)
	{
		s=s+k[i];
		if(s>=sum[n])
		{
			s=0;
			printf("%I64d\n",n);
			continue;
		}
		printf("%I64d\n",n-(upper_bound(sum+1,sum+n+1,s)-sum-1));
	}
	return 0;
}