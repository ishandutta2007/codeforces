#include <bits/stdc++.h>
 
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef long long ll;
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
 
const ll MAXN = 92 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool is_in[MAXN] = {false};
ll dp[90][2] = {0};
vector<ll> fib;

ll solve() {
	for (int i = 0; i < 90; i++) dp[i][0] = dp[i][1] = 0;
	ll n;
	cin >> n;
	memset(is_in, false, sizeof is_in);
	for (int i = fib.size() - 1; i >= 0; i--) {
		if (n >= fib[i]) n -= fib[i], is_in[i + 1] = true;
	}

	if (n) return cout << 0 << endl, 0;
	dp[0][1] = 1, dp[0][0] = 0;
	ll lst1 = 0;
	for (int i = 1; i < 90; i++) {
		if (is_in[i]) {
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
			if (!is_in[i - 1] && i > 2) dp[i][0] = ((i - lst1) >> 1ll) * dp[lst1][0] + ((i - lst1 - 1) >> 1ll) * dp[lst1][1];
		
			lst1 = i;
		} else {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		}
	}


	cout << dp[89][0] << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fib.push_back(1);
	fib.push_back(2);
	while (fib.back() < INF) fib.push_back(fib.back() + fib[fib.size() - 2]);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}