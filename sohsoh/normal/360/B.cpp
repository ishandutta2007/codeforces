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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, dp[MAXN], A[MAXN];

inline bool can(ll c) {
	memset(dp, 0, sizeof dp);
	bool ok = true;
	
	for (int i = 2; i <= n; i++) {
		if (abs(A[i] - A[i - 1]) > c) ok = false;
		if (ok) continue;
		dp[i] = i - 1;
			
		for (int j = 1; j < i; j++) { 
			if (abs(A[i] - A[j]) <= c * (i - j)) {	
				dp[i] = min(dp[i], i - j - 1 + dp[j]);
			}
			
		}
	}

	ll ans = n;
	for (int i = 1; i <= n; i++) ans = min(ans, dp[i] + n - i);
	return ans <= k;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	ll L = 0, R = 4e9;
	while (L < R) {
		ll mid = (L + R) >> 1ll;
		if (can(mid)) R = mid;
		else L = mid + 1;
	}

	cout << L << endl;
	return 0;
}