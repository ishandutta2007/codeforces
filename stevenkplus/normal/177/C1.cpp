#include <cstdio>

using namespace std;

const int MAXN = 50100;

int N, M, K;

int par[MAXN];

int size[MAXN];
bool bad[MAXN];

int find(int n) {
	if (par[n] == n) { return n; }
	return par[n] = find(par[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;
}

int main() {
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; ++i)
		par[i] = i;

	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}

	scanf("%d", &K);
	for(int i = 0; i < K; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (find(a) == find(b)) {
			bad[find(a)] = true;
		}
	}

	for(int i = 1; i <= N; ++i) {
		++size[find(i)];
	}

	int ans = 0;
	for(int i = 1; i <= N; ++i) {
		if (par[i] == i) {
			if (!bad[i]) {
				if (size[i] > ans) ans = size[i];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}