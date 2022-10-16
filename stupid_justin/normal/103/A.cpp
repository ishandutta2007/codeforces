#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
	    ans+=(a-1)*i;
	}
	ans+=n;
	cout<<ans<<endl;
	
}