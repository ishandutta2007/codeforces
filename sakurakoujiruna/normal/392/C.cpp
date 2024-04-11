#include <bits/stdc++.h>
using namespace std;

const int N = 85;
const int Mod = (int)1e9 + 7;
using ll = long long;

ll fac[N], inv[N];
ll binom(int n, int m) {
	return fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

int s;
struct Mat {
	ll a[N][N];
	ll* operator [](int i) {
		return a[i];
	}
	Mat operator *(Mat m) {
		Mat r;
		for(int i = 0; i < s; i ++)
			for(int j = 0; j < s; j ++) {
				r[i][j] = 0;
				for(int k = 0; k < s; k ++) {
					r[i][j] += (*this)[i][k] * m[k][j];
					r[i][j] %= Mod;
				}
			}
		return r;
	}
}e;

Mat qpow(Mat a, ll b) {
	Mat r = e;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a;
		a = a * a;
	}
	return r;
}

int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for(int i = 2; i < N; i ++)
		inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
	for(int i = 2; i < N; i ++) {
		fac[i] = fac[i - 1] * i % Mod;
		inv[i] = inv[i - 1] * inv[i] % Mod;
	}

	ios :: sync_with_stdio(false);
	ll n; int k; cin >> n >> k;
	s = 2 * k + 3;
	for(int i = 0; i < s; i ++)
		for(int j = 0; j < s; j ++)
			e[i][j] = (i == j);

	Mat m;
	for(int i = 0; i < s; i ++)
		for(int j = 0; j < s; j ++)
			m[i][j] = 0;
	for(int i = 0; i < k + 1; i ++) {
		m[i][i + k + 1] = 1;
		for(int j = 0; j <= i; j ++) {
			m[i + k + 1][j] = binom(i, j) *
				((1LL << (i - j)) % Mod) % Mod;
			m[i + k + 1][j + k + 1] = binom(i, j);
		}
	}
	m[s - 1][s - 1] = m[s - 1][s - 2] = 1;
	m = qpow(m, n);

	ll ans = m[s - 1][0];
	for(int i = 0; i < k + 1; i ++)
		ans += m[s - 1][i + k + 1];
	cout << (ans % Mod + Mod) % Mod << '\n';
	return 0;
}