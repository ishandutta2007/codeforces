#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int C[MAXN], par[MAXN], sz[MAXN], opt[MAXN], n, m, q, shit;
stack<pll> hist;
pll E[MAXN];
bool flag;

pll find(int v) {
	if (v == par[v]) return {v, 0};
	pll ans = find(par[v]);
	ans.Y ^= C[v];
	return ans;
}

inline int unite(int ind) {
	int u = E[ind].X, v = E[ind].Y;
	int cu, cv;
	tie(u, cu) = find(u);
	tie(v, cv) = find(v);

	if (v == u) {
		if (cv != cu) {
			hist.push({-2, -2});
			return 2;
		} else { 
			hist.push({-1, -1});
			shit++;
			return 1;
		}
	}

	if (sz[u] < sz[v]) swap(v, u);
	par[v] = u;
	sz[u] += sz[v];
	C[v] = cv ^ cu ^ 1;
	hist.push({v, u});
	return 0;
}

inline void rollback(int cnt) {
	while (cnt > 0 && !hist.empty()) {
		int v = hist.top().X, u = hist.top().Y;
		cnt--;
	
		hist.pop();
		if (v == -1) shit--;
		if (v < 0) continue;
		
		par[v] = v;
		sz[u] -= sz[v];
		C[v] = 0;
	}
}

void solve(int l = 1, int r = m, int optl = 0, int optr = m + 1) {
	if (r < l) return;
	int mid = (l + r) >> 1;

	for (int i = l; i < mid; i++)
		unite(i);

	// min, max -> opt
	
	if (shit) opt[mid] = optr; // +1 ? fd 
	else {
		opt[mid] = optr;
		while (opt[mid] >= optl) {
			if (unite(opt[mid]) == 1) {
				rollback(1);
				break;
			}

			opt[mid]--;
		}

		if (opt[mid] < optl) flag = true;
	}

	rollback(optr - opt[mid]);
	unite(mid);
	solve(mid + 1, r, opt[mid], optr);
	
	rollback(mid - l + 1);
	for (int i = opt[mid] + 1; i <= optr; i++)
		unite(i);
	
	solve(l, mid - 1, optl, opt[mid]);
	rollback(optr - opt[mid]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n >> m >> q;
	for (int i = 0; i < MAXN; i++) {
		par[i] = i;
		sz[i] = 1;
	}

	for (int i = 1; i <= m; i++)
		cin >> E[i].X >> E[i].Y;

	E[m + 1] = {MAXN - 1, MAXN - 2};
	solve();

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (flag || r >= opt[l] ? "NO" : "YES") << endl;
	}
	return 0;
}