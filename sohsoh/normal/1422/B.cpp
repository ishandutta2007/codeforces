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
 
const ll MAXN = 1e2 + 10; // changed
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, A[MAXN][MAXN];
bool B[MAXN][MAXN];

ll solve() {	
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> A[i][j], B[i][j] = false;
	ll ind = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (B[i][j]) continue;
			B[i][j] = B[i][m - j - 1] = B[n - i - 1][j] = B[n - i - 1][m - j - 1] = true;
			set<pll> st;
			st.insert({i, j});
			st.insert({n - i - 1, j});
			st.insert({i, m - j - 1});
			st.insert({n - i - 1, m - j - 1});
			ll tans = INF;
			for (pll e : st) {
				ll xans = 0;
				for (pll e2 : st) {
					xans += abs(A[e2.X][e2.Y] - A[e.X][e.Y]);
				}

				tans = min(tans, xans);
			}

			ans += tans;
		}
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}