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

const ll MAXN = 1e5 + 10;
const ll MAXK = 110;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;
const ll NEG = 105;

ll dp[MAXN][MAXK], tdp[MAXN], ps[MAXN][MAXK], A[MAXN], n, k, len;

inline void mkey(ll& n) {
	if (n >= MOD) n -= MOD;
	if (n < 0) n += MOD;
}

inline void TDP(int i) {
	for (int j = 1; j <= k; j++) 
		mkey(tdp[i] += dp[i][j]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> len;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < MAXK; j++) ps[i][j] = ps[i - 1][j];
		cin >> A[i];
		if (A[i] == -1) A[i] = NEG;
		ps[i][A[i]]++;
	}

	tdp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (A[i] != NEG && j != A[i]) continue;
			mkey(dp[i][j] += tdp[i - 1]);
			if (i >= len && (ps[i][NEG] + ps[i][j] - ps[i - len][NEG] - ps[i - len][j] == len)) {
				mkey(dp[i][j] -= tdp[i - len]);
				mkey(dp[i][j] += dp[i - len][j]);
			}	
		}


		TDP(i);
	}

	cout << tdp[n] << endl;
	return 0;
}