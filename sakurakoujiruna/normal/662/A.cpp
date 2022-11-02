#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n; scanf("%d", &n);
	ll sum = 0;
	vector <ll> base;
	for(int i = 0; i < n; i ++) {
		ll a, b; scanf("%lld%lld", &a, &b);
		sum ^= a; a ^= b;
		for(ll x : base)
			if(x & (-x) & a)
				a ^= x;
		if(a) {
			for(ll &x : base)
				if(a & (-a) & x)
					x ^= a;
			base.push_back(a);
		}
	}
	for(ll x : base)
		if(x & (-x) & sum)
			sum ^= x;
	if(sum)
		puts("1/1");
	else
		printf("%lld/%lld\n", (1LL << base.size()) - 1, (1LL << base.size()));
	return 0;
}