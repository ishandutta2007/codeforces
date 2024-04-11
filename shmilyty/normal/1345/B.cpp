#include<bits/stdc++.h> 
#define int long long
using namespace std;
int t,n,ans,a[100001];
signed main()
{
	for(int i=1;i<=100000;i++)
		a[i]=i*(3*i+1)/2;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=0;
		int x=upper_bound(a+1,a+100001,n)-a;
		for(int i=x;i>=1;i--)
		{
			ans+=n/a[i];
			n%=a[i];
		}
		cout<<ans<<endl;
	}	
	return 0;
}