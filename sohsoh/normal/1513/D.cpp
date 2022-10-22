#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, par[MAXN], A[MAXN];
ll ans, p;

int Find(int v) {
	if (v == par[v]) return v;
	return par[v] = Find(par[v]);
}

inline bool Union(int u, int v) {
	u = Find(u), v = Find(v);
	if (u == v) return false;
	par[v] = u;
	return true;	
}

inline int solve() {
	cin >> n >> p;
	int rem = n - 1;
	vector<pll> v;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		par[i] = i;
		v.push_back({A[i], i});
	}

	sort(all(v));
	ans = 0;
	for (pll e : v) {
		int i = e.Y;
		if (A[i] > p) break;
		for (int j = i + 1; j <= n && A[j] % A[i] == 0 && Union(i, j); j++) rem--, ans += A[i];
		for (int j = i - 1; j > 0 && A[j] % A[i] == 0 && Union(i, j); j--) rem--, ans += A[i];
	}
	
	ans += rem * p;
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