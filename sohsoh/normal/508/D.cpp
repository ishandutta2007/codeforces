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

const ll MAXN = 310;
const ll CHR = 270;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
bool vis[MAXN][MAXN], SSC_C;
vector<pll> adj[MAXN][MAXN], adj_r[MAXN][MAXN];
pair<pll, pll> odd_edge = {{300, 300}, {300, 300}};
vector<pll> tour;

void Euler(pll v) {
	int x = v.X, y = v.Y;
	while (!adj[x][y].empty()) {
		pll u = adj[x][y].back();
		adj[x][y].pop_back();
		Euler(u);
	}

	tour.push_back(v);
}

void dfs(pll v) {
	if (vis[v.X][v.Y]) return;
	vis[v.X][v.Y] = true;
	for (pll u : adj[v.X][v.Y]) dfs(u);
	for (pll u : adj_r[v.X][v.Y]) dfs(u);
}

inline void is_connected(pll v) {	
	SSC_C = true;
	dfs(v);
	for (int i = 0; i < CHR; i++) {
		for (int j = 0; j < CHR; j++) {
			if ((!adj[i][j].empty() || !adj_r[i][j].empty()) && !vis[i][j]) cout << "NO" << endl, exit(0);
		}
	}
}

inline string cv(pll e) {
	string res = {char(e.X), char(e.Y)};
	return res;
}  

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		adj[int(a)][int(b)].push_back({int(b), int(c)});
		adj_r[int(b)][int(c)].push_back({int(a), int(b)});
	}

	pll start;
	for (int i = 0; i < CHR; i++) {
		for (int j = 0; j < CHR; j++) {
			if (!adj[i][j].empty()) is_connected({i, j}), start = {i, j};
			if (adj[i][j].size() == adj_r[i][j].size()) continue;
			if (abs((int) adj[i][j].size() - (int) adj_r[i][j].size()) >= 2) return cout << "NO" << endl, 0;
			if (adj[i][j].size() < adj_r[i][j].size()) {
				if (odd_edge.X.X != 300) return cout << "NO" << endl, 0;
				odd_edge.X = {i, j};
			} else {
				if (odd_edge.Y.X != 300) return cout << "NO" << endl, 0;
				odd_edge.Y = {i, j};
			}

		}
	}
	
	adj[odd_edge.X.X][odd_edge.X.Y].push_back(odd_edge.Y);
	Euler(start);
	if (odd_edge.X.X != 300) tour.pop_back();
	reverse(all(tour));
	int ind = 0;
	for (int i = 0; i < tour.size(); i++) 
		if (i > 0 && make_pair(tour[i - 1], tour[i]) == odd_edge) ind = i;

	vector<pll> ans;
	for (int i = ind; i < tour.size(); i++) ans.push_back(tour[i]);
	for (int i = 0; i < ind; i++) ans.push_back(tour[i]);

	cout << "YES" << endl << cv(ans.front());
	for (int i = 1; i < ans.size(); i++) cout << char(ans[i].Y);
	cout << endl;
	return 0;
}