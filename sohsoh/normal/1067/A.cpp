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
 
const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

ll dp[MAXN][210][2] = {0}, A[MAXN], ps[210][2] = {0};

void mkey(ll& a) {
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	if (A[1] >= 0) dp[1][A[1]][0] = 1;
	else {
		for (int i = 1; i <= 200; i++) dp[1][i][0] = 1;	
	}


	for (int j = 1; j < 210; j++) {
		ps[j][1] = ps[j - 1][1] + dp[1][j][1];
		ps[j][0] = ps[j - 1][0] + dp[1][j][0];
	}

	for (int i = 2; i <= n; i++) {
		if (A[i] >= 0) {
			ll x = A[i];
			mkey(dp[i][x][0] += ps[x - 1][0] + ps[x - 1][1]);
			mkey(dp[i][x][1] += ps[200][1] - ps[x - 1][1]);
			mkey(dp[i][x][1] += dp[i - 1][x][0]);
		} else {
			for (int j = 1; j <= 200; j++) {	
				mkey(dp[i][j][0] += ps[j - 1][0] + ps[j - 1][1]);
				mkey(dp[i][j][1] += ps[200][1] - ps[j - 1][1]);
				mkey(dp[i][j][1] += dp[i - 1][j][0]);	
			} 
		}

		ps[0][0] = ps[1][0] = 0;
		for (int j = 1; j < 210; j++) {
			mkey(ps[j][1] = ps[j - 1][1] + dp[i][j][1]);
			mkey(ps[j][0] = ps[j - 1][0] + dp[i][j][0]);
		}
	}

	cout << ps[200][1] << endl;
	return 0;
}