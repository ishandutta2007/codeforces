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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN], pref_mx[MAXN] = {0}, X[MAXN], Y[MAXN], T[MAXN], n, r;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> r >> n;
	dp[0] = 0;
	X[0] = Y[0] = 1;
	T[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = -1 * INF;
		cin >> T[i] >> X[i] >> Y[i];
		if (i > 2 * r + 5) dp[i] = pref_mx[i - 2 * r - 5] + 1;
		for (int j = max(i - 2 * r - 6, 0ll); j < i; j++) {
			if (T[i] - T[j] >= abs(X[i] - X[j]) + abs(Y[i] - Y[j])) dp[i] = max(dp[i], dp[j] + 1);
		}

		pref_mx[i] = max(pref_mx[i - 1], dp[i]);
	}

	debug(dp[0])

	cout << *max_element(dp, dp + n + 1) << endl;
	return 0;
}