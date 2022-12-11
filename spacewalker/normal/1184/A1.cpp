#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll r; scanf("%lld", &r);
	if (r % 2 == 0 || r < 5) printf("NO\n");
	else printf("1 %lld\n", ((r - 3) / 2));
	return 0;
}