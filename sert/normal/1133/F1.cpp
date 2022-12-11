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

void dfs(int v, const vector<vector<int>> &es, vector<bool> &u) {	
	for (int w: es[v]) {		
		if (!u[w]) {
			cout << v + 1 << " " << w + 1 << "\n";
			u[w] = true;
			dfs(w, es, u);
		}
	}
}

void solve() {	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> es(n);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}
	int mx = 0;
	for (int i = 1; i < n; i++) {
		if ((int)es[i].size() > (int)es[mx].size()) {
			mx = i;
		}
	}

	vector<bool> u(n, false);
	u[mx] = true;	
	for (int w: es[mx]) {
		cout << mx + 1 << " " << w + 1 << "\n";
		u[w] = true;
	}

	for (int w: es[mx]) {
		dfs(w, es, u);
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
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}