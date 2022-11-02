#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m, x[N], y[N], idx[N], idy[N];
map <int, int> mp;
typedef pair <int, int> pii;
set <pii> S;
const int inf = 2e9 + 7;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &y[i]), S.emplace(x[i], y[i]), idx[i] = idy[i] = i;
    sort(idx + 1, idx + n + 1, [&](int i, int j) {return x[i] != x[j] ? x[i] < x[j] : y[i] < y[j];});
    sort(idy + 1, idy + n + 1, [&](int i, int j) {return y[i] != y[j] ? y[i] < y[j] : x[i] < x[j];});
    x[0] = y[0] = inf;
    int cx = 0, cy = 0, i = 1, j = 1;
    while (1) {
		while (x[idx[i]] < cx) i ++;
		while (y[idy[j]] < cy) j ++;
		int nx = x[idx[i]], ny = y[idy[j]];
		if (nx != cx && ny != cy) {
			mp[cx] = cy;
			int d = min(nx - cx, ny - cy);
			if (d > 1e9) break;
			cx += d, cy += d;
		}
		if (S.count(pii(cx, cy))) mp[cx] = cy, cx ++, cy ++;
		else if (nx == cx && y[idx[i]] <= cy) mp[cx] = y[idx[i]], cx ++;
		else if (ny == cy && x[idy[j]] <= cx) cy ++;
		else mp[cx] = cy, cx ++, cy ++;
    }
	while (m --) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (S.count(pii(a, b))) puts("LOSE");
		else {
			auto it = mp.upper_bound(a);
			it --;
			int c = it -> second + a - it -> first;
			if (b == c) puts("LOSE");
			else puts("WIN");
		}
	}

    return 0;
}