#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e5 + 10;
const ll MOD = 1e9 + 7;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1; 
	}

	return ans;
}

int n, spf[MAXN];
ll ans, fact[MAXN], inv[MAXN];
vector<int> vec[MAXN];

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

inline void mkay(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		if (spf[i] || i == 1) continue;

		for (int j = i; j < MAXN; j += i)
			if (!spf[j])
				spf[j] = i;
	}

	inv[MAXN - 1] = poww(fact[MAXN - 1], MOD - 2);
	for (int i = MAXN - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % MOD;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int lst = 0, cnt = 0;

		while (x > 1) {
			int p = spf[x];
			if (p == lst) cnt++;
			else {
				if (cnt) vec[lst].push_back(cnt);
				cnt = 1;
			}

			lst = p;
			mkay(ans += poww(2, n - 1));
			x /= p;
		}

		if (cnt) vec[lst].push_back(cnt);
	}

	for (int p = 2; p < MAXN; p++) {
		if (vec[p].empty()) continue;
		sort(all(vec[p]));
		int f = n - int(vec[p].size());

		int ptr = 0;
		for (int i = 0; ptr < int(vec[p].size()); i++) {
			for (int k = 1; ptr + f + k <= n; k++)
				mkay(ans -= k * C(ptr + f + k, n) % MOD);

			while (ptr < int(vec[p].size()) && vec[p][ptr] <= i + 1)
				ptr++;
		}
	}

	cout << ans << endl;
	return 0;
}