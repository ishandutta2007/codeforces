#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

inline void mkey(int& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

struct Fenwick {
	int n;
	vector<int> fen;
	vector<pll> hist;

	Fenwick(int n): n(n) {
		fen.resize(n + 3, 0);
	}

	inline void add(int ind, int val, bool rec = true) {
		if (rec) hist.push_back({ind, val});
		for (++ind; ind < n + 3; ind += ind & -ind)
			mkey(fen[ind] += val);
	}

	inline int query(int ind) {
		int ans = 0;
		for (++ind; ind > 0; ind -= ind & -ind)
			mkey(ans += fen[ind]);
		return ans;
	}

	inline void init() {
		for (pll e : hist)
			add(e.X, -e.Y, false);
		hist.clear();
		add(0, 1);
	}
};

int A[MAXN], n, suff[MAXN], pref[MAXN];
bool vis[MAXN];

inline void solve() {
	for (int i = 0; i < n + 5; i++) 
		vis[i] = false; 

	cin >> n;
	vector<pll> vec;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vec.push_back({x, i});
	}

	sort(all(vec), [] (pll a, pll b) {
			if (a.X == b.X) return a.Y > b.Y;
			return a.X < b.X;
			});

	for (int i = 0; i < n; i++)
		A[vec[i].Y] = i + 1;

	vector<int> suff_mx;
	int mx = 0, ans = 0;
	Fenwick fen(n);

	fen.init();
	for (int i = n; i > 0; i--) {
		if (A[i] > mx) {
			mx = A[i];
			vis[A[i]] = true;
		}

		suff[i] = fen.query(n - A[i]);
		fen.add(n - A[i] + 1, suff[i]);
	}

	fen.init();
	for (int i = 1; i <= n; i++) {
		pref[i] = fen.query(A[i] - 1);
		fen.add(A[i], pref[i]);
		ans = (ans + 1ll * pref[i] * suff[i]) % MOD;
	}


	fen.init();
	int mx_ind = vec[n - 1].Y;
	mkey(ans -= 1ll * pref[mx_ind] * suff[mx_ind] % MOD);

	for (int i = n - 1; i > 0; i--) {
		int ind = vec[i - 1].Y;
		if (ind > mx_ind) {
			mkey(ans -= 1ll * pref[ind] * suff[ind] % MOD);
			if (vis[i]) {
				mx_ind = ind;
				fen.init();
			}

			continue;
		}

		int x = fen.query(n - ind);
		mkey(ans -= 1ll * pref[ind] * suff[mx_ind] % MOD * x % MOD);
		fen.add(n - ind + 1, x);

		if (vis[i]) {
			mx_ind = ind;
			fen.init();
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}