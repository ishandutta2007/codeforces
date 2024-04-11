#include <cstdio>
#include <vector>
#include <algorithm>
#define NMAX 100000

using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	vector<int> occ(NMAX + 1, 0);
	for (int i = 0; i < n; ++i) {
		int ai; scanf("%d", &ai);
		++occ[ai];
	}
	vector<ll> opt(NMAX + 1, 0);
	opt[1] = occ[1];
	for (ll i = 2; i <= NMAX; ++i) {
		opt[i] = max(opt[i-1], opt[i-2] + occ[i]*i);
	}
	printf("%lld\n", opt[NMAX]);
	return 0;
}