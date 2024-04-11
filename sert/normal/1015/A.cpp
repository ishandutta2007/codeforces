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
	map<int, int> dx;
	vector<int> ans;

	while (n--) {
		int l, r;
		cin >> l >> r;
		dx[l]++;
		dx[r + 1]--;
	}

	int bal = 0;
	for (int i = 1; i <= m; i++) {
		bal += dx[i];
		if (bal == 0) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
#ifdef MADE_BY_SERT
	D = true;	
	while (!cin.eof()) {
		solve();
	}
#else
	solve();
#endif
}