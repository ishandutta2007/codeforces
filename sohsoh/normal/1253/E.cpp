#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN];
bool B[MAXN] = {false};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	dp[0] = 0;
	ll m, n;
	cin >> n >> m;
	vector<pll> v;
	for (int i = 0; i < n; i++) {
		ll x, s;
		cin >> x >> s;
		ll l = x - s, r = x + s;
		v.push_back({l, r});
		for (int i = max(l, 0ll); i <= min(m, r); i++) B[i] = true;
	}

	for (int i = 1; i <= m; i++) {
		dp[i] = i;
		if (B[i]) dp[i] = min(dp[i], dp[i - 1]);
		for (pll e : v) {
			if (e.Y < i) {
				ll cst = (i - e.Y);
				dp[i] = min(dp[i], dp[max(e.X - cst - 1, 0ll)] + cst);
			}
		}
	}

	cout << dp[m] << endl;
	return 0;
}