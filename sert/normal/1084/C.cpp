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
	string s;
	cin >> s;
	int n = s.length();
	vector<int> dp(n + 1, 0);
	int lst = -1;
	for (int i = 1; i <= n; i++) {	
		if (s[i - 1] == 'b') lst = i;			
		if (s[i - 1] == 'a') dp[i] = (dp[i - 1] + (lst == -1 ? 0 : dp[lst]) + 1) % MD;
		else dp[i] = dp[i - 1];
	}
	cout << dp[n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
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