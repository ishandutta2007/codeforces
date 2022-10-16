#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,gcd,ans,a[100001],f[100001];
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==1)
			gcd=a[i];
		else
			gcd=__gcd(gcd,a[i]);
	}
	f[1]=a[1];
	for(int i=2;i<n;i++)
	{
		ans=__gcd(ans,a[i]*f[i-1]); 
		f[i]=__gcd(f[i-1],a[i]);
	}
	ans=__gcd(ans,a[n]*f[n-1]);
	cout<<ans/gcd;
	return 0;
}