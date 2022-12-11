#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e5 + 34;
const int M = 12;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

inline void mxe(int &a, int b) {
	if (b > a) a = b;
}

int dp[5001][501];
int solve(int n, int k, const vector<int> &h) {
	if (n == 0 || k == 0) return 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = -INF;
		}
	}

	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			int curDp = dp[i][j];
			if (curDp == -INF) continue;

			for (int x = 0; x < (int)h.size() && i + x <= n; x++) {
				mxe(dp[i + x][j + 1], curDp + h[x]);
			}
		}
	}

	int ans = -INF;
	for (int i = 0; i <= n; i++) {
		mxe(ans, dp[i][k]);
	}

	return ans;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> num(N, 0);
	for (int i = 0; i < n * k; i++) {
		int x;
		cin >> x;
		num[x]++;
	}
	vector<int> chel(N, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		chel[x]++;
	}

	vector<int> h(k + 1, 0);
	for (int i = 0; i < k; i++) {
		cin >> h[i + 1];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += solve(num[i], chel[i], h);
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
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}