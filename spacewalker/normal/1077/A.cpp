#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll a, b, k; scanf("%lld %lld %lld", &a, &b, &k);
		printf("%lld\n", (a-b)*(k/2) + (k%2 == 1 ? a : 0));
	}
	return 0;
}