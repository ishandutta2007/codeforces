#include <cstdio>

const int MAXN = 100100;

int ar[MAXN];

int N, T;

int main() {
	scanf("%d %d", &N, &T);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}

	int l = 0;
	int r = 0;
	int sum = 0;
	int ans = 0;

	while (r <= N) {
		if (sum <= T) {
			if (r - l > ans) {
				ans = r - l;
			}
			if (r == N) break;
			sum += ar[r];
			++r;
		} else {
			sum -= ar[l];
			++l;
		}
	}

	printf("%d\n", ans);
	return 0;
}