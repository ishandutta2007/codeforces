#include <cstdio>

using namespace std;

const int MAXT = 100100;
const int MAXN = 310;
const int MOD = 1E9 + 7;

int child[MAXN];
int ar[MAXN];
bool haspar[MAXN];
bool vis[MAXN];

int N, Q, T;

int ways[MAXT];

int go() {
	scanf("%d %d %d", &N, &Q, &T);

	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}

	for(int i = 0; i < Q; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		child[a] = b;
		haspar[b] = true;
	}

	for(int i = 1; i <= N; ++i) {
		if (!haspar[i]) {
			int cur = i;
			vis[cur] = true;
			while (child[cur]) {
				T -= ar[cur];
				if (T < 0) return 0;
				ar[child[cur]] += ar[cur];
				cur = child[cur];
				vis[cur] = true;
			}
		}
	}
	for(int i = 1; i <= N; ++i) {
		if (!vis[i]) return 0;
	}

	ways[0] = 1;
	for(int i = 1; i <= N; ++i) {
		for(int j = 0; j + ar[i] <= T; ++j) {
			(ways[j + ar[i]] += ways[j]) %= MOD;
		}
	}
	return ways[T];
}

int main() {
	int ans = go();
	printf("%d\n", ans);
	return 0;
}