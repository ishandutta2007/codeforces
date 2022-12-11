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

vector<int> getZ(string s) {
	vector<int> z(s.length(), 0);
	int l = 0, r = 0;
	for (int i = 1; i < (int)s.length(); i++) {
		z[i] = min(max(0, r - i), z[i - l]);
		while (i + z[i] < (int)s.length() && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r) {
			r = i + z[i];
			l = i;
		}
	}
	return z;
}

inline void mne(int &a, int b) {
	if (b < a) a = b;
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	vector<vector<int>> z;
	for (int i = 0; i < n; i++) {
		z.push_back(getZ(s.substr(i, n - i)));
	}

	vector<int> dp(n + 1, INF);
	dp[0] = 0;

	for (int len = 0; len < n; len++) {
		mne(dp[len + 1], dp[len] + a);

		int maxSubLen = 0;
		for (int i = 0; i < len; i++) {
			maxSubLen = max(maxSubLen, min(len - i, z[i][len - i]));
		}
		mne(dp[len + maxSubLen], dp[len] + b);
	}

	cout << dp[n] << "\n";
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