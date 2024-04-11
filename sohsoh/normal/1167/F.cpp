#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline void mkey(int& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

struct Fen {
	int fen[MAXN];

	inline void Add(int ind, int val) {
		for (++ind; ind < MAXN; ind += ind & -ind) mkey(fen[ind] += val);
	}

	inline ll Pref(int ind) {
		int ans = 0;
		for (++ind; ind > 0; ind -= ind & -ind) mkey(ans += fen[ind]);
		return ans;
	}

	inline ll Suff(int ind) {
		int ans = Pref(MAXN - 2) - Pref(ind - 1);
		mkey(ans);
		return ans;
	}
};

Fen L_Fen, R_Fen;
int n;
vector<pll> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back({x, i});
	}

	int ans = 0;
	sort(all(v));
	for (pll e : v) {
		ll x = e.X, i = e.Y;
		mkey(ans += x * i % MOD * (n - i + 1) % MOD);
		mkey(ans += x * L_Fen.Pref(i) % MOD * (n - i + 1) % MOD);
		mkey(ans += x * i % MOD * R_Fen.Suff(i) % MOD);
		L_Fen.Add(i, i);
		R_Fen.Add(i, n - i + 1);
	} 

	cout << ans << endl;
	return 0;
}