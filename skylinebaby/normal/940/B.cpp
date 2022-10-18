#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n,k,a,b;
	scanf("%lld %lld %lld %lld",&n,&k,&a,&b);
	int ans = 0;
	while(n>1)
	{
		if (k==1)
		{
			ans = (n-1)*a;
			break;
		}
		if (n<k)
		{
			ans += (n-1)*a;
			break;
		}
		int x = n/ k;
		if (n!=k*x)
		{
			ans += (n-k*x)*a;
			n = k*x;
		}
		if ((n-x)*a<=b)
		{
			ans += (n-1)*a;
			break;
		}
		else 
		{
			n = x;
			ans += b;
		}
	}
	printf("%lld\n",ans);
	return 0;
}