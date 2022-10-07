#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 1001000;

int conns[MAXN];

ll choose(int n, int r) {
	ll prod = 1;
	for(int i = 1; i <= r; ++i) {
		prod *= (n - i + 1);
		prod /= i;
	}
	return prod;
}

int N, M;

int main() {
	scanf("%d %d", &N, &M);

	ll sum = choose(N, 3);
	sum -= ll(M) * (N - 2);
	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		++conns[a];
		++conns[b];
	}

	for(int i = 1; i <= N; ++i) {
		sum += choose(conns[i], 2);
	}

	printf("%I64d\n", sum);
	return 0;
}