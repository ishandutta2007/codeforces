//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e6 + 6;

int read() { int x; scanf("%d", &x); return x; }

map<int, vector<pair<int, int>>> queries;

int cnt, mn[N << 2], ch[N << 2], res[N];

void build(int v = 1, int b = 0, int e = cnt) {
	mn[v] = 0;
	ch[v] = 0;
	if (b + 1 == e) {
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
}

void update(int i, int j, int x, int v = 1, int b = 0, int e = cnt) {
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
		ch[v] += x;
		mn[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	mn[v] = mn[l] + mn[r] + ch[v];
}

int query(int i, int j, int c = 0, int v = 1, int b = 0, int e = cnt) {
	c += ch[v];
	if (i >= e || b >= j)
		return 1e9;
	if (i <= b && e <= j) {
		return mn[v] + c;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	return min(query(i, j, c, l, b, m), query(i, j, c, r, m, e));
}

void solve(int x) {
	vector<pair<int, int>> q = queries[x], add = queries[x];
	sort(q.begin(), q.end());
	cnt = q.size();
	build();
	rep(i, (int) add.size()) {
		auto p = add[i];
		int pl = lower_bound(q.begin(), q.end(), p) - q.begin();
//		cout << p.first << ' ' << pl << endl;
		if (p.second > 0) {
			if (p.second == 1)
				update(pl, cnt, 1);
			else
				update(pl, cnt, -1);
		} else {
			int id = p.second * -1;
			int val = max(0, query(pl, pl + 1));
			int lft = min(0, max(0, query(0, pl + 1)));
			res[id] = val - lft;
		}
	}
}

int32_t main() {
//	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> to_handle;
	int n = read();
	int q = 0;
	rep(i, n) {
		int c = read(), t = read(), x = read();
		if (c == 3) {
			to_handle.push_back(x);
			queries[x].push_back({t, -q}); q++;
		} else {
			to_handle.push_back(x);
			queries[x].push_back({t, c});
		}
	}
	sort(to_handle.begin(), to_handle.end());
	for (int i = 0; i < to_handle.size(); ++i)
		if (!i || to_handle[i - 1] != to_handle[i])
			solve(to_handle[i]);
	rep(i, q)
		printf("%d\n", res[i]);
}