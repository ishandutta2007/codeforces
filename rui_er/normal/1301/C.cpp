#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &n, &m);
		ll tot,p,r;
		tot=n*(n+1)/2;
		p=(n-m)/(m+1);
		r=(n-m)% (m+1);
		printf("%lld\n", tot-p*(m+1)*(p+1)/2-(p+1)*r);
	}
	return 0;
}