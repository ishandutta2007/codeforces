#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[501];
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n<=3)
	{
		for(int i=1;i<=n;i++)
			ans|=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			for(int j=l+1;j<=n;j++)
				ans=max(ans,(a[i]|a[l]|a[j]));
	cout<<ans;
	return 0;
}