#include <bits/stdc++.h>

#define MX 105

using namespace std;

int T, N, K, A[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
	freopen("O", "w", stdout);
#endif

	int i, j;
	for(scanf("%d", &T); T --; ) {
		scanf("%d%d", &N, &K);
		K --;
		for(i = 0; i < N; i ++) scanf("%d", A + i);
		int cnt = 0;
		for(i = 0; i < N - 1; i ++) cnt += A[i] < A[i + 1];
		printf("%d\n", K ? (!cnt ? 1 : (cnt + K - 1) / K) : (cnt ? -1 : 1));
	}

	return 0;

}