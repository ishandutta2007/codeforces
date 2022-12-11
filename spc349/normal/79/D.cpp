#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int dist[10010], DD[30][30];
int s[10010];
vector <int> all;
vector <int> a;
queue <int> q;
int dp[1 << 20];
int n;

void calc(int x) {
	memset(dist, -1, sizeof(dist));
	q.push(x), dist[x] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < all.size(); i++) {
			int del = all[i];
			if (x - del > 0 && dist[x - del] == -1) {
				dist[x - del] = dist[x] + 1;
				q.push(x - del);
			}
			if (x + del <= n + 1 && dist[x + del] == -1) {
				dist[x + del] = dist[x] + 1;
				q.push(x + del);
			}
		}
	}
}

void chmin(int &x, int y) {
	x = min(x, y);
}

int main () {
	int k, l; scanf("%d%d%d", &n, &k, &l);
	for (int i = 0; i < k; i++) {
		int x; scanf("%d", &x);
		s[x] = 1;
	}
	while (l--) {
		int x; scanf("%d", &x);
		all.push_back(x);
	}
	for (int i = n + 1; i >= 1; i--) {
		s[i] ^= s[i - 1];
	}
	for (int i = 1; i <= n + 1; i++) {
		if (s[i]) a.push_back(i);
	}
	for (int i = 0; i < a.size(); i++) {
		int x = a[i];
		calc(x);
		for (int j = 0; j < a.size(); j++) {
			DD[i][j] = dist[a[j]];
		}
	}
	int N = a.size();
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int mask = 0; mask < (1 << N) - 1; mask++) {
		if (dp[mask] == INF) continue;
		int x = 0; while (mask >> x & 1) x++;
		for (int y = x + 1; y < N; y++) {
			if (mask >> y & 1) continue;
			if (DD[x][y] == -1) continue;
			chmin(dp[mask | 1 << x | 1 << y], dp[mask] + DD[x][y]);
		}
	}
	printf("%d\n", dp[(1 << N) - 1] == INF ? -1 : dp[(1 << N) - 1]);
	return 0;
}