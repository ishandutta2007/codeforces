#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int MN = 2005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

struct union_find {
	int rt[MN], cnt[MN];
	
	void init(int n) {
		for (int u = 1; u <= n; u++) {
			rt[u] = u;
			cnt[u] = 1;
		}
	}
	
	int find_rt(int u) {
		if (rt[u] != u) rt[u] = find_rt(rt[u]);
		return rt[u];
	}
	
	bool merge(int u, int v) {
		u = find_rt(u);
		v = find_rt(v);
		if (u == v) return 0;
		if (cnt[u] < cnt[v]) swap(u, v);
		rt[v] = u;
		cnt[u] += cnt[v];
		return 1;
	}
} A;

struct pnt {
	int x, y, a, id;
	void in(int i) {
		cin >> x >> y >> a;
		id = i;
		A.merge(id, a);
	}
} p[MN];

bool cmp(pnt p1, pnt p2) {
	return p1.x < p2.x;
}

bool cmp1(pnt p1, pnt p2) {
	return atan2(p1.y - p[0].y, p1.x - p[0].x) < atan2(p2.y - p[0].y, p2.x - p[0].x);
}

vector<pii> V;

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int pn = 0;
	A.init(n);
	for (int i = 0; i < n; i++) {
		p[i].in(i + 1);
		if (p[i].a != p[i].id) p[pn++] = p[i];
	}
	n = pn;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	sort(p, p + n, cmp);
	sort(p + 1, p + n, cmp1);
	for (int i = 1; i < n - 1; i++) {
		if (A.merge(p[i].a, p[i + 1].a)) {
			swap(p[i].a, p[i + 1].a);
			V.push_back({p[i].id, p[i + 1].id});
		}
	}
	while (p[0].id != p[0].a) {
		for (int i = 1; i < n; i++) if (p[i].id == p[0].a) {
			swap(p[0].a, p[i].a);
			V.push_back({p[0].id, p[i].id});
		}
	}
	for (int i = 0; i < n; i++) assert(p[i].id == p[i].a);
	cout << V.size() << endl;
	for (auto pp : V) cout << pp.first << ' ' << pp.second << endl;

	return 0;

}