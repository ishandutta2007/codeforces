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
const ll X = 8;

ll n, k, H[MAXN];

inline int solve() {
	int n;
	cin >> n;
	vector<pll> ans;
	if (n <= X) {
		for (int i = 3; i < n; i++) ans.push_back({i, n});
		int x = n;
		while (x > 1) ans.push_back({n, 2}), x = (x + 1) / 2;
	} else {
		for (int i = 3; i < X; i++) ans.push_back({i, n});
		for (int i = X + 1; i < n; i++) ans.push_back({i, n});
		int x = n;
		while (x > 1) ans.push_back({n, X}), x = (x + X - 1) / X;
		x = X;
		while (x > 1) ans.push_back({X, 2}), x = (x + 1) / 2;
	}

	cout << ans.size() << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve(); 
	return 0;
}