#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll x, y, z; scanf("%lld %lld %lld", &x, &y, &z);
	printf("%lld ", (x + y) / z);
	ll xrem = x % z, yrem = y % z;
	if (xrem + yrem < z) printf("0\n");
	else {
		printf("%lld\n", min(z - xrem, z - yrem));
	}
	return 0;
}