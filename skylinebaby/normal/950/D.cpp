#include<bits/stdc++.h>
using namespace std;
#define int long long
int solve(int n,int q)
{
	if (q%2==1) return (q+1)/2;
	if (n%2==0) return solve(n/2,q/2)+n/2;
	if (q==2) return solve((n-1)/2,(n-1)/2)+(n+1)/2;
	return solve((n-1)/2,q/2-1)+(n+1)/2;
}
main()
{
	int n,q;
	scanf("%lld %lld",&n,&q);
	for(int i  = 0;i<q;i++)
	{
		int x;
		scanf("%lld",&x);
		printf("%lld\n",solve(n,x));
	}
	return 0;
}