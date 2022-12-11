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

void dfs(int v, int d, const vector<vector<int>> &es, vector<int> &dep) {
	dep[d] ^= 1;
	for (int w : es[v]) dfs(w, d + 1, es, dep);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> es(n);
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		es[x - 1].push_back(i);
	}
	vector<int> dep(n, 0);
	dfs(0, 0, es, dep);
	cout << accumulate(dep.begin(), dep.end(), 0) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
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