#include <cstdio>

using namespace std;

const int MAXN = 110;

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

bool knowlang[MAXN][MAXN];

int N, M;

int main() {

	scanf("%d %d", &N, &M);
	bool anylang = false;
	for(int i = 0; i < N; ++i) {
		int k;
		scanf("%d", &k);
		if (k) anylang = true;
		for(int j = 0; j < k; ++j) {
			int p;
			scanf("%d", &p);
			knowlang[i][p] = true;
		}
	}

	for(int i = 0; i < N; ++i) {
		par[i] = i;
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			bool good = false;

			for(int k = 1; k <= M; ++k) {
				if (knowlang[i][k] && knowlang[j][k]) {
					good = true;
					break;
				}
			}
			if (good) {
				merge(i,j);
			}
		}
	}


	int cnt = 0;
	for(int i = 0; i < N; ++i) {
		if (par[i] == i) ++cnt;
	}
	int ans = cnt - 1;
	if (!anylang) ans++;
	printf("%d\n", ans);
	return 0;
}