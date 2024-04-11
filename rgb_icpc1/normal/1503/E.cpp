#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;
const int MX = 10005;
const int M = 998244353;

LL inv[MX], f[MX], g[MX];
void init() {
	int i;
	inv[1] = 1;
	for (i = 2; i < MX; i++) inv[i] = inv[M % i] * (M - M / i) % M;
	f[0] = g[0] = 1;
	for (i = 1; i < MX; i++) {
		f[i] = f[i - 1] * i % M;
		g[i] = g[i - 1] * inv[i] % M;
	}
}

inline LL C(int n, int m) {
	return f[n] * g[m] % M * g[n - m] % M;
}

inline LL HH(int n, int m) {
	return C(n + m - 1, m);
}

inline LL H(int n, int m) {
	return HH(n + 1, m);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	init();
	int n, m;
	cin >> n >> m;
	LL rlt = 0;
	for (int i = 1; i < n; i++) {
		LL A = 0, B = 0, C = 0;
		for (int j = 0; j < m; j++) {
			(A += H(i - 1, j) * H(i, m - j - 1) % M) %= M;
			(B += H(n - i - 1, j) * H(n - i, m - j - 1) % M) %= M;
			(C += H(i - 1, j) * H(i, m - j - 1) % M * H(n - i, j) % M * H(n - i, m - j - 1) % M) %= M;
			(C += H(i, j) * H(i, m - j - 1) % M * H(n - i - 1, j) % M * H(n - i, m - j - 1) % M) %= M;
			(C += M - H(i - 1, j) * H(i, m - j - 1) % M * H(n - i - 1, j) % M * H(n - i, m - j - 1) % M) %= M;
		}
		(rlt += A * B % M) %= M;
		(rlt += M - C) %= M;
	}
	swap(n, m);
	for (int i = 1; i < n; i++) {
		LL A = 0, B = 0, C = 0;
		for (int j = 0; j < m; j++) {
			(A += H(i - 1, j) * H(i, m - j - 1) % M) %= M;
			(B += H(n - i - 1, j) * H(n - i, m - j - 1) % M) %= M;
			(C += H(i - 1, j) * H(i, m - j - 1) % M * H(n - i, j) % M * H(n - i, m - j - 1) % M) %= M;
			(C += H(i, j) * H(i, m - j - 1) % M * H(n - i - 1, j) % M * H(n - i, m - j - 1) % M) %= M;
			(C += M - H(i - 1, j) * H(i, m - j - 1) % M * H(n - i - 1, j) % M * H(n - i, m - j - 1) % M) %= M;
		}
		(rlt += A * B % M) %= M;
		(rlt += M - C) %= M;
	}
	swap(n, m);
	for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) {
		(rlt += M - H(i - 1, j) * H(i, m - j - 1) % M * H(n - i, j - 1) % M * H(n - i - 1, m - j) % M) %= M;
		(rlt += M - H(i, j - 1) * H(i - 1, m - j) % M * H(n - i - 1, j) % M * H(n - i, m - j - 1) % M) %= M;
	}
	cout << rlt << endl;
	
	return 0;
}