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

ll n, p, A[MAXN], B[MAXN];

bool is_ok(ll x) {
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ll poss = max(0ll, upper_bound(A, A + n, x) - A - ll(i));
	       	ans *= poss;	
		ans %= p;
		if (ans == 0) return false;
		x++;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> p;
	for (int i = 0; i < n; i++) cin >> A[i];
	ll lb = 1;
	sort(A, A + n);
	for (int i = 0; i < n; i++) lb = max(lb, A[i] - i);
		
	if (!is_ok(lb)) return cout << 0 << endl << endl, 0;
	ll L = lb, R = 1e9 + 10;
	while (L < R) {
		ll mid = (L + R + 1) / 2;
		if (is_ok(mid)) L = mid;
		else R = mid - 1;
	}

	cout << R - lb + 1 << endl;
	for (int i = lb; i <= R; i++) cout << i << sep;
	cout << endl;	
	return 0;
}