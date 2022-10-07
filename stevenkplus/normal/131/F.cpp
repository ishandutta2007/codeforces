#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN = 510;

char a[MAXN][MAXN];
int b[MAXN][MAXN];
int prefs[MAXN][MAXN];

int N, M, K;

bool star(int x, int y) {
	return a[x][y] && a[x - 1][y] && a[x + 1][y] && a[x][y - 1] && a[x][y + 1];
}

int ar[MAXN];
int main() {
	scanf("%d %d %d", &N, &M, &K);


	for(int i = 0; i < N; ++i) {
		scanf("%s", a[i]);
		for(int j = 0; j < M; ++j) {
			a[i][j] -= '0';
		}
	}

	--N;
	--M;
	for(int i = 1; i < N; ++i) {
		for(int j = 1; j < M; ++j) {
			if (star(i, j)) {
				++b[i - 1][j - 1];
			}
		}
	}

	--N;
	--M;

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			prefs[i][j + 1] = prefs[i][j] + b[i][j];
		}
	}

	ll ans = 0;
	for(int i = 0; i < M; ++i) {
		for(int j = i + 1; j <= M; ++j) {
			int l = 0;
			int r = 0;
			int sum = 0;
			while (r <= N) {
				if (sum >= K) {
					ans += N - r + 1;
					sum -= prefs[l][j] - prefs[l][i];
					++l;

				} else {
					sum += prefs[r][j] - prefs[r][i];
					++r;
				}
			}
		}
	}

	printf("%I64d\n", ans);
	return 0;
}