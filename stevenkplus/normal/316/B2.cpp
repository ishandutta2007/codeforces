#include <cstdio>

using namespace std;

const int MAXN = 2010;

int par[MAXN];
int size[MAXN];
int root[MAXN];
int place[MAXN];
bool vis[MAXN];
bool dp[MAXN];

void go(int n) {
	if (vis[n]) return;
	vis[n] = true;
	if (par[n] == 0) {
		root[n] = n;
		place[n] = 1;
	} else {
		go(par[n]);
		root[n] = root[par[n]];
		place[n] = place[par[n]] + 1;
	}
	++size[root[n]];
}

int N;

int main() {
	int x;
	scanf("%d %d", &N, &x);

	for(int i = 1; i <= N; ++i) {
		scanf("%d", par + i);
	}

	for(int i = 1; i <= N; ++i) {
		go(i);
	}

	dp[0] = true;
	for(int i = 1; i <= N; ++i) {
		if (root[i] == i && root[x] != i) {
			for(int x = N; x >= 0; --x) {
				if (dp[x]) {
					dp[x + size[i]] = true;
				}
			}
		}
	}

	for(int i = 0; i <= N; ++i) {
		if (dp[i]) {
			printf("%d\n", i + place[x]);
		}
	}

	return 0;
}