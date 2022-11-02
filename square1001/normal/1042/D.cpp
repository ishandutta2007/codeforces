#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n; long long t, a[200009];
long long solve(int l, int r) {
	if (r - l == 1) return 0;
	int m = (l + r) >> 1;
	long long lc = solve(l, m);
	long long rc = solve(m, r);
	int ptr = m;
	long long res = 0;
	for (int i = l; i < m; ++i) {
		while (ptr != r && a[ptr] - a[i] < t) ++ptr;
		res += ptr - m;
	}
	sort(a + l, a + r);
	return lc + rc + res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> t;
	for (int i = 0; i < n; ++i) cin >> a[i + 1], a[i + 1] += a[i];
	long long ret = solve(0, n + 1);
	cout << ret << '\n';
	return 0;
}