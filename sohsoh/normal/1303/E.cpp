#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN];
ll F[MAXN][26], tmp[26];

bool is_ok(string s, string sq1, string sq2) {
	ll n = s.size(), sz1 = sq1.size(), sz2 = sq2.size();
	dp[0][0] = 0;
	for (int i = 0; i <= sz1; i++) {
		for (int j = 0; j <= sz2; j++) {
			if (i == 0 && j == 0) continue;
			dp[i][j] = INF;
			if (i > 0) dp[i][j] = min(dp[i][j], F[dp[i - 1][j]][sq1[i - 1] - 'a'] + 1);
			if (j > 0) dp[i][j] = min(dp[i][j], F[dp[i][j - 1]][sq2[j - 1] - 'a'] + 1);
		}
	}


	if (dp[sz1][sz2] <= n) return true;
	return false;
} 

ll solve() {
	string s, t;
	cin >> s >> t;
	ll n = s.size();
	fill(tmp, tmp + 26, n + 1);
	for (int i = n + 4; i >= 0; i--) {
		if (i < n) tmp[s[i] - 'a'] = i;
		for (int j = 0; j < 26; j++) F[i][j] = tmp[j];
	}

	for (int i = 0; i <= t.size(); i++) {
		string s1 = t.substr(0, i);
		string s2 = t.substr(i, n - i);
		if (is_ok(s, s1, s2)) return cout << "YES" << endl, 0;
	}
	
	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}