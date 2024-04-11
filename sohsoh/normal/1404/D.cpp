#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, from[MAXN], to[MAXN], from_val[MAXN], to_val[MAXN];
vector<int> vec[2], adj[MAXN];
ll s;
bool vis[MAXN], F[MAXN], edge_vis[MAXN];

void dfs(int v) {
	vis[v] = true;
	for (int ind : adj[v]) {
		if (!edge_vis[ind]) {
			ll x = (from_val[ind] % n == v ? from_val[ind] : to_val[ind]);
			F[x] = true;	
			edge_vis[ind] = true;
			s += x;
		}

		if (!vis[from[ind] ^ to[ind] ^ v]) dfs(from[ind] ^ to[ind] ^ v);
	}
}

int main() {
	cin >> n;
	if (n % 2 == 0) {
		cout << "First" << endl;
		for (int i = 1; i <= n; i++) cout << i << sep;
		for (int i = 1; i <= n; i++) cout << i << sep;
		return cout << endl, 0;
	}

	cout << "Second" << endl;
	for (int i = 1; i <= 2 * n; i++) {
		int ind;
		cin >> ind;
		if (from_val[ind]) {
			to_val[ind] = i;
			to[ind] = i % n;
			adj[from[ind]].push_back(ind);
			adj[to[ind]].push_back(ind);
		} else {
			from_val[ind] = i;
			from[ind] = i % n;
		}
	}


	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(i);

	int x = 0;
	if (s % (2 * n) == 0) x = 1;
	for (int i = 1; i <= 2 * n; i++)
		if (F[i] == x)
			cout << i << sep;
	cout << endl;
	return 0;
}