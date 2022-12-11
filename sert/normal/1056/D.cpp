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

vector<int> es[N];
int sz[N], ans[N];

void dfs(int v) {
	if (es[v].empty()) sz[v] = 1;
	else sz[v] = 0;

	for (int w: es[v]) {
		dfs(w);
		sz[v] += sz[w];
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		es[i].clear();
		sz[i] = 0;
		ans[i] = 0;
	}

	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		es[p - 1].push_back(i);
	}

	dfs(0);	
	sort(sz, sz + n);	

	/*for (int i = 0; i < n; i++) {
		ans[sz[i]] = i + 1;
	}

	for (int i = 1; i <= n; i++) ans[i] = max(ans[i], ans[i - 1]);*/

	for (int i = 1; i <= n; i++) {
		cout << sz[i - 1] << " ";
	}
	cout << "\n";
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