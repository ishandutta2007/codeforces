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

vector<int> ord;
bool u[N];
vector<int> es[N], eo[N];
int comp[N];

void dfs_ts(int v) {
	if (u[v]) return;
	u[v] = true;
	for (int w: es[v]) dfs_ts(w);
	ord.push_back(v);
}

void dfs_back(int v, int cn) {
	if (u[v]) return;
	u[v] = true;
	comp[v] = cn;
	for (int w: eo[v]) dfs_back(w, cn);
}

void solve() {
	int n, m, s;
	cin >> n >> m >> s;
	s--;

	ord.clear();
	for (int i = 0; i < n; i++) {
		u[i] = false;
		es[i].clear();
		eo[i].clear();
		comp[i] = -1;
	}

	vector<pair<int, int>> e;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		eo[v2].push_back(v1);
		e.emplace_back(v1, v2);
	}

	for (int i = 0; i < n; i++) {
		dfs_ts(i);
	}
	for (int i = 0; i < n; i++) {
		u[i] = false;
	}

	int cmp_num = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (u[ord[i]]) continue;
		dfs_back(ord[i], cmp_num++);
	}

	/*for (int i = 0; i < n; i++) {
		cout << comp[i] + 1 << " ";
	}
	cout << "\n";*/
	
	vector<bool> isInner(cmp_num, false);

	for (auto q: e) {
		int v1 = q.first;
		int v2 = q.second;
		if (comp[v1] != comp[v2]) {
			isInner[comp[v2]] = true;
		}
	}

	int ans = 0;
	for (bool isIn: isInner) {
		if (!isIn) {
			ans++;
		}
	}

	if (!isInner[comp[s]]) {
		ans--;
	}

	cout << ans << "\n";	
	//cout << cmp_num << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}