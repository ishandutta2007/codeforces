/*
    Soheil Mohammadkhani
    final test contest on vim
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 2000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll vis[MAXN][MAXN] = {0}, n, m;
char G[MAXN][MAXN];

int main() {
	fast_io;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];
		}
	}

	queue<pll> q1, q2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) vis[i][j] = 1, q1.push({i, j});
			else {
				if (G[i][j] != G[i - 1][j] || G[i][j] != G[i][j - 1] || G[i][j] != G[i + 1][j] || G[i][j] != G[i][j + 1]) vis[i][j] = 1, q1.push({i, j});
			}
		}
	} 

	while (!q1.empty()) {
		pll p = q1.front();
		q1.pop();
		//if (p.X == 2 && p.Y == 1) debug(vis[2][1])
		if (p.X > 0 && vis[p.X - 1][p.Y] == 0) {
			vis[p.X - 1][p.Y] = vis[p.X][p.Y] + 1;
			q1.push({p.X - 1, p.Y});
		}
	
		if (p.X < n - 1 && vis[p.X + 1][p.Y] == 0) {
                        vis[p.X + 1][p.Y] = vis[p.X][p.Y] + 1;
                        q1.push({p.X + 1, p.Y});
                }
		
		if (p.Y > 0 && vis[p.X][p.Y - 1] == 0) {
                        vis[p.X][p.Y - 1] = vis[p.X][p.Y] + 1;
                        q1.push({p.X, p.Y - 1});
                }

		if (p.Y < m - 1 && vis[p.X][p.Y + 1] == 0) {
                        vis[p.X][p.Y + 1] = vis[p.X][p.Y] + 1;
                        q1.push({p.X, p.Y + 1});
                }

	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += vis[i][j];
		//	cout << vis[i][j];	
		}

		//cout << endl;
	}

	cout << ans << endl;
}