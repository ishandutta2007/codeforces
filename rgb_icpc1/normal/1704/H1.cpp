#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long LL;

const int MX = 5005;

int N, M;
int dp[MX][MX];

inline int add(int x, int y) {return (x + y) % M;}
inline int mul(int x, int y) {return 1LL * x * y % M;}
inline int modpow(int x, int y) {
	int r = 1;
	for (; y; y >>= 1) {
		if (y & 1) r = mul(r, x);
		x = mul(x, x);
	}
	return r;
}

int f[MX], g[MX], inv[MX];
int pw[MX][MX];

void init() {
	int i, j;
	inv[1] = 1;
	for (i = 2; i < MX; i++) inv[i] = mul(inv[M % i], (M - M / i));
	f[0] = g[0] = 1;
	for (i = 1; i < MX; i++) {
		f[i] = mul(f[i - 1], i);
		g[i] = mul(g[i - 1], inv[i]);
	}
	for (i = 1; i < MX; i++) {
		pw[i][0] = 1;
		for (j = 1; j < MX; j++) pw[i][j] = mul(pw[i][j - 1], i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int i, j;
	cin >> N >> M;
	init();
	dp[0][1] = 1;
	for (i = 2; i <= N; i++) dp[0][i] = mul(dp[0][i - 1], i);
	int rlt = 0;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) {
		dp[i][j] = add(mul(dp[i - 1][j], i), mul(dp[i][j - 1], j));
	}
	for (i = 0; i <= N; i++) for (j = 0; j <= N; j++) {
		if (i + 2 * j > N) continue;
		rlt = add(rlt, mul(mul(mul(dp[i][j], f[N]), mul(pw[N - 1][j], g[j])), mul(mul(g[i], g[j]), mul(g[N - i - 2 * j], pw[i + j][N - i - 2 * j]))));
	}
	cout << rlt << '\n';

    return 0;

}