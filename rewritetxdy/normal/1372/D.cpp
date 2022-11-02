#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

ll n,c[N],sum[N];

int main()
{
	scanf("%lld",&n);
	for(int i=1;i <= n;i++) scanf("%lld",&c[i]);
	sum[1] = c[1];
	for(int i=2;i <= n;i++) sum[i] = sum[i-2]+c[i];
	ll ans=sum[n];
	for(int i=2;i <= n;i++) ans = max(ans,i&1 ? sum[i-1]+sum[n]-sum[i-2] : sum[i-1]+sum[n-1]-sum[i-2]);
	printf("%lld\n",ans);
	return 0;
}