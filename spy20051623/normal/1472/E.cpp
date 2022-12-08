#include <bits/stdc++.h>
using namespace std;

struct dt {
	int id, large, small, v;
	operator<(dt x) {
		return small < x.small;
	}
} d[200005];

int cmp1(dt x, dt y) {
	return x.small < y.small;
}

int cmp2(dt x, dt y) {
	return x.id < y.id;
}

map<int, int> m;
queue<int> q;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, p;
	cin >> t;
	while (t--) {
		m.clear();
		while (!q.empty())
			q.pop();
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> d[i].large >> d[i].small;
			d[i].id = i;
			if (d[i].large < d[i].small)
				swap(d[i].large, d[i].small);
		}
		sort(d + 1, d + n + 1, cmp1);
		for (i = 1; i <= n; ++i) {
			d[i].v = -1;
			p = q.front();
			if (!q.empty() && d[i].small > d[p].small) {
				while (!q.empty()) {
					p = q.front();
					q.pop();
					m[d[p].large] = p;
				}
			}
			if (m.size() > 0 && d[m.begin()->second].large < d[i].large) {
				d[i].v = d[m.begin()->second].id;
			}
			q.push(i);
		}
		sort(d + 1, d + n + 1, cmp2);
		for (i = 1; i <= n; ++i) {
			cout << d[i].v << ' ';
		}
		cout << endl;
	}
	return 0;
}