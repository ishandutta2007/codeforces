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

const ll MAXN = 1e3 + 10;

pll par[MAXN][MAXN];
ll n, m, A[MAXN][MAXN], k, ans[MAXN][MAXN];
bool vis[MAXN][MAXN], tvis[MAXN][MAXN];
vector<pair<ll, pll>> vec;
vector<pll> C[MAXN][MAXN];


inline bool unite(pll a, pll b) {
	if (!vis[a.X][a.Y] || !vis[b.X][b.Y]) return false;	
	a = par[a.X][a.Y], b = par[b.X][b.Y];
	if (a == b) return false;
	

	if (C[a.X][a.Y].size() < C[b.X][b.Y].size()) swap(a, b);
	for (pll e : C[b.X][b.Y]) {
		C[a.X][a.Y].push_back(e);
		par[e.X][e.Y] = a;
	}

	C[b.X][b.Y].clear();
	return true;
}

void dfs(int x, int y, ll& cnt, int a) {
	if (tvis[x][y] || cnt <= 0) return;
	tvis[x][y] = true;
	ans[x][y] = a;
	cnt--;

	if (vis[x + 1][y]) dfs(x + 1, y, cnt, a);
	if (vis[x - 1][y]) dfs(x - 1, y, cnt, a);
	if (vis[x][y + 1]) dfs(x, y + 1, cnt, a);
	if (vis[x][y - 1]) dfs(x, y - 1, cnt, a);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
			par[i][j] = {i, j};
			vec.push_back({A[i][j], {i, j}});
			C[i][j].push_back({i, j});
		}
	}

	sort(all(vec), greater<pair<ll, pll>>());
	for (auto e : vec) {
		ll x = e.Y.X, y = e.Y.Y, a = e.X;
		vis[x][y] = true;
		unite({x, y}, {x + 1, y});
		unite({x, y}, {x - 1, y});
		unite({x, y}, {x, y + 1});
		unite({x, y}, {x, y - 1});

		if (k % a) continue;
		ll cnt = k / a;
		pll t = par[x][y];

		if (int(C[t.X][t.Y].size()) >= cnt) {
			dfs(x, y, cnt, a);
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++)
					cout << ans[i][j] << sep;
				cout << endl;
			}

			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}