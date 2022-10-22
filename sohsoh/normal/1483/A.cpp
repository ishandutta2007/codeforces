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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, ans[MAXN], cnt[MAXN];
vector<int> f[MAXN];

inline int solve() {
	for (int i = 0; i < max(n + 10, m + 10); i++) cnt[i] = 0, f[i].clear(), ans[i] = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			f[i].push_back(x);
		}

		if (k == 1) cnt[f[i].front()]++, ans[i] = f[i].front();
	}

	for (int i = 1; i <= m; i++) {
		if (f[i].size() == 1) continue;
		int ind = f[i].front();
		for (int e : f[i]) if (cnt[e] < cnt[ind]) ind = e;
		cnt[ind]++;
		ans[i] = ind;
	}

	for (int i = 0; i < n + 5; i++) if (cnt[i] > (m + 1) / 2) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	for (int i = 1; i <= m; i++) cout << ans[i] << sep;
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