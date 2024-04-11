#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,a[200001];
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			ans+=max(0ll,a[i-1]-a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}