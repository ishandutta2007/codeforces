#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],b[MAXN],sum[MAXN],red[MAXN],sz[MAXN];
int main()
{
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&b[i]);
	sum[0]=0;
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]+b[i];
	sum[n+1]=INF;
	for(ll i=1;i<=n;i++)
	{
		ll l=i-1,r=n+1;
		while(r-l>1)
		{
			ll mid=(l+r)/2;
			if(sum[mid]-sum[i-1]>=a[i]) r=mid; else l=mid;
		}
		if(r!=n+1)
		{
			ll d=sum[r]-sum[i-1]-a[i];
			red[r]-=d;
			sz[r+1]+=1;
		}
	}
	for(ll i=1;i<=n;i++)
		sz[i]+=sz[i-1];
	for(ll i=1;i<=n;i++)
		red[i]+=b[i]*(i-sz[i]);
	for(ll i=1;i<=n;i++)
		printf("%I64d ",red[i]);
	return 0;
}