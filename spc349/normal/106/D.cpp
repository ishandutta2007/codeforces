#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];
char op[100010];
int up[1010][1010], dw[1010][1010], le[1010][1010], ri[1010][1010];
char buf[1010];
int len[100010];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			up[i][j] = a[i][j] == '#' ? 0 : up[i - 1][j] + 1;
			le[i][j] = a[i][j] == '#' ? 0 : le[i][j - 1] + 1;
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			dw[i][j] = a[i][j] == '#' ? 0 : dw[i + 1][j] + 1;
			ri[i][j] = a[i][j] == '#' ? 0 : ri[i][j + 1] + 1;
		}
	}
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%s%d", buf, &len[i]);
		op[i] = buf[0];
	}
	string ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
				int x = i, y = j;
				for (int it = 0; it < k; it++) {
					char dir = op[it]; int l = len[it];
					if (dir == 'N') {
						if (up[x][y] <= l) goto END;
						x -= l;
					} else if (dir == 'S') {
						if (dw[x][y] <= l) goto END;
						x += l;
					} else if (dir == 'W') {
						if (le[x][y] <= l) goto END;
						y -= l;
					} else {
						if (ri[x][y] <= l) goto END;
						y += l;
					}
				}
				ans.push_back(a[i][j]);
				END:;
			}
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == 0) ans = "no solution";
	cout << ans << endl;
	return 0;
}