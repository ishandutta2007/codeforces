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
	int n, k;
	cin >> n >> k;
	if (k > n || k > 3 || k == 1 || (k == 2 && n < 5) || (k == 3 && n < 4)) return cout << -1 << endl, 0;
	if (k == 2) {
		cout << n - 1 << endl;
		for (int i = 1; i < n; i++) cout << i << sep << i + 1 << endl;
		return 0;
	}

	vector<pll> ans;
	ans.push_back({1, 2});
	ans.push_back({n - 1, n});
	for (int i = 2; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans.push_back({i, j});
		}
	}

	cout << ans.size() << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << endl;
	return 0;
}