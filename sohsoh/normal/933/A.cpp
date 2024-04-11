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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll mx1[MAXN] = {0}, dp[MAXN][4] = {0};
vector<ll> A;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	A.push_back(0);
	vector<pll> v;
	ll cnt = 0, prv = 0;
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x != prv) {
			if (cnt > 0) {
				v.push_back({cnt, prv});
				cnt = 0;
			}

			prv = x;
		}

		cnt++;
		A.push_back(x);
	}

	v.push_back({cnt, prv}); cnt = 0;
	n = v.size();
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i].Y == 1 && v[j].Y == 2) ans = max(ans, v[i].X + v[j].X);
		}

		if (i > 0) mx1[i] = mx1[i - 1];
		if (v[i].Y == 1) mx1[i] = max(mx1[i], v[i].X);
	}	
	
	for (int i = 1; i < A.size(); i++) {
		ll tcnt = 0, ocnt = 0;	
		
		for (int k = 0; k <= i; k++) {
			if (A[k] == 1) ocnt++;
			if (A[k] == 2) tcnt++;
		}

		for (int j = 0; j <= i; j++) {	
			if (A[j] == 1) ocnt--;
			if (A[j] == 2) tcnt--;
			dp[i][0] = max(dp[i][0], ocnt);
			dp[i][1] = max(dp[i][1], dp[j][0] + tcnt);
			dp[i][2] = max(dp[i][2], dp[j][1] + ocnt);
			dp[i][3] = max(dp[i][3], dp[j][2] + tcnt);
			ans = max(ans, dp[i][3]);
		}
	}

	cout << ans << endl;
	return 0;
}