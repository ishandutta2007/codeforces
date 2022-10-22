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
#define debug2(x)	            cerr << #x << ": " << x.X << sep << x.Y << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 100 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll dist[MAXN][MAXN][3], pos[MAXN];
int A[MAXN][MAXN], n;
queue<pair<pll, int>> q;

inline void upd(int d_v, int r_v, int v, int r, int t) {
	if (v == 0) return;
	if (v == r + 1) r++;
	if (make_pair(d_v, r_v) < dist[v][r][t]) {
		dist[v][r][t] = {d_v, r_v};
		q.push({{v, r}, t});
	}
}

inline int CV(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > n) return 0;
	return A[x][y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = {INF, INF};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			pos[A[i][j]] = {i, j};
		}
	}

	q.push({{1, 1}, 0});
	q.push({{1, 1}, 1});
	q.push({{1, 1}, 2});
	dist[1][1][0] = dist[1][1][1] = dist[1][1][2] = {0, 0};
	while (!q.empty()) {
		int v = q.front().X.X, r = q.front().X.Y, t = q.front().Y;
		int d_v = dist[v][r][t].X, r_v = dist[v][r][t].Y;
		q.pop();
		upd(d_v + 1, r_v + 1, v, r, 0);
		upd(d_v + 1, r_v + 1, v, r, 1);
		upd(d_v + 1, r_v + 1, v, r, 2);
		
		int x = pos[v].X, y = pos[v].Y;
		if (t == 0) {
			upd(d_v + 1, r_v, CV(x - 1, y - 2), r, t);
			upd(d_v + 1, r_v, CV(x - 1, y + 2), r, t);
			upd(d_v + 1, r_v, CV(x - 2, y - 1), r, t);
			upd(d_v + 1, r_v, CV(x - 2, y + 1), r, t);
			upd(d_v + 1, r_v, CV(x + 1, y - 2), r, t);
			upd(d_v + 1, r_v, CV(x + 1, y + 2), r, t);
			upd(d_v + 1, r_v, CV(x + 2, y - 1), r, t);
			upd(d_v + 1, r_v, CV(x + 2, y + 1), r, t);
		} else if (t == 1) {
			for (int i = 1; i <= n; i++) {
				upd(d_v + 1, r_v, CV(i, y), r, t);	
				upd(d_v + 1, r_v, CV(x, i), r, t);
			}
		} else {
			int diag1 = x + y, diag2 = x - y;
			for (int i = 1; i <= n; i++) {
				upd(d_v + 1, r_v, CV(i, diag1 - i), r, t);
				upd(d_v + 1, r_v, CV(i, i - diag2), r, t);
			}
		}
	}
	
	pll ans = {INF, INF};
	ans = min(ans, dist[n * n][n * n][0]);
	ans = min(ans, dist[n * n][n * n][1]);
	ans = min(ans, dist[n * n][n * n][2]);
	cout << ans.X << sep << ans.Y << endl;
	return 0;
}