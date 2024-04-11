#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
	int n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	int t = __gcd(n,k);
	int x = __gcd(n*m,k);
	int y = k/x;
	int z = n*m/x;
	if(y>2) printf("NO\n");
	else if (y==2) printf("YES\n0 0\n%lld 0\n0 %lld",n/t,t*z/n);
	else if(2*n/t<=n) printf("YES\n0 0\n%lld 0\n0 %lld",2*n/t,t*z/n);
	else printf("YES\n0 0\n%lld 0\n0 %lld",n/t,2*t*z/n);
	return 0;
}