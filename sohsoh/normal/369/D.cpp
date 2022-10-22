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

const ll MAXN = 3e3 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, k, dist[MAXN][MAXN], P[MAXN], pos_cnt[MAXN], full_cnt[MAXN];
bool S[MAXN][MAXN];
queue<pair<int, int>> q;

inline bool is_valid(pair<int, int> p) {
	if (p.X < p.Y && p.Y <= n + 1) return true;
	return false;
} 

inline void upd(pair<int, int> p, pair<int, int> p2) {
	if (!is_valid(p2)) return;
	if (dist[p2.X][p2.Y] == INF) {
		dist[p2.X][p2.Y] = dist[p.X][p.Y] + 1;
		q.push(p2);
	}	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &n, &k);
	
	if (n == 1) return cout << 1 << endl, 0;
	for (int i = 1; i <= n; i++) scanf("%d", P + i);
	for (int i = n; i > 0; i--) {
		pos_cnt[i] = pos_cnt[i + 1];
		full_cnt[i] = full_cnt[i + 1];
		if (P[i]) pos_cnt[i]++;
		if (P[i] == 100) full_cnt[i]++;
	}

	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dist[i][j] = INF;

	q.push({1, 2});
	dist[1][2] = 0;
	while (!q.empty()) {
		int f = q.front().X, ind = q.front().Y;
		pair<int, int> p = q.front();
		q.pop();	
		if (P[f] > 0 && pos_cnt[ind] > 0) upd(p, {ind + 1, ind + 2});   // both
		if (P[f] > 0 && full_cnt[ind] <= 0) upd(p, {f, ind + 1}); // L
	       	if (P[f] < 100 && pos_cnt[ind] > 0) upd(p, {ind, ind + 1}); // R
	}


	int ans = 0, emp = 0;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			if (!is_valid({i, j})) continue;
			if (dist[i][j] <= k) ans++;
			if (j == n && dist[i][j] < k && i < n && P[i] > 0 && P[n] > 0) emp = 1;	
		}
	} 

	printf("%d \n", ans + emp);
	return 0;
}