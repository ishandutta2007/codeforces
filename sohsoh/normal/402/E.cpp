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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int> adj[MAXN], adj_r[MAXN];
int n, lst;
bool vis[MAXN];

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = true;
	for (int u : adj[v]) dfs(u);
	lst = v;
}

void sfd(int v) {
	if (vis[v]) return;
	vis[v] = true;
	for (int u : adj_r[v]) sfd(u);
	lst = v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (x) adj[i].push_back(j), adj_r[j].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) dfs(i);
	memset(vis, false, sizeof vis);
	sfd(lst);

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	return 0;
}