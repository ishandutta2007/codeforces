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

int n, m, A[MAXN], B[MAXN], par[MAXN], H[MAXN];
vector<pair<ll, pll>> edges;

int Find(int v) {
	if (v == par[v]) return v;
	return par[v] = Find(par[v]);
}

inline void Union(int v, int u) {
	if (H[u] < H[v]) swap(v, u);
	par[v] = u;
	if (H[u] == H[v]) H[u]++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];
	for (int i = 0; i < MAXN; i++) par[i] = i; //i/
	
	ll tot = 0;
	for (int i = 1; i <= m; i++) {
		int s;
		cin >> s;
		for (int j = 0; j < s; j++) {
			int v;
			cin >> v;
			edges.push_back({A[i] + B[v], {v, i + n}});
			tot += A[i] + B[v];
		}
	}

	sort(all(edges));
	reverse(all(edges));
	for (auto e : edges) {
		int u = e.Y.X, v = e.Y.Y;
		u = Find(u);
		v = Find(v);
		if (u == v) continue;
		tot -= e.X;
		Union(u, v);
	}

	cout << tot << endl;
	return 0;
}