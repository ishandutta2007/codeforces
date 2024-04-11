#include <bits/stdc++.h>

using namespace std;

int a[50005][15];
int cnt;

int bat(int x, int y) {
	int u = 0, v = 0;
	for (int i = 1; i <= 5; ++i) {
		if (a[x][i] < a[y][i])++u;
		if (a[x][i] > a[y][i])++v;
	}
	if (u >= 3)return x;
	if (v >= 3)return y;
}

void solve() {
	++cnt;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 5; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int win = 1;
	for (int i = 2; i <= n; ++i) {
		int tmp = bat(win, i);
		if (!tmp)win = i + 1;
		else win = tmp;
	}
	for (int i = 1; i <= n; ++i) {
		if (i != win) {
			int tmp = bat(win, i);
			if (tmp != win) {
				win = 0;
				break;
			}
		}
	}
	if (win != 0)printf("%d\n", win);
	else printf("-1\n");
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