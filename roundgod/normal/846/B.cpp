#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,m,a[MAXN];
int main()
{
	ll sum=0;
	scanf("%I64d%I64d%I64d",&n,&k,&m);
	for(ll i=1;i<=k;i++)
	{
		scanf("%I64d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+k);
	ll ans=0;
	for(ll i=0;i*sum<=m&&i<=n;i++)
	{
		ll cnt=i*(k+1),rest=m-i*sum;
		if(i==n)
		{
			ans=max(ans,cnt);
			break;
		}
		for(ll j=1;j<=k;j++)
		{
			if(rest<a[j]*(n-i))
			{
				cnt+=rest/a[j];
				ans=max(ans,cnt);
				break;
			}
			else {cnt+=(n-i); rest-=a[j]*(n-i);}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}