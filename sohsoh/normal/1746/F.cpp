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
const ll LOG = 30;
const ll MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll P[LOG], T[LOG], n, q, A[MAXN], fen[LOG][MAXN];
vector<int> F[MAXN];

inline ll poww(ll a, ll b) {
	a %= MOD;
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline void recalc(int ind) {
	F[ind].clear();
	for (int i = 0; i < LOG; i++)
		F[ind].push_back(poww(A[ind] + T[i], P[i]));
}

inline void update(int x, int ind, ll val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[x][ind] += val;
}

inline ll query(int x, int ind) {
	ll ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[x][ind];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < LOG; i++) P[i] = rng() % MOD, T[i] = rng() % MOD;
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		recalc(i);

		for (int j = 0; j < LOG; j++)
			update(j, i, F[i][j]);
	}

	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int i, x;
			cin >> i >> x;

			vector<int> vec = F[i];
			A[i] = x;
			recalc(i);

			for (int j = 0; j < LOG; j++)
				update(j, i, F[i][j] - vec[j]);
		} else {
			int l, r, k;
			cin >> l >> r >> k;

			bool flag = true;
			for (int j = 0; j < LOG; j++) {
				if ((query(j, r) - query(j, l - 1)) % k) {
					flag = false;
					break;
				}
			}

			cout << (flag ? "YES" : "NO") << endl;
		}
	}
	return 0;
}