#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,a[MAXN],sum[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=m;i++)
	{
		ll x;
		scanf("%I64d",&x);
		ll id=lower_bound(sum+1,sum+n+1,x)-sum;
		printf("%I64d %I64d\n",id,x-sum[id-1]);
	}
	return 0;
}