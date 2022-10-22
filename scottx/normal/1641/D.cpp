#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int n, m, w[100005], a[100005][7], id[100005];
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	rep(i, 0, n - 1) {
		rep(j, 0, m - 1) scanf("%d", &a[i][j]);
		sort(a[i], a[i] + m);
		scanf("%d", &w[i]);
		id[i] = i;
	}
	sort(id, id + n, [&](int lhs, int rhs) { return w[lhs] < w[rhs]; });
	vector<int> all;
	map<vector<int>, int> mp;
	int ans = int(2e9) + 5;
	int limit[6];
	memset(limit, 0, sizeof(limit));
	int pw = 1;
	per(i, m, 0) {
		limit[i] = pw;
		pw *= m;
	}
	rep(_, 0, n - 1) {
		int i = id[_];
		for (auto& j: all) {
			bool gg = 0;
			int p1 = 0, p2 = 0;
			while (p1 < m && p2 < m) {
				if (a[i][p1] == a[j][p2]) {
					gg = 1;
					break;
				}
				if (a[i][p1] < a[j][p2])
					++p1;
				else
					++p2;
			}
			if (!gg) {
				ans = min(ans, w[i] + w[j]);
				break;
			}
		}
		bool err = 0;
		rep(mask, 0, (1 << m) - 1) {
			vector<int> v;
			rep(j, 0, m - 1) if (mask >> j & 1) v.push_back(a[i][j]);
			if (mp[v] >= limit[__builtin_popcount(mask)]) {
				err = 1;
				break;
			}
		}
		if (!err) {
			all.push_back(i);
			rep(mask, 0, (1 << m) - 1) {
				vector<int> v;
				rep(j, 0, m - 1) if (mask >> j & 1) v.push_back(a[i][j]);
				++mp[v];
			}
		}
	}
	if (ans <= 2e9)
		printf("%d\n", ans);
	else
		puts("-1");
}