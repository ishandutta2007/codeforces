#include <iostream>
#include <algorithm>
using namespace std;
int n, m, q, l, r, c, a[100009], s[75];
inline int binpow(int x, int y, int mod) {
	if (x == 1) return 1;
	if (y <= 30) {
		int res = 1; bool flag = false;
		for (int i = 0; i < y; i++) {
			if (1LL * res * x >= mod) flag = true;
			res = 1LL * res * x % mod;
		}
		return res + (flag ? mod : 0);
	}
	int ret = 1; x %= mod;
	while (y) {
		if (y & 1) ret = 1LL * ret * x % mod;
		x = 1LL * x * x % mod;
		y >>= 1;
	}
	return ret + mod;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	s[0] = m;
	int cur = m;
	while (cur != 1) {
		int x = cur;
		for (int i = 2; i * i <= cur; i++) {
			if (x % i == 0) {
				while (x % i == 0) x /= i;
				cur = cur / i * (i - 1);
			}
		}
		if (x != 1) cur = cur / x * (x - 1);
		s[++c] = cur;
	}
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r; l--;
		int pos = min(r - 1, l + c), ans = a[pos];
		for (int j = pos - 1; j >= l; j--) {
			ans = binpow(a[j], ans, s[j - l]);
		}
		cout << ans % m << '\n';
	}
	return 0;
}