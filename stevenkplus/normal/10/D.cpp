#include <cstdio>

using namespace std;

const int MAXN = 510;

int X[MAXN];
int Y[MAXN];

int trace[MAXN][MAXN];
int dp[MAXN];

int N, M;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", X + i);
	}

	scanf("%d", &M);
	for(int j = 0; j < M; ++j) {
		scanf("%d", Y + j);
	}

	int best = 0;
	int start = -1;
	for(int i = N - 1; i >= 0; --i) {
		int nxt = -1;
		int val = 0;
		for(int j = M - 1; j >= 0; --j) {
			if (X[i] == Y[j]) {
				trace[i][j] = nxt;
				dp[j] = val + 1;
			}
			if (dp[j] > val && X[i] < Y[j]) {
				val = dp[j];
				nxt = j;
			}
			if (dp[j] > best) {
				best = dp[j];
				start = j;
			}
		}
	}

	printf("%d\n", best);
	if (best) {
		int cury = start;
		int curx = 0;
		while (X[curx] != Y[cury]) ++curx;
		printf("%d", Y[cury]);
		while (trace[curx][cury] != -1) {
			cury = trace[curx][cury];
			while (X[curx] != Y[cury]) ++curx;
			printf(" %d", Y[cury]);
		}
	}
	printf("\n");

	return 0;
}