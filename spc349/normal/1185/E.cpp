#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

char a[2010][2010];
char b[2010][2010];
vector <pair <pair <int, int>, pair <int, int> > > op;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		int N = -1, px, py;
		for (int i = 0; i < n; i++) scanf("%s", a[i]);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			if (a[i][j] != '.') {
				if (N < a[i][j] - 'a') N = a[i][j] - 'a', px = i, py = j;
			}
		}
		if (N == -1) {
			printf("YES\n0\n");
			continue;
		}
		op.clear();
		for (int it = N; it >= 0; it--) {
			int minx = 0x3f3f3f3f, maxx = -0x3f3f3f3f, miny = 0x3f3f3f3f, maxy = -0x3f3f3f3f;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] - 'a' == it) {
						minx = min(minx, i), maxx = max(maxx, i);
						miny = min(miny, j), maxy = max(maxy, j);
					}
				}
			}
			if (minx == 0x3f3f3f3f) {
				op.push_back(mp(mp(px, py), mp(px, py)));
			} else {
				if (minx != maxx && miny != maxy) {
					printf("NO\n");
					goto END;
				}
				op.push_back(mp(mp(minx, miny), mp(maxx, maxy)));
			}
		}
		reverse(op.begin(), op.end());
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) b[i][j] = '.';
		for (int it = 0; it < op.size(); it++) {
			int x = op[it].fi.fi, y = op[it].fi.se, xx = op[it].se.fi, yy = op[it].se.se;
			while (x != xx || y != yy) {
				b[x][y] = char(it + 'a');
				if (x < xx) x++;
				if (x > xx) x--;
				if (y < yy) y++;
				if (y > yy) y--;
			}
			b[x][y] = char(it + 'a');
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				printf("NO\n");
				goto END;
			}
		}
		printf("YES\n");
		printf("%d\n", (int)op.size());
		for (int i = 0; i < op.size(); i++) {
			printf("%d %d %d %d\n", op[i].fi.fi + 1, op[i].fi.se + 1, op[i].se.fi + 1, op[i].se.se + 1);
		}
		END:;
	}
	return 0;
}