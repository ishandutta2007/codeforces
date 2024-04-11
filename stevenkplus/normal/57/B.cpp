#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

ll incs[MAXN];
ll stairs[MAXN];

ll sums[MAXN];

int N, M, K;

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int off = c - a;
		incs[b] += off;
		incs[a - 1] -= off;
		++stairs[b];
		--stairs[a - 1];
	}

	ll num = 0;
	ll cur = 0;
	for(int i = N; i > 0; --i) {
		cur += incs[i];
		sums[i] += cur;

		num += stairs[i];
		sums[i] += num * i;
	}

	ll ans = 0;
	for(int i = 0; i < K; ++i) {
		int x;
		scanf("%d", &x);
		ans += sums[x];
	}

	printf("%I64d\n", ans);
	return 0;

}