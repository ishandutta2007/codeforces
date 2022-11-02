#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

int const INF = 1 << 30;

vector<int> z[4];
int cost[N], have[N];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", cost + i);
	}
	int q;
	for (int s = 0; s < 2; s++) {
  	scanf("%d", &q);
  	for (int i = 0; i < q; i++) {
  		int x;
  		scanf("%d", &x);
  		--x;
  		have[x] |= 1 << s;
  	}
	}
	for (int i = 0; i < n; i++) {
		z[have[i]].push_back(cost[i]);
	}
	for (int i = 0; i < 4; i++) std::sort(z[i].begin(), z[i].end());
	int both = 0;
	int single = 0;
	int need = k;
	long long ans = 0;
	while (need > 0 && (both < (int) z[3].size() || (single < (int) z[1].size() && single < (int) z[2].size()))) {
		if (both >= (int) z[3].size() || (single < (int) z[1].size() && single < (int) z[2].size() && z[3][both] > z[1][single] + z[2][single])) {
			ans += z[1][single] + z[2][single];
			++single;
		} else {
			ans += z[3][both];
			++both;
		}
		--need;
	}
	if (need > 0 || m < k) {
		puts("-1");
		return 0;
	}
	while (both + 2 * single > m && both < (int) z[3].size()) {
		--single;
		ans -= z[1][single] + z[2][single];
		ans += z[3][both];
		++both;
	}
	if (both + 2 * single > m) {
		puts("-1");
		return 0;
	}
	if (both + 2 * single == m) {
		printf("%lld\n", ans);
		return 0;
	}	
	int sz[4];
	sz[0] = 0;
	sz[1] = sz[2] = single;
	sz[3] = both;
	int h = both + single * 2;
	while (h < m) {
		int mn = -1;
		for (int i = 0; i < 4; i++) {
			if (sz[i] < (int) z[i].size() && (mn < 0 || z[mn][sz[mn]] > z[i][sz[i]])) {
				mn = i;
			}
		}
		int best = mn < 0 ? INF : z[mn][sz[mn]];
		int best2 = INF;
		if (sz[1] < (int) z[1].size() && sz[2] < (int) z[2].size() && sz[3] > 0) {
			best2 = z[1][sz[1]] + z[2][sz[2]] - z[3][sz[3] - 1];
		}
		if (best < best2) {
			++sz[mn];
			ans += best;
		} else {
			ans += best2;
			--sz[3];
			++sz[1];
			++sz[2];
		}
		++h;
	}
	printf("%lld\n", ans);
}