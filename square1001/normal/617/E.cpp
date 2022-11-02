#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int max_val = (1 << 20);
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, q, x;
	cin >> n >> q >> x;
	vector<int> a(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i + 1];
		a[i + 1] ^= a[i];
	}
	vector<int> l(q), r(q), p(q);
	for (int i = 0; i < q; ++i) {
		cin >> l[i] >> r[i];
		--l[i];
		p[i] = i;
	}
	int b = sqrt(n);
	sort(p.begin(), p.end(), [&](int i, int j) { return l[i] / b != l[j] / b ? l[i] < l[j] : r[i] < r[j]; });
	vector<long long> ans(q);
	vector<int> cnt(max_val); cnt[0] = 1;
	int cl = 0, cr = 0; long long cans = 0;
	for (int i : p) {
		while (cr < r[i]) {
			++cr;
			cans += cnt[a[cr] ^ x];
			++cnt[a[cr]];
		}
		while (cl > l[i]) {
			--cl;
			cans += cnt[a[cl] ^ x];
			++cnt[a[cl]];
		}
		while (cr > r[i]) {
			--cnt[a[cr]];
			cans -= cnt[a[cr] ^ x];
			--cr;
		}
		while (cl < l[i]) {
			--cnt[a[cl]];
			cans -= cnt[a[cl] ^ x];
			++cl;
		}
		ans[i] = cans;
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}