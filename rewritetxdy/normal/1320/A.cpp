#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll N = 8e5+10;
 
ll n,c[N],val[N],cnt[N];

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i <= n;i++)
		scanf("%lld",&c[i]) , c[i] -= i;
	for(ll i=1;i <= n;i++)
		cnt[c[i]+400000]++ , val[c[i]+400000] += i;
	ll ans = 0;
	for(ll i=0;i <= 800000;i++)
		ans = max(ans,cnt[i]*(i-400000)+val[i]);
	printf("%lld\n",ans);
	return 0;
}