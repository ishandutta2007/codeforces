#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int p, a, dp[2][3334][2][2];
string A, B;

void upd(int &x, long long y) {
	x = (x + y) % P;
}

int main() {
	cin >> p >> a >> A;
	for (char &c : A) c -= '0';
	if (A.size() == 1 && A[0] == 0) A.clear();
	dp[0][0][0][0] = 1;
	int now = 0, lst = 1;
	while (!A.empty()) {
		swap(now, lst);
		B.clear();
		int x = 0;
		for (char c : A) {
			if (!B.empty() || x * 10ll + c >= p) B += (x * 10ll + c) / p;
			x = (x * 10ll + c) % p;
		}
		A = B;
		memset(dp[now], 0, sizeof dp[now]);
		for (int j = 0; j <= 3333; ++j)
			for (int a = 0; a < 2; ++a)
				for (int b = 0, z; b < 2; ++b) {
					z = dp[lst][j][a][b];
					if (!z) continue;
					int lim = min(p - 2, max(-1, x - a - b));
					upd(dp[now][j][0][0], (lim + 2ll) * (lim + 1) / 2 % P * z);
					upd(dp[now][j][1][0], (p + lim + 1ll) * (p - 2 - lim) / 2 % P * z);
					upd(dp[now][j + b][(b + p - 1) % p > x - a][b], 1ll * p * z);
					upd(dp[now][j + 1][0][1], (2ll * p - 2 - lim) * (lim + 1) / 2 % P * z);
					upd(dp[now][j + 1][1][1], (p - 1ll - lim) * (p - 2 - lim) / 2 % P * z);
				}
	}
	int ans = 0;
	for (int j = a; j <= 3333; ++j)
		ans = (ans + dp[now][j][0][0]) % P;
	printf("%d\n", ans);
	return 0;
}