#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
ll n,k;
ll a[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	ll s=a[0]/k,m=a[0]%k,res=s;
	for(ll i=1;i<n;i++)
	{
		if(a[i]%k!=m)
		{
			printf("-1\n");
			return 0;
		}
		res=min(res,a[i]/k);
		s+=a[i]/k;
	}
	printf("%I64d\n",s-res*n);
	return 0;
}