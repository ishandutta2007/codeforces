#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a[5000100];
signed main()
{
	for(int i=2;i<=500000;i++)
		a[i]=a[i-2]+(int)4*(i-1)*(i>>1);
	scanf("%lld",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
	}
	return 0;
}