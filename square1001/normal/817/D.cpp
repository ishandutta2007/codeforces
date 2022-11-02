#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[1000009], p[1000009];
long long solve() {
	for (int i = 0; i < n; i++) p[i] = i;
	sort(p, p + n, [](int i, int j) { return a[i] < a[j]; });
	set<int> s = { -1, n };
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		set<int>::iterator it = s.lower_bound(p[i]);
		int r = *it, l = *(--it);
		ret += 1LL * a[p[i]] * (r - p[i]) * (p[i] - l);
		s.insert(p[i]);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	long long ret = solve();
	for (int i = 0; i < n; i++) a[i] *= -1;
	ret += solve();
	printf("%lld\n", -ret);
	return 0;
}