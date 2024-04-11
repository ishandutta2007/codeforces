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

vector<ll> ac[MAXN];
ll F[MAXN] = {0};

ll solve() {
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) F[i] = INF;
	for (int i = 1; i <= n; i++) ac[i].push_back(0), ac[i].push_back(n + 1);
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		ac[x].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		sort(all(ac[i]));
		ll dist = 0;
		for (int j = 1; j < ac[i].size(); j++) dist = max(dist, ac[i][j] - ac[i][j - 1]);
		F[dist] = min(F[dist], ll(i));
	}

	ll ans = INF;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, F[i]);
		if (ans > n) cout << -1 << sep;
		else cout << ans << sep;
	}

	for (int i = 0; i < n + 10; i++) ac[i].clear();
	return cout << endl, 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();	
	return 0;
}