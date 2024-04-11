#include <bits/stdc++.h>

using namespace std;
struct dt {
	int x, y, id;
} p[10000];
int a[10000];

void solve() {
	int n;
	cin >> n;
	map<int, int> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i].x = a[i];
		p[i].id = i;
		++s[a[i]];
	}
	sort(p + 1, p + n + 1, [&](dt &x, dt &y) { return x.x < y.x; });
	for (int i = 1; i <= n; ++i) p[i].y = i;
	sort(p + 1, p + n + 1, [&](dt &x, dt &y) { return x.id < y.id; });
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (p[j].y < p[i].y) ++cnt;
		}
	}
	if ((cnt & 1) && s.size() == n) {
		cout << "-1\n";
		return;
	}
	if (cnt & 1) {
		for (auto i: s) {
			if (i.second == 1) continue;
			int x = -1, y = -1;
			for (int j = 1; j <= n; ++j) {
				if (p[j].x == i.first) {
					if (x == -1) x = j;
					else {
						y = j;
						break;
					}
				}
			}
			swap(p[x].y, p[y].y);
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = p[i].y;
	}
	vector<int> op;
	for (int i = 1; i <= n; ++i) {
		int pos = -1;
		for (int j = i; j <= n; ++j) {
			if (a[j] == i) {
				pos = j;
				break;
			}
		}
		for (int j = pos; j - 2 >= i; j -= 2) {
			op.push_back(j - 2);
			swap(a[j], a[j - 1]);
			swap(a[j - 1], a[j - 2]);
		}
		if (pos - i & 1) {
			op.push_back(i);
			op.push_back(i);
			swap(a[i], a[i + 1]);
			swap(a[i + 1], a[i + 2]);
		}
	}
	cout << op.size() << '\n';
	for (int i: op) cout << i << ' ';
	cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}