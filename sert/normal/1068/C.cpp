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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	int cur = n;
	for (int i = 0; i < n; i++) {
		a[i].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		a[v1].push_back(cur);
		a[v2].push_back(cur);
		cur++;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i].size() << "\n";
		for (int j = 0; j < (int)a[i].size(); j++) {
			cout << i + 1 << " " << a[i][j] + 1 << "\n";
		}
	}
}

int main() {
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