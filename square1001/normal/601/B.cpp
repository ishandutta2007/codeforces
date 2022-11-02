#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
int n, q, a[100009], b[100009], l[109], r[109], p[100009]; long long ret[109];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < q; i++) cin >> l[i] >> r[i], l[i]--;
	for (int i = 0; i < n - 1; i++) b[i] = abs(a[i + 1] - a[i]), p[i] = i;
	sort(p, p + n - 1, [](int i, int j) { return b[i] > b[j]; });
	set<int> s = { -1, n - 1 };
	for (int i = 0; i < n - 1; i++) {
		set<int>::iterator it = s.lower_bound(p[i]);
		int pr = *it, pl = *(--it) + 1;
		for (int j = 0; j < q; j++) {
			int xl = max(pl, l[j]), xr = min(pr, r[j] - 1);
			if (xl <= p[i] && p[i] < xr) {
				ret[j] += 1LL * (p[i] - xl + 1) * (xr - p[i]) * b[p[i]];
			}
		}
		s.insert(p[i]);
	}
	for (int i = 0; i < q; i++) cout << ret[i] << endl;
	return 0;
}