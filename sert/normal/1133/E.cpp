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

void mxe(int &a, int b) {
	if (b > a) a = b;
}

void solve() {	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> nx5(n + 1);
	a.push_back(a.back() + 10);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		while (a[cur] <= a[i] + 5) cur++;
		nx5[i] = cur;
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int t = 0; t <= k; t++) {
			int curDp = dp[i][t];			
			mxe(dp[i + 1][t], curDp);
			mxe(dp[nx5[i]][t + 1], curDp + nx5[i] - i);
		}
	}

	int ans = 0;
	for (int t = 0; t <= k; t++) {
		mxe(ans, dp[n][t]);
	}

	cout << ans << "\n";
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