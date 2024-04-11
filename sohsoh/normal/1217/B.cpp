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
const ll LOG = 20;

ll n, x, A[MAXN], B[MAXN];

ll solve() {
	cin >> n >> x;
	ll b_s = 0;
	for (int i = 0; i < n; i++) cin >> A[i] >> B[i], b_s = max(b_s, A[i] - B[i]);
	if (b_s <= 0 && *max_element(A, A + n) < x) return cout << -1 << endl, 0;
	ll mx = *max_element(A, A + n);
	cout << max(0ll, ll(ceil(ld(x - mx) / ld(b_s)))) + 1 << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}