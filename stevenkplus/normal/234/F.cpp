#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 1 << 30;
const int MAXN = 210;
const int MAXM = 40100;

int sums[MAXN];
int ar[MAXN];

int N, A, B;

int dp[MAXN][MAXM][3];
int get(int n, int r, int prc) { // red = 0, green = 1, a = #red left
	if (n == N) {
		return 0;
	}
	int &ret = dp[n][r][prc];
	if (ret) {
		return ret - 1;
	}
	ret = inf;
	int g = B - (sums[n] - (A - r));
	int next = ar[n];
	if (r >= next) {
		int cost = get(n + 1, r - next, 0);
		if (prc == 1) {
			cost += min (next, ar[n - 1]);
		}
		ret = min (ret, cost);
	}
	if (g >= next) {
		int cost = get(n + 1, r, 1);
		if (prc == 0) {
			cost += min(next, ar[n - 1]);
		}
		ret = min (ret, cost);
	}
	return ret++;
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	scanf("%d", &N);
	scanf("%d %d", &A, &B);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	for(int i = 0; i < N; ++i) {
		sums[i + 1] = sums[i] + ar[i];
	}
	int ans = get(0, A, -1);
	if (ans == inf) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}