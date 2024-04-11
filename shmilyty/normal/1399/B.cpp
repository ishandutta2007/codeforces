#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,mina,minb,ans,a[51],b[51];
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		mina=minb=1e9;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			mina=min(mina,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
			minb=min(minb,b[i]);
		}
		for(int i=1;i<=n;i++)
			ans+=max(a[i]-mina,b[i]-minb);
		cout<<ans<<endl;
	}
	return 0;
}