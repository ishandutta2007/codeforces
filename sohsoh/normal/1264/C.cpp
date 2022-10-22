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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

ll pref[MAXN], n, q, P[MAXN], ps_pref[MAXN];
set<pll> st;
bool B[MAXN];

inline ll inv(ll a) {
	a %= MOD;
	return poww(a, MOD - 2, MOD);
} 

inline ll SegVal(pll e) {
	int L = e.X, R = e.Y;
	ll ans = (ps_pref[R - 1] - ps_pref[L - 1] + MOD) % MOD * inv(pref[L - 1]) % MOD + 1;
	ans %= MOD;
	ll E = pref[R] * inv(pref[L - 1]) % MOD;
	ans = ans * inv(E) % MOD;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	pref[0] = ps_pref[0] = 1, B[1] = true;
	
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		P[i] = P[i] * inv(100) % MOD;
		pref[i] = pref[i - 1] * P[i] % MOD;
		ps_pref[i] = ps_pref[i - 1] + pref[i];
		ps_pref[i] %= MOD;
	}

	st.insert({1, n});
	ll ans = SegVal({1, n});

	while (q--) {
		int v;
		cin >> v;
		if (!B[v]) {
			B[v] = true;
			auto it = st.lower_bound({v, 0});
			it--;
			pll e = *it;
			st.erase(it);
			ans -= SegVal(e);
			ans += SegVal({e.X, v - 1});
			st.insert({e.X, v - 1});
			ans += SegVal({v, e.Y});
			st.insert({v, e.Y});
		} else {
			B[v] = false;
			auto it = st.lower_bound({v, 0});
			pll e2 = *it;
			it--;
			pll e1 = *it;
			ans -= SegVal(e2);
			ans -= SegVal(e1);
			st.erase(e1);
			st.erase(e2);
			st.insert({e1.X, e2.Y});
			ans += SegVal({e1.X, e2.Y});
		}

		ans += 20 * MOD;
		ans %= MOD;
		cout << ans << endl;
	}
	return 0;
}