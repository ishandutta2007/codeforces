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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<vector<int>> pr(n, vector<int>(5, -1));

	for (int i = 0; i < 5; i++) pr[0][i] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (pr[i - 1][k] == -1) continue;
				if (a[i - 1] < a[i] && k < j) pr[i][j] = k;
				if (a[i - 1] > a[i] && k > j) pr[i][j] = k;
				if (a[i - 1] == a[i] && k != j) pr[i][j] = k;
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (pr[i][j] != -1) cout << " ";
			cout << pr[i][j] << " ";
		}
		cout << "\n";
	}*/

	int p = -1;
	for (int i = 0; i < 5; i++) {
		if (pr[n - 1][i] != -1)
			p = i;
	}

	if (p == -1) {
		cout << "-1\n";
		return;
	}
	vector<int> ans = {p};

	for (int i = n - 1; i > 0; i--) {
		p = pr[i][p];
		ans.push_back(p);
	}
	reverse(ans.begin(), ans.end());
	for (auto x: ans) cout << x + 1 << " ";
	cout << endl;
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