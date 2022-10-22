#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 18 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll dp[MAXN][MAXN];
ll n, tpow[MAXN];
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	reverse(all(s));
	dp[0][0] = {0, 4};
	tpow[0] = 1;
	for (int i = 1; i <= 18; i++) tpow[i] = tpow[i - 1] * 10ll;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i + j == 0) continue;
			dp[i][j] = {0, 1};
			if (i > 0) dp[i][j] = max(dp[i][j], {dp[i - 1][j].X + int(s[i + j - 1] - '0') * tpow[i - 1], 1});
			if (j > 0) dp[i][j] = max(dp[i][j], {dp[i][j - 1].X + int(s[j + i - 1] - '0') * tpow[j - 1], 2});
		}
	}

	
	string ans;
	ll i = n, j = n;
	while (i + j) {
		if (dp[i][j].Y == 1) i--, ans.push_back('H');
		else j--, ans.push_back('M');
	}

	cout << ans << endl;
	return 0;
}