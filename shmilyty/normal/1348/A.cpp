#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=0;
		ans+=(1<<n);
		for(int i=1;i<n/2;i++)
			ans+=(1<<i);
		cout<<abs(((1<<(n+1))-2-ans)-ans)<<endl;
	}
	return 0;
}