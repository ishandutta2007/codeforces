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
 
const ll MAXN = 5000 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int vis[MAXN], n;
pll pos[MAXN];

int dist(int i, int j) {
	return abs(pos[i].X - pos[j].X) + abs(pos[i].Y - pos[j].Y);
}

bool dfs(int v, ll d) {
	for (int i = 1; i <= n; i++) {
		if (i == v || dist(i, v) <= d) continue;
		if (!vis[i]) {
			vis[i] = 3 - vis[v];
			if (!dfs(i, d)) return false; 
		}
		else if (vis[i] == vis[v]) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> pos[i].X >> pos[i].Y;
	int L = 0, R = int(1e4 + 10);
	while (L < R) {
		int mid = (L + R) / 2;
		memset(vis, 0, sizeof vis);
		bool can = true;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				vis[i] = 1;
				if (!dfs(i, mid)) {
					can = false;
					break;
				}
			}
		}

		
		if (can) R = mid;
		else L = mid + 1;
	}

	cout << L << endl;
	memset(vis, 0, sizeof vis);
	int C = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			C++;
			vis[i] = 1;
			dfs(i, L);
		}
	}

	cout << poww(2, C, MOD) << endl;
	return 0;
}