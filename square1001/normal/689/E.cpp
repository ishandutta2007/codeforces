#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int n, m, fact[200009], inv[200009], factinv[200009];
int coeff(int x, int y) {
	if (x < y || y < 0) return 0;
	return 1LL * fact[x] * factinv[y] % mod * factinv[x - y] % mod;
}
int main() {
	fact[0] = 1; for (int i = 1; i <= 200000; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
	inv[1] = 1; for (int i = 2; i <= 200000; i++) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
	factinv[0] = 1; for (int i = 1; i <= 200000; i++) factinv[i] = 1LL * factinv[i - 1] * inv[i] % mod;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<int> l(n), r(n), p(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		p[i] = l[i];
		p[i + n] = ++r[i];
	}
	sort(p.begin(), p.end());
	vector<int> sum(2 * n);
	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(p.begin(), p.end(), l[i]) - p.begin(); sum[l[i]]++;
		r[i] = lower_bound(p.begin(), p.end(), r[i]) - p.begin(); sum[r[i]]--;
	}
	for (int i = 1; i < 2 * n; i++) sum[i] += sum[i - 1];
	int ret = 0;
	for (int i = 0; i < 2 * n - 1; i++) ret = (ret + 1LL * (p[i + 1] - p[i]) * coeff(sum[i], m)) % mod;
	cout << ret << endl;
	return 0;
}