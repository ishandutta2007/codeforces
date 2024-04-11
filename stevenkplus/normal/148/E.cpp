#include <cstdio>

using namespace std;

const int MAXN = 110;
const int MAXM = 10100;

int ar[MAXN][MAXN];
int vals[MAXN][MAXN];
int dp[MAXN][MAXM];
int size[MAXN];

int N, M;

int get(int n, int m) {
	if (n == N) return 0;
	int &ret = dp[n][m];
	if (ret) return ret - 1;

	for(int i = 0; i <= size[n] && i <= m; ++i) {
		int k = vals[n][i] + get(n + 1, m - i);
		if (k > ret) {
			ret = k;
		}
	}
	return ret++;
}

void prec() {
	for(int i = 0; i < N; ++i) {
		int z = size[i];
		int lsum = 0;
		for(int a = 0; a <= z; ++a) {
			int rsum = 0;
			for(int b = 0; b + a <= z; ++b) {
				int s = lsum + rsum;
				if (s > vals[i][a + b]) {
					vals[i][a + b] = s;
				}
				if (b < z)
					rsum += ar[i][z - b - 1];
			}
			if (a < z)
				lsum += ar[i][a];
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		scanf("%d", size + i);
		for(int j = 0; j < size[i]; ++j) {
			scanf("%d", ar[i] + j);
		}
	}

	prec();
	int ans = get(0, M);
	printf("%d\n", ans);
	return 0;
}