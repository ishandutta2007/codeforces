#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int n, d, m, acc = 0;
	scanf("%d %d %d", &n, &d, &m);
	long long a[n + 1], ans = 0, temp;
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	multiset<long long> small, large;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > m) large.insert(a[i]);
		else small.insert(a[i]);
	}
	if (!large.empty()) {
		ans += *--large.end();
		large.erase(--large.end());
	}
	for (long long i: small) ans += i;
	acc = 0, temp = ans;
	while (!large.empty()) {
		temp += *--large.end();
		large.erase(--large.end());
		acc += d;
		if (large.size() + small.size() < acc) break;
		int k = acc;
		for (int i = 0; i < (acc > large.size() ? acc - large.size() : 0); ++i) temp -= *small.begin(), small.erase(small.begin()), --k;
		acc = k;
		ans = max(ans, temp);
	}
	printf("%lld", ans);
	return 0;
}