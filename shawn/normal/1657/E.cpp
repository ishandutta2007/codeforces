#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int P = 998244353;
const int N = 300;
ll c[N][N], f[N][N];
int n, k;

ll qpow(ll a, ll b) {
	ll ret = 1;
	for (; b; b >>= 1, a = a * a % P)
		if (b & 1) ret = ret * a % P;
	return ret;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> k;
	c[0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= n; j ++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
		}
	}
	// for (int i = 1; i <= n; i ++, cout << "\n")
	// 	for (int j = 1; j <= n; j ++) cout << c[i][j] << " ";
	f[1][0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= k; j ++) {
			for (int l = 1; l <= i; l ++) {
				int t = (i - l) * (l - 1) + (i - l) * (i - l - 1) / 2;
				f[i][j] = (f[i][j] + f[l][j - 1] * c[i - 1][l - 1] % P * qpow(k - j + 1, t) % P) % P;
			}
		}
	}
	cout << f[n][k];
	return 0;	
}