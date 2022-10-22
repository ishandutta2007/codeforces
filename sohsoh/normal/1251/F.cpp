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

const ll MAXN = (1 << 19);
const ll MOD = 998244353;
const ll ROOT = 3;

int cnt[MAXN], n, k, q, rev[MAXN], Q[MAXN];
ll fact[MAXN], pw[MAXN], inv[MAXN], A[MAXN], B[MAXN], ans[MAXN];
vector<int> T;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

inline void NTT(ll* A, int n, bool inv) {
	int lg = __builtin_ctz(n);
	for (int i = 1; i < n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
		if (rev[i] < i) swap(A[i], A[rev[i]]);
	}

	for (int len = 1; len < n; len <<= 1) {
		ll wn = poww(ROOT, MOD / 2 / len);
		if (inv) wn = poww(wn, MOD - 2);

		for (int i = 0; i < n; i += len * 2) {
			ll w = 1;
			for (int j = i; j < i + len; j++) {
				ll x = A[j], y = w * A[j + len] % MOD;
				A[j] = (x + y) % MOD;
				A[j + len] = (x - y + MOD) % MOD;
				w = w * wn % MOD;
			}
		}
	}

	if (inv) {
		ll n_inv = poww(n, MOD - 2);
		for (int i = 0; i < n; i++)
			A[i] = A[i] * n_inv % MOD;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = pw[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		pw[i] = pw[i - 1] * 2 % MOD;
		inv[i] = poww(fact[i], MOD - 2);
	}

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		T.push_back(x);
	}

	cin >> q;
	for (int i = 0; i < q; i++) cin >> Q[i];

	for (int e : T) {
		memset(A, 0, sizeof A);
		memset(B, 0, sizeof B);

		int a = 0, b = 0;
		for (int i = 0; i < e; i++) {
			if (cnt[i] == 1) a++;
			if (cnt[i] > 1) b++;
		}

		for (int i = 0; i <= a; i++)
			A[i] = pw[i] * C(i, a) % MOD;
		for (int i = 0; i <= 2 * b; i++)
			B[i] = C(i, 2 * b);
		
		NTT(A, MAXN, false);
		NTT(B, MAXN, false);
		for (int i = 0; i < MAXN; i++)
			A[i] = A[i] * B[i] % MOD;
		NTT(A, MAXN, true);

		for (int i = 0; i < q; i++) {
			int rem = Q[i] - 2 * (e + 1);
			rem /= 2;
			if (rem >= 0 && rem < MAXN) ans[i] += A[rem];
		}
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] % MOD << endl;
	return 0;
}