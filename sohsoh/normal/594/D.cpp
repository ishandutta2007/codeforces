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

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

vector<pll> Q[MAXN];
int F[MAXN], lst[MAXN], n, q, A[MAXN];
ll ans[MAXN], inv[MAXN], fen[MAXN];

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}

	return ans;
}

inline void update(int ind, ll val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] = fen[ind] * val % MOD;
}

inline ll query(int ind) {
	ll ans = 1;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans = ans * fen[ind] % MOD;
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fen[0] = fen[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		fen[i] = 1;

		if (!F[i]) {
			inv[i] = poww(i, MOD - 2);
			inv[i - 1] = poww(i - 1, MOD - 2);
			for (int j = i; j < MAXN; j += i)
				if (!F[j])
					F[j] = i;
		}
	}
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	cin >> q;
	for (int t = 1; t <= q; t++) {
		int l, r;
		cin >> l >> r;
		Q[l].push_back({t, r});
	}

	for (int l = n; l > 0; l--) {
		int x = A[l];	
		update(l, A[l]);

		while (x > 1) {
			ll p = F[x];
			x /= p;

			if (lst[p]) update(lst[p], p * inv[p - 1] % MOD);
			update(l, (p - 1) * inv[p] % MOD);
			lst[p] = l;
		}

		for (pll e : Q[l])
			ans[e.X] = query(e.Y);
	}

	for (int i = 1; i <= q; i++) cout << ans[i] << endl;
	return 0;
}