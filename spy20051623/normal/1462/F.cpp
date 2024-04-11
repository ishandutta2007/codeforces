#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
pair<int, int> p[200005];
int cnt;

struct dt {
	int d[400005];
	int lowbit(int x) {
		return x & (-x);
	}

	void update(int x, int k) {
		for (int i = x; i <= cnt; i += lowbit(i))
			d[i] += k;
	}

	int sum(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			res += d[i];
		return res;
	}
} l, r;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j, maxm;
	cin >> t;
	while (t--) {
		cin >> n;
		m.clear();
		for (i = 0; i < n; ++i) {
			cin >> p[i].first >> p[i].second;
			m[p[i].first];
			m[p[i].second];
		}
		cnt = 1;
		for (auto &it : m) {
			it.second = cnt;
			++cnt;
		}
		for (i = 0; i < n; ++i) {
			p[i].first = m[p[i].first];
			p[i].second = m[p[i].second];
			l.update(p[i].first, 1);
			r.update(p[i].second, 1);
		}
		maxm = 0;
		for (i = 0; i < n; ++i) {
			j = l.sum(p[i].second) - r.sum(p[i].first - 1);
			if (j > maxm)
				maxm = j;
		}
		cout << n - maxm << endl;
		memset(l.d, 0, sizeof(int) * (cnt + 5));
		memset(r.d, 0, sizeof(int) * (cnt + 5));
	}
	return 0;
}