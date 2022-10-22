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

ll ans[MAXN] = {0};
bool prime[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(prime, prime + MAXN, true);

	for (ll p = 2; p * p < MAXN; p++) {
		if (prime[p]) for (ll i = p * p; i < MAXN; i += p) prime[i] = false;
	}

	ll cnt = 0;
	for (int i = 2; i < MAXN; i++) {
		if (prime[i]) cnt++;
		ll sq = sqrt(i);
		if (sq * sq == i && prime[sq]) cnt--;
		ans[i] = cnt;
	}
	
	ll q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		cout << ans[n] + 1 << endl;
	}
	return 0;
}