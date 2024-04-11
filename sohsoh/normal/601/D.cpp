#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll P1 = 12121;
const ll P2 = 317;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

ll ans[MAXN], C[MAXN], n, H[MAXN];
pll hsh[MAXN];
set<pll> st[MAXN];
char S[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	H[v] = H[p] + 1;
	hsh[v].X = (hsh[p].X * P1 + S[v]) % MOD;
	hsh[v].Y = (hsh[p].X * P2 + (S[v] * H[v])) % MOD2;
	st[v].insert(hsh[v]);

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);

		bool flag = false;
		if (st[v].size() < st[u].size()) {
			swap(v, u);
			flag = true;
		}

		for (pll e : st[u]) st[v].insert(e);
		if (flag) st[v].swap(st[u]), swap(v, u);
	}

	ans[v] = C[v] + st[v].size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 1; i <= n; i++) cin >> S[i];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	ll mx = *max_element(ans + 1, ans + n + 1);
	cout << mx << endl << count(ans + 1, ans + n + 1, mx) << endl;
	return 0;
}