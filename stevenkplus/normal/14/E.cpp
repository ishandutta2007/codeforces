#include <cstdio>

using namespace std;

const int MAXN = 22;
const int MAXT = 22;
const int MAXA = 10;

int dp[MAXN][MAXT][MAXA][MAXA];
int go(int n, int t, int a, int b) {
	if (t < 0) return 0;
	if (n == 0) {
		if (t == 0) return 1;
		else return 0;
	}
	int &ret = dp[n][t][a][b];
	if (ret) {
		return ret - 1;
	}

	for(int c = 1; c <= 4; ++c) {
		if (b == c) continue;
		if ((b < a && b < c) || (b > a && b > c)) {
			ret += go(n - 1, t - 1, b, c);
		} else {
			ret += go(n - 1, t, b, c);
		}
	}

	return ret++;
}

int N, T;
int main() {
	scanf("%d %d", &N, &T);

	int ans = 0;
	for(int a = 1; a <= 4; ++a) {
		for(int b = a + 1; b <= 4; ++b) {
			ans += go(N - 2, 2 * T - 1, a, b);
		}
	}

	printf("%d\n", ans);
	return 0;
}