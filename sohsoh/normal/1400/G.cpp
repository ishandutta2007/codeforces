/*
    Soheil Mohammadkhani
    OK, im back :)
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 3e5 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

ll D[MAXN] = {0}, C[MAXN] = {0};
ll fact[MAXN], inv[MAXN];

ll nCr(ll k, ll n) {
	if (k > n || k < 0) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

pll A[MAXN];
ll ans_arr[MAXN][42] = {0}, ps[42][MAXN] = {0};

int main() {
	fast_io;
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = poww(fact[i], MOD - 2, MOD);
	}
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		D[a]++;
	       	D[b + 1]--;	
		A[i + 1] = {a, b};
	}
	
	vector<pll> v;
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	C[0] = 0;
	for (int i = 1; i <= n; i++) C[i] += D[i] + C[i - 1];
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i, 40); j++) {
			ans_arr[i][j] = nCr(i - j, C[i] - j);
		}	

		ans += ans_arr[i][0];
		ans %= MOD;
	}

	
	for (int k = 0; k <= 40; k++) {
		ps[k][0] = 0;
		for (int i = 1; i <= n; i++) ps[k][i] += ans_arr[i][k] + ps[k][i - 1], ps[k][i] %= MOD;
	}
	
	ll mxx = 1;
	for (int i = 1; i <= m; i++) mxx *= 2;
	for (int i = 1; i < mxx; i++) {
		ll x = 0;
		set<ll> st;
		ll t = i;
		ll j = 0, al = 0;
		while (t > 0) {
			if (t & 1) st.insert(v[j].X), st.insert(v[j].Y), al++;
			j++;
			t /= 2;
		}

		ll mn = st.size(), mx = n;
		for (ll e : st) {
			mn = max(mn, A[e].X);
			mx = min(mx, A[e].Y);
		}
		
		if (mn > mx) continue;

		x = ps[st.size()][mx] - ps[st.size()][mn - 1];
		x += 3 * MOD;
		x %= MOD;	

		if (al & 1) ans -= x;
		else ans += x;
		ans += 3 * MOD;
		ans %= MOD;
	}

	cout << ans % MOD << endl;
	return 0;

}