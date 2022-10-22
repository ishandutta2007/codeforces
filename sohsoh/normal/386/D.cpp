#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 70 + 3;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

char G[MAXN][MAXN];
int n, a, b, c, dist[MAXN][MAXN][MAXN];
tuple<int, int, int> par[MAXN][MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> G[i][j];

	for (int i = 0; i < MAXN; i++) 
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < MAXN; k++) dist[i][j][k] = INF;
	queue<tuple<int, int, int>> q;
	q.push({a, b, c});
	dist[a][b][c] = 0;
	while (!q.empty()) {
		int x = get<0> (q.front()), y = get<1> (q.front()), z = get<2> (q.front());
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (x != i && y != i && dist[x][y][i] == INF && G[i][z] == G[x][y]) { // z
				dist[x][y][i] = dist[x][y][z] + 1;
				par[x][y][i] = {x, y, z};
				q.push({x, y, i});
			}

			if (x != i && z != i && dist[x][i][z] == INF && G[i][y] == G[x][z]) { // y
				dist[x][i][z] = dist[x][y][z] + 1;
				par[x][i][z] = {x, y, z};
				q.push({x, i, z});
			}

			if (y != i && z != i && dist[i][y][z] == INF && G[i][x] == G[y][z]) { // x
				dist[i][y][z] = dist[x][y][z] + 1;
				par[i][y][z] = {x, y, z};
				q.push({i, y, z});
			}
		}	
	}
	
	int ans = INF;
	tuple<int, int, int> ans_t;
	if (dist[1][2][3] < ans) ans = dist[1][2][3], ans_t = {1, 2, 3};	
	if (dist[1][3][2] < ans) ans = dist[1][3][2], ans_t = {1, 3, 2};	
	if (dist[2][1][3] < ans) ans = dist[2][1][3], ans_t = {2, 1, 3};	
	if (dist[2][3][1] < ans) ans = dist[2][3][1], ans_t = {2, 3, 1};	
	if (dist[3][1][2] < ans) ans = dist[3][1][2], ans_t = {3, 1, 2};	
	if (dist[3][2][1] < ans) ans = dist[3][2][1], ans_t = {3, 2, 1};	
	
	if (ans == INF) return cout << -1 << endl, 0;
	
	stack<pair<int, int>> st;
	int x = get<0> (ans_t), y = get<1> (ans_t), z = get<2> (ans_t);
	while (get<0> (par[x][y][z])) {
		int p_x = get<0> (par[x][y][z]), p_y = get<1> (par[x][y][z]), p_z = get<2> (par[x][y][z]);
		if (p_x != x) st.push({p_x, x});
		if (p_y != y) st.push({p_y, y});
		if (p_z != z) st.push({p_z, z});
		x = p_x, y = p_y, z = p_z;
	}

	cout << ans << endl;
	while (!st.empty()) cout << st.top().first << sep << st.top().second << endl, st.pop();
	return 0;
}