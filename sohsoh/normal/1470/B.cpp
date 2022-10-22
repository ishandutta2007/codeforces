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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int S[MAXN], A[MAXN], n;
map<int, int> mp;

inline void Majik() {
	S[1] = 1;
	for (int i = 2; i < MAXN; i++) S[i] = i;
	for (int i = 4; i < MAXN; i += 2) S[i] = 2;
	for (ll i = 3; i * i < MAXN; i++) {
		if (S[i] == i) {
			for (ll j = i * i; j < MAXN; j += i) {
				if (S[j] == j) S[j] = i;
			}
		}
	}	
}

inline vector<int> P_factor(int x) {
	vector<int> ans;
	while (x > 1) {
		ans.push_back(S[x]);
		x /= S[x];
	}

	return ans;
}

inline int P_O(int x) {
	vector<int> F = P_factor(x);
	sort(all(F));
	int ans = 1, cnt = 0;
	for (int i = 0; i < (int)F.size(); i++) {
		cnt++;
		if (i == (int)F.size() - 1 || F[i] != F[i + 1]) {
			if (cnt & 1) ans *= F[i];
			cnt = 0;
		}
	}

	return ans;
}

inline int solve() {
	cin >> n;
	mp.clear();
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		mp[P_O(A[i])]++;
	}

	ll ans0 = 0, ans1 = 0;
	int t = 0;
	for (pll e : mp) {
		ans0 = max(ans0, e.Y);
		if (e.X != 1 && e.Y % 2 == 0) t += e.Y;
	}

	mp[1] += t;
	for (pll e : mp)
		ans1 = max(ans1, e.Y);
	int q;
	cin >> q;
	while (q--) {
		ll w;
		cin >> w;
		if (w >= 1) cout << ans1 << endl;
		else cout << ans0 << endl;
	}

	return 0;
}	

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Majik();
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}