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
	scanf("%I64d%I64d",&n,&k);
	for(ll i=1;i<=k;i++)
		scanf("%I64d",&a[i]);
	ll rem=n+1,t=-1;
	for(ll i=1;i<=k;i++)
	{
		if(n%a[i]<rem)
		{
			rem=n%a[i];
			t=i;
		}
	}
	printf("%I64d %I64d\n",t,n/a[t]);
	return 0;
}