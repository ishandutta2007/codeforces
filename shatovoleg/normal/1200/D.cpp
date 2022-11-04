#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
void run();
 
signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}
 
struct SegTree {
	int n;
	vector<int> tree;
	vector<int> add;
 
	SegTree(int sz) : n(sz) {
		while (n & (n - 1)) {
			++n;
		}
		tree.resize(2 * n - 1, 0);
		add.resize(2 * n - 1, 0);
	}
 
	void plus(int v, int tl, int tr, int l, int r, int val) {
		push(v, tl, tr);
		if (tl >= r || tr <= l) {
			return;
		}
		if (tl >= l && tr <= r) {
			add[v] += val;
			push(v, tl, tr);
			return;
		}
		int mid = (tl + tr) >> 1;
		plus(2 * v + 1, tl, mid, l, r, val);
		plus(2 * v + 2, mid, tr, l, r, val);
		recalc(v, tl, tr);
	}
 
	int query(int v, int tl, int tr, int l, int r) {
		push(v, tl, tr);
		if (tl >= r || tr <= l) {
			return -INF;
		}
		if (tl >= l && tr <= r) {
			return tree[v];
		}
		int mid = (tl + tr) >> 1;
		int q1 = query(2 * v + 1, tl, mid, l, r);
		int q2 = query(2 * v + 2, mid, tr, l, r);
		return max(q1, q2);
	}
 
	void plus(int l, int r, int val) {
		plus(0, 0, n, l, r, val);
	}
 
	int query(int l, int r) {
		return query(0, 0, n, l, r);
	}
 
	void push(int v, int l, int r) {
		if (!add[v]) {
			return;
		}
		int a = add[v];
		add[v] = 0;
		tree[v] += a;
		if (r - l > 1) {
			add[2 * v + 1] += a;
			add[2 * v + 2] += a;
		}
	}
 
	void recalc(int v, int l, int r) {
		tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
	}
};
 
void run() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> fld(n, vector<int>(n));
	for (auto &v : fld) {
		for (auto &x : v) {
			char c;
			cin >> c;
			if (c == 'W') {
				x = 0;
			} else {
				x = 1;
			}
		}
	}
	pii kek_val = mp(INF, -INF);
	vector<pii> col(n, kek_val), row(n, kek_val);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (fld[i][j]) {
				cmin(row[i].first, j);
				cmax(row[i].second, j);
				cmin(col[j].first, i);
				cmax(col[j].second, i);
			}
		}
	}
	int N = n - k + 1;
	vector<vector<int>> add(N + 1, vector<int>(N + 1));
	for (int i = 0; i < n; ++i) {
		if (col[i] == kek_val) {
			++add[0][0];
			--add[0][N];
			--add[N][0];
			++add[N][N];
		} else if (col[i].second - col[i].first <= k - 1) {
			int cl = i - k + 1, cr = i + 1;
			cmax(cl, 0);
			cmin(cr, N);
			int r = col[i].first + 1, l = col[i].second - k + 1;
			cmax(l, 0);
			cmin(r, N);
			++add[cl][l];
			--add[cl][r];
			--add[cr][l];
			++add[cr][r];
		}
		if (row[i] == kek_val) {
			++add[0][0];
			--add[0][N];
			--add[N][0];
			++add[N][N];
		} else if (row[i].second - row[i].first <= k - 1) {
			int rl = i - k + 1, rr = i + 1;
			cmax(rl, 0);
			cmin(rr, N);
			int r = row[i].first + 1, l = row[i].second - k + 1;
			cmax(l, 0);
			cmin(r, N);
			++add[l][rl];
			--add[l][rr];
			--add[r][rl];
			++add[r][rr];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			add[i][j] += add[i][j - 1];
		}
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			add[i][j] += add[i - 1][j];
		}
	}
	int ans = 0;
	for (auto &l : add) {
		for (auto &x : l) {
			cmax(ans, x);
		}
	}
	cout << ans << endl;
}