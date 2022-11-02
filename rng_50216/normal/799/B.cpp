#include <bits/stdc++.h>

std::vector<int> f[4][4];

int const INF = 1 << 30;
int const N = 1234567;

int p[N], a[N], b[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", p + i);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) scanf("%d", b + i);
	for (int i = 0; i < n; i++) {
		f[a[i]][b[i]].push_back(p[i]);
	}
	for (int i = 1; i <= 3; i++) 
		for (int j = 1; j <= 3; j++) std::sort(f[i][j].begin(), f[i][j].end(), [](int x, int y) { return x > y; });
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int c;
		scanf("%d", &c);
		int best = INF;
		for (int x = 1; x <= 3; x++) {
			for (int y = 1; y <= 3; y++) {
				if (x != c && y != c) continue;
				if (!f[x][y].empty()) {
					best = std::min(best, f[x][y].back());					
				}
			}
		}
		if (best != INF) {
  		for (int x = 1; x <= 3; x++) {
  			for (int y = 1; y <= 3; y++) {
  				if (x != c && y != c) continue;
  				if (!f[x][y].empty() && f[x][y].back() == best) {
						f[x][y].pop_back();
  				}
  			}
  		}
		}
		printf("%d ", best == INF ? -1 : best);
	}
	puts("");
}