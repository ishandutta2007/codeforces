#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll getMinLength(ll k) {
	return k*(k-1)/2 + (1 - k%2) * (k/2 - 1) + 1;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> pts(m);
	for (int i = 0; i < m; ++i) {
		int dump; scanf("%d %d", &dump, &pts[i]);
	}
	sort(pts.begin(), pts.end());
	reverse(pts.begin(), pts.end());
	vector<ll> pans(m, pts[0]);
	for (int i = 1; i < m; ++i) {
		pans[i] = pts[i] + pans[i-1];
	}
	ll ans = 0;
	for (ll k = 0; k < m; ++k) {
		if (getMinLength(k + 1) <= n) {
			ans = pans[k];
		}
	}
	printf("%lld\n", ans);
	return 0;
}