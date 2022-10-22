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
 
const ll MAXN = 1e3 + 10;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

// for B: 0: not set, 1: (, 2: )

ll P[MAXN], B[MAXN], n, m, k, dp[MAXN][MAXN], len;

// dp[i][j]: index i, balance j

void ovf(ll& x) {
	x = min(x, INF);
}

ll calc() {
	if (B[0] == 2) return 0;	
	for (int i = 0; i <= len + 10; i++) for (int j = 0; j <= len + 10; j++) dp[i][j] = 0;
	dp[0][1] = 1;
	for (int i = 1; i < len; i++) {
		for (int j = 0; j <= len; j++) {
			if ((B[i] == 0 || B[i] == 1) && j > 0) ovf(dp[i][j] += dp[i - 1][j - 1]);
			if (B[i] == 0 || B[i] == 2) ovf(dp[i][j] += dp[i - 1][j + 1]);
		}
	}

	return dp[len - 1][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	fill(P, P + MAXN, INF);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ll x;
			cin >> x;
			P[i + j] = min(P[i + j], x);			
		}
	}

	len = n + m - 1;
	
	for (int t = 0; t < len; t++) {
		ll mn_ind = -1;
		for (int i = 0; i < len; i++) if (B[i] == 0 && (mn_ind < 0 || P[i] < P[mn_ind])) mn_ind = i;
		B[mn_ind] = 1;
		ll x = calc();
		if (x < k) {
			k -= x;
			B[mn_ind] = 2;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (B[i + j] == 1) cout << '(';
			else cout << ')';
		}

		cout << endl;
	}
	return 0;
}