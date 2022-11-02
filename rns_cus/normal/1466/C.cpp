#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, dp[N][4];
const int inf = 1e9;
char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		if (n < 2) {
			puts("0"); continue;
		}
		dp[2][1] = dp[2][2] = 1, dp[2][3] = 2;
		if (s[1] == s[2]) dp[2][0] = inf;
		else dp[2][0] = 0;
		for (int i = 3; i <= n; i ++) {
			for (int x = 0; x < 4; x ++) dp[i][x] = inf;
			for (int x = 0; x < 4; x ++) {
				for (int c = 0; c < 2; c ++) {
					int y = (x & 1) << 1 | c;
					int z = dp[i-1][x] + (c > 0);
					if (!c && (x & 1) == 0 && s[i] == s[i-1]) z = inf;
					if (!c && (x & 2) == 0 && s[i] == s[i-2]) z = inf;
					dp[i][y] = min(dp[i][y], z);
				}
			}
		}
		printf("%d\n", min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])));
    }

    return 0;
}