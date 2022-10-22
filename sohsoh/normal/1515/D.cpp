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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, l, r, ans;
map<int, int> L_mp, R_mp;

inline int solve() {
	ans = 0;
	L_mp.clear();
	R_mp.clear();

	cin >> n >> l >> r;
	for (int i = 0; i < l; i++) {
		int x;
		cin >> x;
		L_mp[x]++;
	}

	for (int i = 0; i < r; i++) {
		int x;
		cin >> x;
		R_mp[x]++;
	}

	for (pll e : L_mp) {
		int l_cnt = e.Y, r_cnt = R_mp[e.X];
		L_mp[e.X] -= min(l_cnt, r_cnt);
		R_mp[e.X] -= min(l_cnt, r_cnt);
		n -= 2 * min(l_cnt, r_cnt);
	}

	if (r < l) swap(l, r), swap(L_mp, R_mp);
	int diff = r - l;
	for (pll e : R_mp) {
		int t = min(e.Y / 2, 1ll * diff / 2);
		diff -= t * 2;
		R_mp[e.X] -= t * 2;
		ans += t;
		n -= t * 2;
	}	
	
	ans += diff;
	n -= diff;
	ans += n / 2;
	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}