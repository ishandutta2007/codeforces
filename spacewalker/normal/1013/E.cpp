#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int INF = 1000000000;
constexpr int DPMAX = 5010;

int dp[DPMAX][DPMAX][3], h[DPMAX];
int n;

constexpr int BOTH_STAND = 0;
constexpr int PREV_HOUSE = 1;
constexpr int PREV2_HOUSE = 2;

int fitHillTo(int iHouse, int iDig) {
	if (iDig < 0 or iDig >= n) return 0;
	else return max(0, h[iDig] - h[iHouse] + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", h + i);
	for (int hi = 0; hi < DPMAX; ++hi) {
		for (int hc = 0; hc < DPMAX; ++hc) {
			for (int t = 0; t < 3; ++t) dp[hi][hc][t] = INF;
		}
	}
	for (int t = 0; t < 3; ++t) dp[0][0][t] = 0;
	for (int hill = 1; hill <= n; ++hill) {
		for (int t = 0; t < 3; ++t) dp[hill][0][t] = 0;
		for (int houseCt = 1; houseCt <= (hill/2) + (hill%2); ++houseCt) {
			dp[hill][houseCt][BOTH_STAND] = min(
				dp[hill-1][houseCt][BOTH_STAND],
				dp[hill-1][houseCt-1][PREV_HOUSE] + fitHillTo(hill-1, hill) + fitHillTo(hill-1, hill-2));
			dp[hill][houseCt][PREV_HOUSE] = dp[hill-1][houseCt][PREV2_HOUSE];
			int p2hprh = (hill >= n - 1 ? INF : min(h[hill], h[hill+1] - 1));
			dp[hill][houseCt][PREV2_HOUSE] = min(
				dp[hill-1][houseCt][BOTH_STAND],
				dp[hill-1][houseCt-1][PREV_HOUSE] + fitHillTo(hill-1, hill-2) + max(0, p2hprh - h[hill-1] + 1));
			// printf("hill %d at %d houses: %lld %lld %lld\n", hill, houseCt, dp[hill][houseCt][BOTH_STAND], dp[hill][houseCt][PREV_HOUSE], dp[hill][houseCt][PREV2_HOUSE]);
			// printf("rh = %lld\n", p2hprh);
		}
	}
	for (int k = 1; k <= (n / 2) + (n % 2); ++k) {
		printf("%s%d", (k != 1 ? " " : ""), dp[n][k][BOTH_STAND]);
	}
	printf("\n");
	return 0;
}