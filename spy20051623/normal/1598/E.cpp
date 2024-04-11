#include <bits/stdc++.h>

using namespace std;

map<int, set<int>> mp;
int a[1005][1005];

void add(int x, int y, int f) {
	mp[y - x - f].insert(x + y);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i) add(i, 0, 0), add(i, 0, 1);
	for (int i = 1; i <= m; ++i) add(0, i, 0), add(0, i, 1);
	for (int i = 1; i <= n; ++i) add(i, m + 1, 0), add(i, m + 1, 1);
	for (int i = 1; i <= m; ++i) add(n + 1, i, 0), add(n + 1, i, 1);
	long long ans = 0;
	for (auto &it: mp) {
		auto &s = it.second;
		while (*s.begin() + 1 == *++s.begin()) s.erase(s.begin());
		while (*s.rbegin() - 1 == *++s.rbegin()) s.erase(--s.end());
//		if (s.size() < 2) cerr << 1 << endl;
		int num = *s.rbegin() - *s.begin() - 1;
		ans += num * (num + 1) / 2;
	}
	ans -= n * m + 2;
//	cerr << ans << endl;
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (!a[x][y]) {
			int l, r;
			l = *--mp[y - x].lower_bound(x + y);
			r = *mp[y - x].upper_bound(x + y);
			ans -= (r - x - y) * (x + y - l);
			mp[y - x].insert(x + y);
			l = *--mp[y - x - 1].lower_bound(x + y);
			r = *mp[y - x - 1].upper_bound(x + y);
			ans -= (r - x - y) * (x + y - l);
			mp[y - x - 1].insert(x + y);
			++ans;
			a[x][y] = 1;
		} else {
			int l, r;
			l = *--mp[y - x].lower_bound(x + y);
			r = *mp[y - x].upper_bound(x + y);
			ans += (r - x - y) * (x + y - l);
			mp[y - x].erase(x + y);
			l = *--mp[y - x - 1].lower_bound(x + y);
			r = *mp[y - x - 1].upper_bound(x + y);
			ans += (r - x - y) * (x + y - l);
			mp[y - x - 1].erase(x + y);
			--ans;
			a[x][y] = 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}