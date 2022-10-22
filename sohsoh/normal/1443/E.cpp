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
const ll FACT = 17;

ll fact[FACT], k = 1, q, n;

inline vector<int> perm_t(int n, ll k, ll L = 1) { // n^2 :)
	vector<int> ans, dig;
	for (int i = 1; i <= n; i++) dig.push_back(L + i - 1);
	for (int i = 1; i <= n; i++) {
		ll red = fact[n - i];
		ll d = (k + red - 1) / red;
		k -= (d - 1) * red;
		auto it = dig.begin() + d - 1;
		ans.push_back(*it);
		dig.erase(it);
	}

	return ans;
}

inline ll sum(ll L, ll R) {
	return R * (R + 1) / 2 - L * (L - 1) / 2;
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = fact[1] = 1;
	for (int i = 2; i < FACT; i++) fact[i] = fact[i - 1] * i;
	
	cin >> n >> q;
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			ll l, r;
			cin >> l >> r;
			if (n < FACT) {
				vector<int> P = perm_t(n, k);
				int ans = 0;
				for (int i = l - 1; i < r; i++) ans += P[i];
			       	cout << ans << endl;	
			} else {
				vector<int> P = perm_t(FACT, k, n - FACT + 1);
				ll ans = 0;
				if (l < n - FACT + 1) ans += sum(l, min(n - FACT, r));
				for (int i = max(n - FACT + 1, l); i <= r; i++) ans += P[i - (n - FACT + 1)];
				cout << ans << endl;	
			}
		} else {
			int x;
			cin >> x;
			k += x;
		}
	}
	return 0;
}