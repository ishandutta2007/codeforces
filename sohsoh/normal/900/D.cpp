#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 3000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll ans = 0, x, y, dp[MAXN];

ll solve(ll x, ll y) {
	if (y % x) return 0;
	return poww(2, y / x - 1, MOD);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> x >> y;
	vector<ll> P;
	for (int i = 1; i * i <= y; i++) {
		if (y % i) continue;
		P.push_back(i);
		if (i != y / i) P.push_back(y / i);
	}

	sort(all(P));
	int n = P.size();
	for (int i = n - 1; i >= 0; i--) {
		int t = P[i];
		dp[i] = solve(t, y);
		for (int j = i + 1; j < n; j++) 
			if (P[j] % t == 0)
				dp[i] += MOD - dp[j], dp[i] %= MOD;
	}

	if (y % x) return cout << 0 << endl, 0;
	cout << dp[find(all(P), x) - P.begin()] << endl;
	return 0;
}