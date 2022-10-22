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

ll tree[MAXN] = {0}, A[MAXN];

void add(ll ind, ll diff) {
	for (++ind; ind < MAXN; ind += ind & -ind) tree[ind] += diff;
}

void range_update(ll l, ll r, ll diff) {
	add(l, diff);
	add(r + 1, -diff);
}

ll point(ll ind) {
	ll ans = 0;;
	for (++ind; ind > 0; ind -= ind & -ind) ans += tree[ind];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i], range_update(i, i, A[i]);
	ll diff = 0;
	for (int i = 0; i < n - 1; i++) diff += max(A[i + 1] - A[i], 0ll);
	
	ll alpha = (diff + A[0]) / 2;
	cout << max(alpha, diff + A[0] - alpha) << endl;

	cin >> q;
	while (q--) {
		ll l, r, x;
		cin >> l >> r >> x;
		l--; r--;

		ll pl = point(l), pr = point(r);
		range_update(l, r, x);
	
		if (l > 0) {
			diff -= max(pl - point(l - 1), 0ll);
			diff += max(point(l) - point(l - 1), 0ll);
		}

		if (r < n - 1) {
			diff -= max(point(r + 1) - pr, 0ll);
			diff += max(point(r + 1) - point(r), 0ll);
		} 
		
		alpha = (point(0) + diff) / 2;
		cout << max(alpha, point(0) + diff - alpha) << endl;	
	}
	return 0;
}