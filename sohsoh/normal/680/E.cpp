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

const ll MAXN = 500 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const pll ROOT = {502, 502};

stack<pair<pll, int>> st;
pll par[MAXN][MAXN];
int t_s[MAXN][MAXN], t_e[MAXN][MAXN], val[MAXN][MAXN], min_x[MAXN][MAXN], max_x[MAXN][MAXN], min_y[MAXN][MAXN], max_y[MAXN][MAXN];
int k, n, H[MAXN][MAXN], S[MAXN][MAXN], ps[MAXN][MAXN], ans;
char G[MAXN][MAXN];

pll Find(pll v) {
	if (v == par[v.X][v.Y]) return v;
	return Find(par[v.X][v.Y]);
}

inline void Union(pll v, pll u, bool track = false) {
	v = Find(v);
	u = Find(u);
	if (u == v) return;
	if (H[u.X][u.Y] < H[v.X][v.Y]) swap(v, u);	
	if (track) st.push({v, H[u.X][u.Y]});
	if (H[u.X][u.Y] == H[v.X][v.Y]) H[u.X][u.Y]++;
	par[v.X][v.Y] = u;
	S[u.X][u.Y] += S[v.X][v.Y];
}

inline void Reset() {
	while (!st.empty()) {
		pll v = st.top().X;
		pll u = par[v.X][v.Y];
		par[v.X][v.Y] = v;
		S[u.X][u.Y] -= S[v.X][v.Y];
		H[u.X][u.Y] = st.top().Y;
		st.pop();
	}
}

inline int Sum(int x0, int y0, int x1, int y1) {
	return ps[x1][y1] - ps[x0 - 1][y1] - ps[x1][y0 - 1] + ps[x0 - 1][y0 - 1];
}

inline void BS() {	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {	
			if (min_y[i][j] == INF || min_x[i][j] == INF) continue;
			int y0 = max(max_y[i][j] - k + 1, 1), y1 = min_y[i][j];	
			for (int tk = min_x[i][j]; tk >= max(1, max_x[i][j] - k + 1); tk--) {	
				t_s[tk][y0] += S[i][j];
				t_e[tk][y1] += S[i][j];
			}	
		}
	}

	for (int i = 1; i <= n; i++) {
		int t_val = 0;
		for (int j = 1; j <= n; j++) {
			t_val += t_s[i][j];
			val[i][j] = t_val;	
			t_val -= t_e[i][j];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++) for (int j = 1; j < MAXN; j++) min_y[i][j] = min_x[i][j] = INF; 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> G[i][j];
			par[i][j] = {i, j};
			ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
			if (G[i][j] == '.') {
				S[i][j] = 1;
				if (G[i][j - 1] == '.') Union({i, j}, {i, j - 1});
				if (G[i - 1][j] == '.') Union({i, j}, {i - 1, j});
			}
			
			else ps[i][j]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (G[i][j] == 'X') continue;
			pll v = Find({i, j});
			min_x[v.X][v.Y] = min(min_x[v.X][v.Y], i);
			max_x[v.X][v.Y] = max(max_x[v.X][v.Y], i);
			min_y[v.X][v.Y] = min(min_y[v.X][v.Y], j);
			max_y[v.X][v.Y] = max(max_y[v.X][v.Y], j);
		}
	}

	BS();	

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ans = max(ans, S[i][j]);

	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= n - k + 1; j++) {
			int ei = i + k - 1, ej = j + k - 1;	
			if (i > 1) for (int k = j; k <= ej; k++) Union(ROOT, {i - 1, k}, true);	
			if (j > 1) for (int k = i; k <= ei; k++) Union(ROOT, {k, j - 1}, true);
			if (ei < n) for (int k = j; k <= ej; k++) Union(ROOT, {ei + 1, k}, true);
			if (ej < n) for (int k = i; k <= ei; k++) Union(ROOT, {k, ej + 1}, true);
			
			pll v = Find(ROOT);
			ans = max(ans, S[v.X][v.Y] + Sum(i, j, ei, ej) + val[i][j]);
			Reset();
		}
	}

	cout << ans << endl;
	return 0;
}