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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		string s;
		cin >> n >> q;
		cin >> s;
		s = "." + s;
		while (q--) {
			int l, r;
			cin >> l >> r;
			bool ok = false;
			for (int i = 1; i < l; i++) if (s[i] == s[l]) ok = true;
			for (int i = r + 1; i <= n; i++) if (s[i] == s[r]) ok = true;
			if (ok) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}