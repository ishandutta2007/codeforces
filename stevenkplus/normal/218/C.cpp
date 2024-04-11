#include <cstdio>

using namespace std;

const int MAXN = 10010;

int X[MAXN];
int Y[MAXN];

int par[MAXN];

int find(int n) {
	if (par[n] == n) return n;
	return par[n] = find(par[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;
}

int N;

int main() {
	scanf("%d", &N);

	for(int i = 0; i < N; ++i) {
		par[i] = i;
		scanf("%d %d", X + i, Y + i);
		for(int j = 0; j < i; ++j) {
			if (X[j] == X[i] || Y[j] == Y[i]) {
				merge(i, j);
			}
		}
	}

	int cnt = 0;
	for(int i = 0; i < N; ++i) {
		if (par[i] == i) {
			++cnt;
		}
	}

	int ans = cnt - 1;
	printf("%d\n", ans);
	return 0;
}