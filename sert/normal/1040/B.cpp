#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

void solve() {
	int n, k;
	cin >> n >> k;
	int d = k * 2 + 1;
	int ans = INF;
	int bst = -1;

	for (int st = 1; st <= min(n, k + 1); st++) {
		int cur = 1 + (n - st) / d;
		int lst = st + (cur - 1) * d;
		if (n - lst <= k && cur < ans) {
			ans = cur;
			bst = st;
		}
	}

	cout << ans << "\n";
	for (int x = bst; x <= n; x += d) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst++;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}