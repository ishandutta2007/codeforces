#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ll a, b; scanf("%lld %lld", &a, &b);
	printf("YES\n");
	for (ll x = a; x <= b; x += 2) printf("%lld %lld\n", x, x + 1);
	return 0;
}