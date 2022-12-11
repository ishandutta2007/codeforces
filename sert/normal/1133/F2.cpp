#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void dfs_print(int v, const vector<vector<int>> &es, vector<bool> &u) {	
	for (int w: es[v]) {		
		if (!u[w]) {
			cout << v + 1 << " " << w + 1 << "\n";
			u[w] = true;
			dfs_print(w, es, u);
		}
	}
}

void dfs0(int v, const vector<vector<int>> &es, vector<bool> &u) {	
	for (int w: es[v]) {		
		if (!u[w]) {			
			u[w] = true;
			dfs0(w, es, u);
		}
	}
}

void solve() {	
	int n, m, d;
	cin >> n >> m >> d;
	vector<vector<int>> es(n);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}
	
	vector<bool> u(n, false);
	u[0] = true;
	vector<int> nid;
	for (int w: es[0]) {
		if (!u[w]) {
			nid.push_back(w);
			u[w] = true;
			dfs0(w, es, u);
		}
	}

	if (d > (int)es[0].size() || d < (int)nid.size()) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	vector<bool> st(n, false);
	for (int i = 1; i < n; i++) u[i] = false;
	for (int x: nid) u[x] = st[x] = true;
	int cnt = d - (int)nid.size();
	for (int w: es[0]) {
		if (!u[w] && cnt > 0) {
			cnt--;
			u[w] = st[w] = true;
		}
	}
	for (int i = 1; i < n; i++) {
		if (st[i]) {
			cout << "1 " << i + 1 << "\n";
			dfs_print(i, es, u);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}