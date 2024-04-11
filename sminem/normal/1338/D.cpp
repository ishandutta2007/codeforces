#include <bits/stdc++.h>
using namespace std;

struct info {
	int s, b;
};

int n;
basic_string<int> e[100005];
info up[100005], dn[100005];
int p[100005];

void dfs1(int x, int p) {
	int sm = -123123123, bm = -123123123, c = 0;
	::p[x] = p;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		sm = max(sm, dn[y].s);
		bm = max(bm, dn[y].b);
		c++;
	}

	if (c) {
		dn[x].s = 1 + bm;
		dn[x].b = max(sm, bm) + c - 1;
	} else {
		dn[x].s = 1;
		dn[x].b = 0;
	}
}

void dfs2(int x, int p) {
	multiset<int> sms, bms;
	int c = -1;

	sms.insert(-123123123);
	bms.insert(-123123123);

	if (x != p) {
		sms.insert(up[x].s);
		bms.insert(up[x].b);
		c++;
	}

	for (int y : e[x]) {
		if (y == p)
			continue;
		sms.insert(dn[y].s);
		bms.insert(dn[y].b);
		c++;
	}

	for (int y : e[x]) {
		if (y == p)
			continue;
		sms.erase(sms.find(dn[y].s));
		bms.erase(bms.find(dn[y].b));
		up[y].s = 1 + *bms.rbegin();
		up[y].b = max(*sms.rbegin(), *bms.rbegin()) + c - 1;
		sms.insert(dn[y].s);
		bms.insert(dn[y].b);
	}

	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs2(y, x);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v, e[v] += u;
	}

	dfs1(1, 1);
	dfs2(1, 1);
	int sol = max(dn[1].s, dn[1].b);
	for (int i=2; i<=n; i++) {
		int sm = -123123123, bm = -123123123, c = 0;
		for (int y : e[i]) {
			if (y == p[i]) {
				sm = max(sm, up[i].s);
				bm = max(bm, up[i].b);
			} else {
				sm = max(sm, dn[y].s);
				bm = max(bm, dn[y].b);
			}
			c++;
		}

		sol = max({sol, 1 + bm, sm + c - 1, bm + c - 1});
	}

	// for (int i=1; i<=n; i++) {
	// 	cerr << dn[i].s << ' ' << dn[i].b << ' ' << up[i].s << ' ' << up[i].b << '\n';
	// }

	cout << sol << '\n';
}