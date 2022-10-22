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
 
const ll MAXN = 1e3 + 100;
const ll MAXK = 1e6 + 100;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN], B, n, kk, pref[MAXN], A[MAXN];

void mkey(ll& a) {
	while (a >= MOD) a -= MOD;
	while (a < 0) a+= MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> kk;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	A[0] = -1 * INF;
	B = MAXK / kk + 100;
	ll ans = 0;
	for (int b = 1; b < B; b++) {
		ll prev_ans = ans;
		ll pnt = 0;
		vector<ll> lst;
		lst.push_back(0);
		for (int j = 1; j <= n; j++) {
			while (pnt < j - 1 && A[j] - A[pnt + 1] >= b) pnt++;
			lst.push_back(pnt);
		}
		
		fill(dp[1], dp[1] + MAXN, 0);
		for (int i = 1; i <= n; i++) dp[1][i] = 1;
		pref[0] = 0;
		for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + dp[1][i];
		for (int l = 2; l <= kk; l++) {
			dp[l][0] = 0;
			for (int i = 1; i <= n; i++) dp[l][i] = pref[lst[i]];
			pref[0] = 0;
			for (int i = 1; i <= n; i++) mkey(pref[i] = pref[i - 1] + dp[l][i]);
		}

		for (int i = 0; i <= n; i++) mkey(ans += dp[kk][i]);
		if (ans == prev_ans) break;
	}	

	cout << ans << endl;
	return 0;
}