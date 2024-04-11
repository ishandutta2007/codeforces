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

const ll MAXN = 3e5 + 10;
const ll SIG = 26;

int n, q, I[MAXN], nxt[MAXN][SIG], trie_sz, F[MAXN], val[MAXN],
    sg[MAXN << 2], sz[MAXN], hvy[MAXN], head[MAXN], id[MAXN], t, par[MAXN];
vector<int> adj[MAXN];
multiset<int> st[MAXN];

inline int addTrie(string& s) {
	int v = 0;
	for (char c : s) {
		if (nxt[v][c - 'a']) v = nxt[v][c - 'a'];
		else v = nxt[v][c - 'a'] = ++trie_sz;
	}

	return v;
}

inline void buildAho() {
	queue<int> q;
	for (int i = 0; i < SIG; i++)
		if (nxt[0][i])
			q.push(nxt[0][i]);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		adj[F[v]].push_back(v);

		for (int i = 0; i < SIG; i++) {
			if (nxt[v][i]) {
				F[nxt[v][i]] = nxt[F[v]][i];
				q.push(nxt[v][i]);
			} else nxt[v][i] = nxt[F[v]][i];
		}
	}
}

void hld(int v) {
	hvy[v] = 0;
	for (int u : adj[v]) {
		par[u] = v;
		hld(u);
		sz[v] += sz[u];

		if (!hvy[v] || sz[u] > sz[hvy[v]])
			hvy[v] = u;
	}
}

void dfs(int v) {
	id[v] = ++t;
	if (hvy[v]) {
		head[hvy[v]] = head[v];
		dfs(hvy[v]);
	} 

	for (int u : adj[v])
		if (u != hvy[v])
			head[u] = u, dfs(u);
} 

void update(int ind, int val, int l = 1, int r = MAXN - 2, int v = 1) {
	if (l == r) sg[v] = val;
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) update(ind, val, l, mid, v << 1);
		else update(ind, val, mid + 1, r, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

int query(int ql, int qr, int l = 1, int r = MAXN - 2, int v = 1) {
	if (ql > r || qr < l) return -1;
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return max(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	fill(sg, sg + (MAXN << 2), -1);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		I[i] = addTrie(s);
		st[I[i]].insert(0);
	}

	buildAho();
	hld(0);
	dfs(0);
	for (int i = 1; i <= n; i++) update(id[I[i]], 0);

	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int ind;
			cin >> ind;
			st[I[ind]].erase(st[I[ind]].find(val[ind]));

			cin >> val[ind];
			st[I[ind]].insert(val[ind]);
			
			update(id[I[ind]], *st[I[ind]].rbegin());
		} else {
			string s;
			cin >> s;
			int ans = -1;

			int tv = 0;
			for (char c : s) {
				tv = nxt[tv][c - 'a'];
				int v = tv;
				while (v) {
					ans = max(ans, query(id[head[v]], id[v]));
					v = par[head[v]];
				}
			}	

			cout << ans << endl;
		}
	}
	return 0;
}