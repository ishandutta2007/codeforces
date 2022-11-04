#include <bits/stdc++.h>

#define MX 100005

using namespace std;

int T, N, pn, A[MX], B[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
	freopen("O", "w", stdout);
#endif

	int i, j;
	for(scanf("%d", &T); T --; ) {
		scanf("%d", &N);
		int av = 0;
		for(i = 1; i <= N; i ++) scanf("%d", A + i), av += A[i], B[i] = A[i];
		if(av % N) {
			puts("-1");
			continue;
		}
		av /= N;
		printf("%d\n", 3 * N - 3);
		for(i = 2; i <= N; i ++) {
			int tp = (i - (A[i] % i)) % i;
			printf("1 %d %d\n", i, tp);
			printf("%d 1 %d\n", i, (A[i] + tp) / i);
		}
		for(i = 2; i <= N; i ++) printf("1 %d %d\n", i, av);
	}

	return 0;

}