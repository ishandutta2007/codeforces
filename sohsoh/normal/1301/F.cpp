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

const ll MAXN = 1e6 + 100;
const ll MAXK = 41;
const ll MAXM = 1e3 + 100;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, k, qr, C[MAXN], val[MAXM][MAXM], t = 1, dist[MAXK][MAXN];
pair<int, int> P[MAXN];
vector<int> col[MAXN];
deque<int> q;

inline void Update(int c, int v, int d, int w) {
	if (dist[c][v] > d + w) {
		dist[c][v] = d + w;
		if (w == 1) q.push_back(v);
		else q.push_front(v);	
	} 
}

inline void BFS(int c) {
	memset(dist[c], 63, sizeof dist[c]);
	for (int i = 1; i < t; i++) {
		if (C[i] == c) {
			q.push_back(i);
			dist[c][i] = 0;
		}
	}

	while (!q.empty()) {
		int v = q.front(), d_v = dist[c][v];
		q.pop_front();
		if (v > n * m) {
			for (int e : col[v - n * m]) Update(c, e, d_v, 0);
			continue;
		}

		if (P[v].Y < m) Update(c, v + 1, d_v, 1);
		if (P[v].Y > 1) Update(c, v - 1, d_v, 1);
		if (P[v].X > 1) Update(c, v - m, d_v, 1);
		if (P[v].X < n) Update(c, v + m, d_v, 1);
		Update(c, n * m + C[v], d_v, 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> C[t];
			P[t] = {i, j};
			col[C[t]].push_back(t);
			val[i][j] = t++;
		}
	}

	for (int i = 1; i <= k; i++) BFS(i);

	cin >> qr;
	while (qr--) {
		int c1, r1, c2, r2;
		cin >> c1 >> r1 >> c2 >> r2;
		int ans = abs(r1 - r2) + abs(c1 - c2);
		for (int i = 1; i <= k; i++) ans = min(1ll * ans, 1ll * dist[i][val[c1][r1]] + dist[i][val[c2][r2]] + 1);
		cout << ans << endl;
	}

	return 0;
}