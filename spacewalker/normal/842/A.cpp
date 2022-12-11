#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
	int l, r, x, y, k; scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);
	// exp / cost = k
	// exp = k * cost
	bool yes = false;
	for (ll pcost = x; pcost <= y; ++pcost) {
		ll pexp = k * pcost;
		if (l <= pexp && pexp <= r) {
			yes = true;
			break;
		}
	}
	printf("%s\n", (yes ? "yes": "no"));
	return 0;
}