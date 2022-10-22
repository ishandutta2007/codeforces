// Sohsoh84 :)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e5 + 10;
const ll MOD = 998244353;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

ll fact[MAXN], inv[MAXN], n;

inline ll C(ll k, ll n) {
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

inline int solve() {
	ll cnt = 0, tot = 0;
	cin >> n;
	ll tn = n;

	string s;
	cin >> s;
	for (int i = 0; i < tn; i++) {
		if (s[i] == '0') {
			tot += cnt - (cnt % 2);
			n -= cnt;
			cnt = 0; 
		}

		if (s[i] == '1') cnt++;
	}

	tot += cnt - (cnt % 2);
	n -= cnt;
	
	tot /= 2;
	cout << C(tot, tot + n) << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = poww(fact[i], MOD - 2);
	}

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}