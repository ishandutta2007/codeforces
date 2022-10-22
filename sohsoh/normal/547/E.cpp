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
const ll SIG = 26;

int n, q, t, nxt[MAXN][SIG], F[MAXN], fen[MAXN], 
    tin[MAXN], tout[MAXN], sz, ans[MAXN];
vector<int> adj[MAXN], vec[MAXN];
vector<pair<int, pll>> S[MAXN];

inline int addTrie(string s, int ind) {
	int v = 0;
	for (char c : s) {
		if (nxt[v][c - 'a']) v = nxt[v][c - 'a'];
		else v = nxt[v][c - 'a'] = ++sz;
	
		vec[ind].push_back(v);
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

void dfs(int v) {
	tin[v] = ++t;
	for (int u : adj[v])
		dfs(u);
	tout[v] = t;
}

inline void update(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] += val;
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

inline int query(int l, int r) {
	return query(r) - query(l - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		addTrie(s, i);
	}

	buildAho();
	dfs(0);

	for (int i = 1; i <= q; i++) {
		int l, r, ind;
		cin >> l >> r >> ind;
		S[l - 1].push_back({i, {vec[ind].back(), -1}});
		S[r].push_back({i, {vec[ind].back(), 1}});
	}

	for (int i = 1; i <= n; i++) {
		for (int e : vec[i])
			update(tin[e], 1);

		for (auto Q : S[i])
			ans[Q.X] += query(tin[Q.Y.X], tout[Q.Y.X]) * Q.Y.Y;
	}

	for (int i = 1; i <= q; i++) cout << ans[i] << endl;
	return 0;
}