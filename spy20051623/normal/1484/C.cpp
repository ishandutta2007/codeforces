#include <bits/stdc++.h>
using namespace std;

struct dt {
	int id;
	int cnt;
	vector<int> a;
	int c;
};

int cmp1(dt x, dt y) {
	return x.cnt < y.cnt;
}

int cmp2(dt x, dt y) {
	return x.id < y.id;
}

void solve() {
	int n, m, i, j, k, maxm, res;
	bool ok;
	cin >> n >> m;
	vector<dt> d(m + 5);
	vector<int> cnt(n + 5);
	for (i = 1; i <= m; ++i) {
		cin >> j;
		d[i].cnt = j;
		d[i].id = i;
		while (j--) {
			cin >> k;
			d[i].a.push_back(k);
			++cnt[k];
		}
	}
	maxm = 0;
	for (i = 1; i <= n; ++i) {
		if (cnt[i] > cnt[maxm])
			maxm = i;
	}
	sort(d.begin() + 1, d.begin() + m + 1, cmp1);
	res = 0;
	for (i = 1; i <= m; ++i) {
		ok = 0;
		for (j = 0; j < d[i].cnt; ++j) {
			if (maxm == d[i].a[j]) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			if (res + 1 > (m + 1) / 2) {
				if (d[i].cnt == 1) {
					cout << "NO" << endl;
					return;
				} else {
					break;
				}
			}
			++res;
			d[i].c = maxm;
		}
	}
	for (i = 1; i <= m; ++i) {
		if (d[i].c)
			continue;
		else if (d[i].a[0] != maxm)
			d[i].c = d[i].a[0];
		else
			d[i].c = d[i].a[1];
	}
	sort(d.begin() + 1, d.begin() + m + 1, cmp2);
	cout << "YES" << endl;
	for (i = 1; i <= m; ++i)
		cout << d[i].c << ' ';
	cout << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}