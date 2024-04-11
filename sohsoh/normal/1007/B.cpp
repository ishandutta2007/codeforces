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

ll spf[MAXN], div_cnt[MAXN];
ll num_div(ll x) {
	map<ll, ll> div_mp;
	while (x > 1) {
		ll y = spf[x];
		if (div_mp.find(y) == div_mp.end()) div_mp.insert({y, 0});
		div_mp[y]++;
		x /= y;
	}

	ll ans = 1;
	for (pll e : div_mp)
		ans *= (e.Y + 1);

	return ans;
}

ll p[6][3] = {
	{0, 1, 2},
	{0, 2, 1},
	{1, 0, 2},
	{1, 2, 0},
	{2, 0, 1},
	{2, 1, 0}
};

ll solve() {
	ll x, y, z;
	cin >> x >> y >> z;
	ll ans = 0, ans2 = 0;
	ll g[8] = {0, div_cnt[x], div_cnt[y], div_cnt[__gcd(x, y)], div_cnt[z], div_cnt[__gcd(x, z)], div_cnt[__gcd(y, z)], div_cnt[__gcd(__gcd(x, y), z)]};
	
	for (int msk = 1; msk < 1 << 6; msk++) {
		ll xx = 0, yy = 0, zz = 0;
		for (int i = 0; i < 6; i++) {
			if (msk & (1ll << i)) {
				xx |= (1 << p[i][0]);
				yy |= (1 << p[i][1]);
				zz |= (1 << p[i][2]);
			}
		}
		
		ll delta1 = g[xx] * g[yy] * g[zz], delta2 = g[xx | yy] * g[zz];
		if (__builtin_popcount(msk) % 2 == 1) {
			ans += delta1;
			ans2 += delta2;
		} else {
			ans -= delta1;
			ans2 -= delta2;
		}
	} 
	
	ans += 2 * g[7];
	cout << (ans + 3 * ans2) / 6 << endl;
	return 0;
}
	
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	spf[1] = 1;
	for (ll i = 2; i < MAXN; i++) spf[i] = i;
	for (ll i = 4; i < MAXN; i += 2) spf[i] = 2;
       	for (ll i = 3; i * i < MAXN; i++) 
		if (spf[i] == i)
			for (ll j = i * i; j < MAXN; j += i)
				if (spf[j] == j) spf[j] = i;	
	
	for (int i = 1; i < MAXN; i++) div_cnt[i] = num_div(i);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}