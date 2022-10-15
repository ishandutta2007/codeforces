#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	for(ll i=0;i<n-1;i++)
		a[i]=max(a[i+1]-a[i],a[i]-a[i+1]);
	ll ans=0;
	for(ll i=1;i<n-1;i+=2)
		a[i]=-a[i];
	ll now=0;
	for(ll i=0;i<n-1;i++)
	{
		now+=a[i];
		if(now<0) now=0;
		ans=max(ans,now);
	}
	for(ll i=0;i<n-1;i++)
		a[i]=-a[i];
	now=0;
	for(ll i=0;i<n-1;i++)
	{
		now+=a[i];
		if(now<0) now=0;
		ans=max(ans,now);
	}
	printf("%I64d\n",ans);
	return 0;
}