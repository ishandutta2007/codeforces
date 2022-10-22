#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 30;

int ans[MAXN], n, q, f[MAXN];
vector<pll> vec[MAXN];
vector<pair<pll, int>> Q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	while (q--) {
		int i, j, x;
		cin >> i >> j >> x;
		if (i > j) swap(i, j);

		if (i == j) ans[i] |= x;
		f[i] |= (((1 << LOG) - 1) ^ x);
		f[j] |= (((1 << LOG) - 1) ^ x);
		Q.push_back({{i, j}, x});
	}

	for (auto [p, x] : Q) {
		int i = p.X, j = p.Y;
		ans[i] |= (x & f[j]);

		vec[i].push_back({j, x});
	}

	for (int i = 1; i <= n; i++) {
		for (auto [j, x] : vec[i]) {
			x = x ^ (x & ans[i]);
			ans[j] |= x;
		}

		cout << ans[i] << sep;
	}

	cout << endl;
	return 0;
}