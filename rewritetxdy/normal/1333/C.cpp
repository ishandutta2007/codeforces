#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+10;

ll n,c[N],sum[N],x=1,ans;
map<ll,ll>vis;

int main()
{
	scanf("%lld",&n);
	for(int i=1;i <= n;i++) scanf("%lld",&c[i]);
	for(int i=1;i <= n;i++) sum[i] = sum[i-1]+c[i];
	vis[0] = 1;
	for(int i=1;i <= n;i++){
		while(x <= n && !vis[sum[x]]) vis[sum[x]] = 1 , x++;
		ans += x-i;
		vis[sum[i-1]]--;
	}
	printf("%lld\n",ans);
}