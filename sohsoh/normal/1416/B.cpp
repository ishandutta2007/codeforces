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

ll A[MAXN], n;

ll solve() {
	cin >> n;
	ll s = 0;
	for (int i = 1; i <= n; i++) cin >> A[i], s += A[i];
	if (s % n > 0) return cout << -1 << endl, 0;

	vector<pair<pll, ll>> ans;
	for (int i = 2; i <= n; i++) {
		if (A[i] % i == 0) ans.push_back({{i, 1}, A[i] / i});
		else {
			ll x = i - (A[i] % i);
			ans.push_back({{1, i}, x});
			A[i] += x;
			ans.push_back({{i, 1}, A[i] / i});
		}
	}

	ll x = s / n;
	for (int i = 2; i <= n; i++) ans.push_back({{1, i}, x});
	cout << ans.size() << endl;
	for (pair<pll, ll> e : ans) cout << e.X.X << sep << e.X.Y << sep << e.Y << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}