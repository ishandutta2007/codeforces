#include <cstdio>

const int MAXN = 100100;
const int MOD = 1E9 + 9;

int par[MAXN];
int find(int n) {
	if (par[n] == n) return n;
	return par[n] = find(par[n]);
}

bool join(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;
	return a != b;
}

int N, M;


int main() {
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++i) {
		par[i] = i;
	}

	int ans = 0;
	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!join(a, b)) {
			(ans *= 2) %= MOD;
			(++ans) %= MOD;
		}

		printf("%d\n", ans);
	}

	return 0;
}