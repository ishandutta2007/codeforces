#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL s;

// L + 1  a
// R + 1  b

// a  L + 1  b  R + 1  1
// a  L  0b  R  1
// a + b = s
// popcount(a) + popcount(b) = t

LL solve(int L, int R, int t, LL s) {
	LL dp[55][110][2] = {};
	dp[0][0][0] = 1;
	for (int i = 0; i <= 51; ++i)
		for (int j = 0; j <= i * 2 && j <= t; ++j)
			for (int k = 0; k < 2; ++k)
				if (dp[i][j][k])
					for (int a = 0; a < 2; ++a) {
						if ((i == L - 1|| i > L) && a) continue;
						if (i == L && !a) continue;
						for (int b = 0; b < 2; ++b) {
							if ((i == R - 1 || i == R) && !b) continue;
							if (i > R && b) continue;
							if ((a + b + k & 1) == (s >> i & 1))
								dp[i + 1][j + a + b][a + b + k >= 2] += dp[i][j][k];
						}
					}
	return dp[52][t][0] + dp[52][t][1];
}

int main() {
	cin >> s;
	LL ans = 0;
	for (int L = 0; L <= 50; ++L)
		for (int R = 0; R <= 50; ++R) {
			LL x = (s + R + 1 - (1LL << R)) / ((1LL << L + 1) + (1LL << R + 1) - 3);
			if (x == 0) break;
			LL tmp = s - (x - 1) * ((1LL << L + 1) + (1LL << R + 1) - 3) + 1;
			for (int t = tmp & 1 ? 3 : 2; t <= L + R + 2; t += 2)
				ans += solve(L, R, t, (tmp + t) / 2);
		}
	cout << ans << endl;
	return 0;
}