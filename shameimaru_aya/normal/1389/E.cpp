#include<bits/stdc++.h>
using namespace std;
int T;
long long m , d , w , ans;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%lld%lld%lld" , &m , &d , &w);
		long long qwq = w / __gcd(d - 1 , w);
		long long k = min(m , d) / qwq;
		ans = k * min(m , d) - k * (k + 1) / 2ll * qwq;
		printf("%lld\n" , ans);
	}
	return 0;
}
/*
5
2 2 2
6 6 2
3 4 3
*/