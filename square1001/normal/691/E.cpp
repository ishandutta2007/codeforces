#include <iostream>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
int n; ll b, a[109], d[109], e[109], f[64][109][109];
int popcount(ll x) {
	int ret = 0;
	while (x) {
		if (x & 1) ret++;
		x >>= 1;
	}
	return ret;
}
int main() {
	cin >> n >> b; b--;
	for (int i = 0; i < n; i++) cin >> a[i], d[i] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (popcount(a[i] ^ a[j]) % 3 == 0) f[0][i][j] = 1;
		}
	}
	for (int i = 0; b > 0; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					f[i + 1][j][k] = (f[i + 1][j][k] + 1LL * f[i][j][l] * f[i][l][k]) % mod;
				}
			}
		}
		if (b & 1) {
			fill(e, e + n, 0);
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					e[k] = (e[k] + 1LL * d[j] * f[i][j][k]) % mod;
				}
			}
			for (int j = 0; j < n; j++) d[j] = e[j];
		}
		b >>= 1;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) sum = (sum + d[i]) % mod;
	cout << sum << endl;
	return 0;
}