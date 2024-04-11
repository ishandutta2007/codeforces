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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}

	return ans;
}

ll ans, inv[MAXN], fact[MAXN], a, b, c, n, A[MAXN], s;
map<int, int> cnt;

inline ll C(ll k, ll n) {
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD; 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) 
		fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		s += A[i];
		cnt[A[i]]++;
	}

	if (s % n) return cout << 0 << endl, 0;
	s /= n;

	ll tot_inv = 1;
	for (pll e : cnt) tot_inv = tot_inv * inv[e.Y] % MOD;

	for (int i = 1; i <= n; i++) {
		A[i] -= s;
		if (A[i] == 0) c++;
		else if (A[i] > 0) a++;
		else b++;
	}

	if (a <= 1 || b <= 1) cout << fact[n] * tot_inv % MOD << endl;
	else cout << C(c, n) * fact[c] % MOD * fact[a] % MOD * fact[b] % MOD * 2 % MOD * tot_inv % MOD << endl;
	return 0;
}