#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
const int LOG = 20;
const int INF = 1e9;
const int OWO = 500;
const int SZ = MAXN/OWO + 2;

struct xtrie {
	vector<int> to[2], mx, mn;
	int sz;
	xtrie() {
		to[0] = {-1};
		to[1] = {-1};
		mn = {INF};
		mx = {-1};
		sz = 1;
	}

	void add(int x, int y) {
		int cur = 0;
		for(int b = LOG - 1; b >= 0; b--) {
			int d = ((1 << b) & x) >> b;
			if(to[d][cur] == -1) {
				to[0].push_back(-1);
				to[1].push_back(-1);
				mn.push_back(INF);
				mx.push_back(-1);
				to[d][cur] = sz++;
			}
			mx[cur] = max(mx[cur], y);
			mn[cur] = min(mn[cur], y);
			cur = to[d][cur];
		}
		mx[cur] = max(mx[cur], y);
		mn[cur] = min(mn[cur], y);
	}

	int maximize(int x, int y, bool le) {
		int cur = 0, ans = 0;
		if(le && y > mx[0])
			return -1;
		if(!le && y < mn[0])
			return -1;
		for(int b = LOG - 1; b >= 0; b--) {
			int d = ((1 << b) & x) >> b;
			if(to[d^1][cur] != -1) {
				int u = to[d^1][cur];
				if((le && y <= mx[u]) || (!le && y >= mn[u])) {
					cur = u;
					ans += (1 << b);
					continue;
				}
			}
			cur = to[d][cur];
		}
		return ans;
	}
};

xtrie fuck[2], me[2];

struct qry {
	int l, r, idx;

	bool operator< (const qry &o) const {
		return r < o.r;
	}
};
vector<qry> qs[SZ];

int n, m, l, r, a[MAXN], big[MAXN], low[MAXN], ans[MAXN];
int glob;

void solve(vector<qry> &queries) {
	sort(queries.begin(), queries.end());
	if(queries.empty())
		return;
	int mxl = -1;
	for(auto q : queries)
		mxl = max(mxl, q.l);
	r = mxl - 1;
	glob = 0;
	fuck[0] = fuck[1] = xtrie();
	for(auto q : queries) {
		int res = 0;
		while(r < q.r) {
			r++;
			fuck[0].add(low[r], a[r]);
			fuck[1].add(big[r], a[r]);
			glob = max(glob, fuck[0].maximize(big[r], a[r], false));
			glob = max(glob, fuck[1].maximize(low[r], a[r], true));
		}
		res = glob;
		me[0] = me[1] = xtrie();
		l = min(mxl, q.r + 1);
		while(l > q.l) {
			l--;
			me[0].add(low[l], a[l]);
			me[1].add(big[l], a[l]);
			res = max(res, me[0].maximize(big[l], a[l], false));
			res = max(res, me[1].maximize(low[l], a[l], true));
			res = max(res, fuck[0].maximize(big[l], a[l], false));
			res = max(res, fuck[1].maximize(low[l], a[l], true));
		}
		ans[q.idx] = res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	auto f = [&](int x) {
		int a = x % 2, b = (x/2) % 2;
		return (a ? 1 : x) + (1 - 2*a)*b;
	};
	for(int i = 1; i <= n; i++) {
		big[i] = f(a[i]);
		low[i] = f(a[i] - 1);
	}
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		qs[l/OWO].push_back({l, r, i});
	}
	for(int i = 0; i < SZ; i++)
		solve(qs[i]);
	for(int i = 0; i < m; i++)
		cout << ans[i] << '\n';
}