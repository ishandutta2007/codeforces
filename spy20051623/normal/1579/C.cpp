#include <bits/stdc++.h>

using namespace std;

char s[20][20];
int a[20][20], b[20][20];
int n, m, k;

bool check() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.') continue;
			bool ok = false;
			int x, y, cnt;
			x = i, y = j, cnt = 0;
			while (x < n && y < m) {
				if (a[x][y] >= max(k, cnt) && b[x][y] >= max(k, cnt)) {
					ok = true;
					break;
				}
				++cnt, ++x, ++y;
			}
			if (ok) continue;
			x = i, y = j, cnt = 0;
			while (x < n && y >= 0) {
				if (a[x][y] >= max(k, cnt) && b[x][y] >= max(k, cnt)) {
					ok = true;
					break;
				}
				++cnt, ++x, --y;
			}
			if (!ok) return false;
		}
	}
	return true;
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) scanf("%s", s[i]);
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < m - 1; ++j)
			if (s[i][j] == '*' && s[i + 1][j + 1] == '*') a[i + 1][j + 1] = a[i][j] + 1;
	for (int i = 0; i < n - 1; ++i)
		for (int j = m - 1; j > 0; --j)
			if (s[i][j] == '*' && s[i + 1][j - 1] == '*') b[i + 1][j - 1] = b[i][j] + 1;
	if (check()) printf("YES\n");
	else printf("NO\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}