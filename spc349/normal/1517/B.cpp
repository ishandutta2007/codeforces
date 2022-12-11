#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[110][110];
int ans[110][110];
set <int> S[110];
vector <pii> all;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		all.clear();
		for (int i = 0; i < n; i++) {
			S[i].clear();
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				all.push_back(mp(a[i][j], i * m + j));
				S[i].insert(j);
			}
		}
		sort(all.begin(), all.end());
		for (int i = 0; i < m; i++) {
			int x = all[i].se / m, y = all[i].se % m;
			S[x].erase(y);
		}
		for (int i = 0; i < m; i++) {
			int x = all[i].se / m, y = all[i].se % m;
			for (int j = 0; j < n; j++) {
				if (x == j) ans[j][i] = a[j][y];
				else {
					int tmp = *S[j].begin(); S[j].erase(S[j].begin());
					ans[j][i] = a[j][tmp];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}