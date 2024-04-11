#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int H[MAXN], W[MAXN], n, mn_W[MAXN], ans[MAXN];

inline int solve() {
	cin >> n;
	vector<pll> v;
	for (int i = 1; i <= n; i++) {
		cin >> H[i] >> W[i];
		v.push_back({H[i], i});
	}

	sort(all(v));
	for (int i = 0; i < n; i++) {
		if (i == 0) mn_W[i] = v[i].Y;
		else {
			mn_W[i] = mn_W[i - 1];
			if (W[v[i].Y] < W[mn_W[i]]) mn_W[i] = v[i].Y;
		}
	}

	for (int i = 0; i < n; i++) {	
		int ind = v[i].Y, h = v[i].X, w = W[ind];
		ans[ind] = -1;
		auto it = lower_bound(all(v), make_pair(h, -INF));
		int ind2 = it - v.begin();
		ind2--;
		if (ind2 >= 0 && W[mn_W[ind2]] < w) ans[ind] = mn_W[ind2];
		it = lower_bound(all(v), make_pair(w, -INF));
		ind2 = it - v.begin();
		ind2--;
		if (ind2 >= 0 && W[mn_W[ind2]] < h) ans[ind] = mn_W[ind2];
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}