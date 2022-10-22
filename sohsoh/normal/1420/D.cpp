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
const ll MOD = 998244353; // 1e9 + 9;
const ll LOG = 40;

ll fact[MAXN] = {0}, inv[MAXN] = {0};

ll C(ll r, ll n) {
	if (r == 0) return 1;
	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

vector<pll> v;
vector<ll> points;
map<ll, ll> mp;
ll n, k;

ll op[MAXN] = {0}, clos[MAXN] = {0};

void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2, MOD) % MOD;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		points.push_back(l);
		points.push_back(r);
		v.push_back({l, r});
	}

	sort(all(points));
	ll ind = 1;
	for (ll e : points) {
		if (mp.find(e) == mp.end()) mp.insert({e, ind++});
	}

	for (int i = 0; i < n; i++) {
		v[i].X = mp[v[i].X];
		v[i].Y = mp[v[i].Y];
		op[v[i].X]++;
		clos[v[i].Y]++;
	}

	ll cnt = 0;
	ll ans = 0;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < op[i]; j++) {
			if (cnt + 1 >= k) mkey(ans += C(k - 1, cnt));	
			cnt++;
		}

		cnt -= clos[i];
	}

	cout << ans % MOD << endl;
	return 0;
}