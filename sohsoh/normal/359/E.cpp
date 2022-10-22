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
 
const ll MAXN = 500 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN][MAXN], n, x_0, y_0;
bool vis[MAXN][MAXN];
vector<char> ans;

bool can(int x, int y, int delta_x, int delta_y) {
	while (x > 0 && y > 0 && y <= n && x <= n) {
		x += delta_x;
		y += delta_y;
		if (A[x][y] == 1) return true;
	}

	return false;
}

void turn_off(int x, int y) {
	if (A[x][y] == 1) A[x][y] = 0, ans.push_back('2');
}

void turn_on(int x, int y) {
	if (A[x][y] == 0) A[x][y] = 1, ans.push_back('1');
}

void dfs(int x, int y) {
	if (vis[x][y]) return;
	vis[x][y] = true;
	turn_on(x, y);
	if (can(x, y, 0, 1)) ans.push_back('R'), dfs(x, y + 1), ans.push_back('L');
	if (can(x, y, 0, -1)) ans.push_back('L'), dfs(x, y - 1), ans.push_back('R');
	if (can(x, y, 1, 0)) ans.push_back('D'), dfs(x + 1, y), ans.push_back('U');
	if (can(x, y, -1, 0)) ans.push_back('U'), dfs(x - 1, y), ans.push_back('D');
	turn_off(x, y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> x_0 >> y_0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];			
		}
	}

	dfs(x_0, y_0);
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (A[i][j] == 1) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	for (char c : ans) cout << c;
	cout << endl;
	return 0;
}