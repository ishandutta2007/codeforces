#include <bits/stdc++.h>
using namespace std;
#define N 1010

int t, n, m, a[N][N];
char s[N];
bool vis[N][N];
pair <int, int> p[N*N];
int cnt;

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, 0, -1, 1, 0, -1, 1, -1};

void dfs(int i, int j) {
	vis[i][j] = 1;
	p[++cnt].first = i, p[cnt].second = j;
	for (int k = 0; k < 8; k ++) {
		int I = i + dx[k], J = j + dy[k];
		if (!vis[I][J]) dfs(I, J);
	}
}

bool ok(int n) {
	if (n % 4) return 0;
	int k = n / 4 + 1;
	sort(p + 1, p + n + 1);
	if (p[1].first == p[2].first) {
		for (int i = 2; i <= k; i ++)
			if (p[i].first != p[1].first || p[i].second != p[i-1].second + 1) return 0;
		for (int i = k + 1; i <= 3 * k - 4; i ++) {
			int d = (i - k + 1) >> 1;
			if (p[i].first != p[1].first + d) return 0;
			if (((i - k) & 1) && p[i].second != p[1].second) return 0;
			if (!((i - k) & 1) && p[i].second != p[k].second) return 0;
		}
		int d = k - 1;
		for (int i = 3 * k - 3; i <= 4 * k - 4; i ++) {
			if (p[i].first != p[1].first + d) return 0;
			if (p[i].second != p[i-3*k+4].second) return 0;
		}
		return 1;
	}
	else {
		for (int i = 2; i <= 2 * k - 1; i ++) {
			if (i & 1) {
				if (p[i].first != p[1].first + i / 2 || p[i].second != p[1].second + i / 2) return 0;
			}
			else {
				if (p[i].first != p[1].first + i / 2 || p[i].second != p[1].second - i / 2) return 0;
			}
		}
		for (int i = 2 * k; i <= 4 * k - 5; i ++) {
			if (i & 1) {
				int d = i - (2 * k - 1) >> 1;
				if (p[i].first != p[2*k-1].first + d || p[i].second != p[2*k-1].second - d) return 0;
			}
			else {
				int d = i - (2 * k - 2) >> 1;
				if (p[i].first != p[2*k-2].first + d ||  p[i].second != p[2*k-2].second + d) return 0;
			}
		}
		if (p[n].first != p[1].first + 2 * k - 2 || p[n].second != p[1].second) return 0;
		return 1;
	}
}

int main() {
//	freopen("c.in", "r", stdin);
//	freopen("new.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			scanf("%s", s);
			int len = strlen(s);
			for (int j = 0; j < len; j ++) a[i][j+1] = s[j] - '0';
		}
		for (int i = 0; i <= n + 1; i ++) a[i][0] = a[i][m+1] = 0;
		for (int j = 0; j <= m + 1; j ++) a[0][j] = a[n+1][j] = 0;
		for (int i = 0; i <= n + 1; i ++) for (int j = 0; j <= m + 1; j ++) vis[i][j] = a[i][j] ? 0 : 1;
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (vis[i][j]) continue;
				cnt = 0;
				dfs(i, j);
				if (ok(cnt)) ans ++;
			}
		}
		printf("%d\n", ans);
	}
}