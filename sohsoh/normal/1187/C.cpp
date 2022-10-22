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

bool prv[MAXN];
int ans[MAXN], m, n;
vector<pll> v0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t) for (int i = l; i < r; i++) prv[i + 1] = true;
		else v0.push_back({l, r});
	}

	int ptr = MAXN;
	for (int i = 1; i <= n; i++) {
		if (prv[i]) ans[i] = ptr;
		else ans[i] = --ptr;
	}

	for (pll e : v0) {
		if (is_sorted(ans + e.X, ans + e.Y + 1)) return cout << "NO" << endl, 0;
	}

	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}