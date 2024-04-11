#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e3 + 10;
const ll INF = 4e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline ll dist(pll x,  pll y) {
	return (abs(x.X - y.X) + abs(x.Y - y.Y)) * (abs(x.X - y.X) + abs(x.Y - y.Y));
}

inline ll C(plll x, pll y) {
	return dist(x.X, y) <= x.Y * x.Y;
}

vector<plll> v;
vector<pll> v2;
ll n, m, k;
vector<int> adj[MAXN];
int par[MAXN], D[MAXN][MAXN];

void dfs(int i, int v, int p, int d = 0) {
	D[i][v] = d;
	for (int u : adj[v]) if (u != p) dfs(i, u, v, d + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	v.push_back({{0, 0}, INF});
	v2.push_back({0, 0});
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v2.push_back({x, y});
	}

	for (int i = 0; i < m; i++) {
		int x, y, r;
		cin >> r >> x >> y;
		v.push_back({{x, y}, r});
	}
	

	for (int i = 1; i <= m; i++) {
		int R = 0;
		for (int j = 1; j <= m; j++)
			if (v[j].Y > v[i].Y && C(v[j], v[i].X) && v[j].Y < v[R].Y)
			       R = j;
		adj[i].push_back(R);
		adj[R].push_back(i);
	}

	for (int i = 0; i <= m; i++) dfs(i, i, -1);
	for (int i = 1; i <= n; i++) {
		int R = 0;
		for (int j = 1; j <= m; j++)
			if (C(v[j], v2[i]) && v[j].Y < v[R].Y)
				R = j;
		par[i] = R;
	}

	while (k--) {
		int u, v;
		cin >> u >> v;
		cout << D[par[u]][par[v]] << endl;
	}
	return 0;
}