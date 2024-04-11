#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,maxx,a;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=maxx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a);
			if(a*maxx<=0)
			{
				ans+=maxx;
				maxx=a;	
			} 
			maxx=max(maxx,a);
		}
		cout<<ans+maxx<<endl;
	}
	return 0;
}