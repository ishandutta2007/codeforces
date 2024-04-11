#include <cstdio>

using namespace std;

const int MAXN = 210;

int N, L, K;

double DP[MAXN][MAXN];
double probs[MAXN];
int ar[MAXN];

int main() {
	scanf("%d %d %d", &N, &L, &K);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		probs[i] = tmp / 100.;
	}

	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp != -1) {
			ar[i] = tmp + 1;
		}
	}
	if (K > N) K = N;

	DP[0][K] = 1;
	for(int i = 0; i < N; ++i) {
		for(int j = N - 1; j >= 0; --j) {
			for(int k = 0; k <= N; ++k) {
				int nxt = k + ar[i];
				if (nxt > N) nxt = N;
				DP[j + 1][nxt] += DP[j][k] * probs[i];
				DP[j][k] *= 1 - probs[i];
			}
		}
	}

	double ans = 0;
	for(int i = L; i <= N; ++i) {
		for(int k = i; k <= N; ++k) {
			ans += DP[i][k];
		}
	}

	printf("%.10f\n", ans);
	return 0;
}