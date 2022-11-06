//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, p1, p2, k;

ll Gcd(ll x, ll y) {return y == 0 ? x : Gcd(y, x%y);}

int main()
{
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld%lld%lld", &p1, &p2, &k);
		if(k == 1) 
		{
			printf("REBEL\n");
			continue;
		}
		ll g = Gcd(p1, p2);
		if(g != 1) p1 /= g, p2 /= g;
		if(p1 < p2) swap(p1, p2);
		ll t = (p1 - 2) / p2 + 1;
		if(t < k) printf("OBEY\n");
		else printf("REBEL\n");
	}
	return 0;
}