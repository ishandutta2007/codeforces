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
 
const ll MAXN = 5e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll P1, P2, n, m;
char A[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pair<char, pll>> ans;

void dfs(int i, int j, bool no_par = false) {
	if (vis[i][j]) return;
	vis[i][j] = true;
	if (i < 1 || j < 1 || i > n || j > m || A[i][j] == '#') return;
	ans.push_back({'B', {i, j}});
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j + 1);
	dfs(i, j - 1);
	if (!no_par) {
		ans.push_back({'D', {i, j}});
		ans.push_back({'R', {i, j}});
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> A[i][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dfs(i, j, true);
	cout << ans.size() << endl;
	for (auto e : ans) cout << e.X << sep << e.Y.X << sep << e.Y.Y << endl;
	return 0;
}