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

const ll MAXN = 2e3 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, k;
bool vis[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	queue<pair<int, int>> q;
	while (k--) {
		int x, y;
		cin >> x >> y;
		q.push({x, y});
		vis[x][y] = true;
	}

	pair<int, int> ans;
	while (!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		ans = q.front();
		q.pop();
		if (x > 1 && !vis[x - 1][y]) vis[x - 1][y] = true, q.push({x - 1, y});
		if (y > 1 && !vis[x][y - 1]) vis[x][y - 1] = true, q.push({x, y - 1});
		if (x < n && !vis[x + 1][y]) vis[x + 1][y] = true, q.push({x + 1, y});
		if (y < m && !vis[x][y + 1]) vis[x][y + 1] = true, q.push({x, y + 1});
	}

	cout << ans.X << sep << ans.Y << endl;
	return 0;
}