#include <cstdio>

const int MAXN = 1001000;

int dp[MAXN];

int getdp(int x) {
	if (x == 0) return x;
	int &ret = dp[x];
	if (ret) return ret - 1;
	ret = -1;

	int cur = x;
	while (cur) {
		int d = cur % 10;
		cur /= 10;

		int val = getdp(x - d) + 1;
		if (val < ret || ret == -1) ret = val;
	}

	return ret++;
}

int N;

int main() {
	while (scanf("%d", &N) != -1) {
		int ans = getdp(N);
		printf("%d\n", ans);
		return 0;
	}
	return 0;
}