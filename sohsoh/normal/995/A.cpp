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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll G[4][MAXN], g_prim[4][MAXN];
ll n, k;
vector<pair<ll, pll>> ans;

void move(ll i, ll j) {
	if (G[i][j] <= 0) return;
	if (i == 2 && j == 0) {
		g_prim[1][0] = G[2][0];
		ans.push_back({G[2][0], {1, 0}});
		return;
	} 

	if (i == 1 && j == n - 1) {
		g_prim[2][n - 1] = G[1][n - 1];
		ans.push_back({G[1][n - 1], {2, n - 1}});
		return;
	}

	if (i == 1) {
		g_prim[i][j + 1] = G[i][j];
		ans.push_back({G[i][j], {i, j + 1}});
	} else if (i == 2) {
		g_prim[i][j - 1] = G[i][j];
		ans.push_back({G[i][j], {i, j - 1}});
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			cin >> G[i][j];
		}
	}

	ll op = 0;
	while (op < 2000) {
		for (int i = 0; i < n; i++) {
			if (G[1][i] > 0 && G[0][i] == G[1][i]) {
				ans.push_back({G[1][i], {0, i}});
				G[0][i] = G[1][i];
				G[1][i] = 0;
			}

			if (G[2][i] > 0 && G[3][i] == G[2][i]) {
				ans.push_back({G[2][i], {3, i}});
				G[3][i] = G[2][i];
				G[2][i] = 0;
			}
		}	

		ll cnt = 0;
		pll free;
		for (int i = 0; i < n; i++) {
			if (G[1][i]) cnt++;
			else free = {1, i};
			if (G[2][i]) cnt++;
			else free = {2, i};			
		}

		if (cnt == 2 * n) break;

		fill(g_prim[1], g_prim[1] + n + 10, 0);
		fill(g_prim[2], g_prim[2] + n + 10, 0);
		
		if (free.X == 1) {
			for (int i = free.Y; i >= 0; i--) move(1, i);	
			for (int i = 0; i < n; i++) move(2, i);
			for (int i = n - 1; i > free.Y; i--) move(1, i);	
		} else if (free.X == 2) {
			for (int i = free.Y; i < n; i++) move(2, i);
			for (int i = n - 1; i >= 0; i--) move(1, i);
			for (int i = 0; i < free.Y; i++) move(2, i);
		}

		for (int i = 0; i < n; i++) G[1][i] = g_prim[1][i], G[2][i] = g_prim[2][i];
		op++;
	}

	for (int i = 0; i < n; i++) {
		if (G[1][i] || G[2][i]) return cout << -1 << endl, 0;
	}	
	
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < n; j++) cout << G[i][j] << sep;
//		cout << endl;
//	}

	cout << ans.size() << endl;
	for (pair<ll, pll> e : ans) {
		cout << e.X << sep << e.Y.X + 1 << sep << e.Y.Y + 1 << endl;
	}
	return 0;
}