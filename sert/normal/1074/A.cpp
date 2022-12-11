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
	vector<int> a(n), b;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	sort(a.begin(), a.end());
	if (a.empty() || a.back() != 1000000000) {
		a.push_back(1000000000);
	}

	for (int i = 0; i < m; i++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if (x1 == 1) {
			b.push_back(x2);
		}
	}
	sort(b.begin(), b.end());
	int bs = b.size();

	int ans = n + bs + 2;
	int cur = 0;
	for (int i = 0; i <= n; i++) {
		while (cur < bs && b[cur] < a[i]) cur++;
		ans = min(ans, i + bs - cur);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 5;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}