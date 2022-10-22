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

const ll MAXN = 5e4 + 10; //
const ll LOG = 8; //
const ll LOG2 = 20;
const ll SQ = (1 << LOG);

int par[MAXN], par256[MAXN], n, q, A[MAXN], H[MAXN], 
    nxt[(SQ + 5) * LOG2][2], sz = 1, ans[MAXN][MAXN / SQ + 3];
vector<int> adj[MAXN];

inline void addTrie(int val) {
	int v = 1;
	for (int i = LOG2 - 1; i >= 0; i--) {
		if (nxt[v][val >> i & 1]) v = nxt[v][val >> i & 1];
		else v = nxt[v][val >> i & 1] = ++sz;
	}
}

inline int maxXor(int val) {
	int v = 1, ans = 0;
	for (int i = LOG2 - 1; i >= 0; i--) {
		if (nxt[v][(val >> i & 1) ^ 1]) {
			v = nxt[v][(val >> i & 1) ^ 1];
			ans ^= (1 << i);
		} else v = nxt[v][val >> i & 1];
	}

	return ans;
}

void dfs(int v, int p) {
	par[v] = p;
	for (int u : adj[v]) {
		if (u == p) continue;
		H[u] = H[v] + 1;
		dfs(u, v);
	}

	if (H[v] + 1 >= SQ) {
		memset(nxt, 0, sizeof nxt);
		sz = 1;

		int tv = v, cnt = 0;
		while (cnt < SQ) {
			addTrie(cnt ^ A[v]);
			cnt++;	
			v = par[v];
		}

		for (int i = 0; i < MAXN / SQ + 2; i++)
			ans[tv][i] = maxXor(i * SQ);

		par256[tv] = v;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	H[0] = -1;

	while (q--) {
		int u, v;
		cin >> u >> v;
		int tv = v;

		int fans = 0, ind = 0;
		while (H[v] >= SQ - 1 && H[par256[v]] >= H[u] - 1) {
			fans = max(fans, ans[v][ind++]);
			v = par256[v];
		}

		while (H[v] >= H[u]) {
			fans = max(fans, A[v] ^ (H[tv] - H[v]));	
			v = par[v];
		}

		cout << fans << endl;
	}
	return 0;
}