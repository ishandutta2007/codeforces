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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
int deg[MAXN], A[MAXN];

inline int solve() {
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) cin >> A[i], ans += A[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}

	priority_queue<pll> pq;
	for (int i = 1; i <= n; i++) {
		deg[i]--;
		if (deg[i] > 0) pq.push({A[i], i});
	}
	cout << ans << sep;
	for (int i = 0; i < n - 2; i++) {
		int val = pq.top().X, ind = pq.top().Y;	
		pq.pop();
		ans += val;
		deg[ind]--;
		if (deg[ind] > 0) pq.push({val, ind});
		cout << ans << sep;
	}

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