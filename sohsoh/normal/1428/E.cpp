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

ll val(ll n, ll k) {
	ll p1 = (n / k) * (n / k) * (k - (n % k));
	ll p2 = (n / k + 1) * (n / k + 1) * (n % k);
	return p1 + p2;
}

ll one_more(ll n, ll k) {
	return val(n, k) - val(n, k + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, k, ans = 0;
	cin >> n >> k;
	priority_queue<pair<ll, pll>> pq; // red, n, k
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		pq.push({one_more(x, 1), {x, 1}});
		ans += x * x;
	}

	k -= n;
	while (k--) {
		pair<ll, pll> p = pq.top();
		pq.pop();
		ans -= p.X;
		pq.push({one_more(p.Y.X, p.Y.Y + 1), {p.Y.X, p.Y.Y + 1}});
	}

	cout << ans << endl;
	return 0;
}