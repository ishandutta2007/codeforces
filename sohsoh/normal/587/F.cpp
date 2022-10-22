#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const int MAXN = 1e5 + 10; 
const int SQ = 200;
const int SIG = 26;

int tin[MAXN], tout[MAXN], nxt[MAXN][SIG], sz, t,
    F[MAXN], C[MAXN / SQ + 5][MAXN], n, q, I[MAXN], T[MAXN];
string S[MAXN];
vector<pair<int, pll>> Q[MAXN];
vector<int> adj[MAXN];
ll ans[MAXN];

void dfs(int v) {
	tin[v] = ++t;
	for (int u : adj[v])
		dfs(u);
	tout[v] = t;
}

void t_dfs(int v) {
	for (int u : adj[v]) {
		T[u] += T[v];
		t_dfs(u);
	}
}

inline int addTrie(string& s) {
	int v = 0;
	for (char c : s) {
		if (nxt[v][c - 'a']) v = nxt[v][c - 'a'];
		else v = nxt[v][c - 'a'] = ++sz;
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
		I[i] = addTrie(S[i]);
	}

	buildAho();
	dfs(0);
	for (int i = 0; i * SQ < n; i++) {
		int l = i * SQ, r = min(n - 1, l + SQ - 1);
		memset(T, 0, sizeof T);

		for (int j = l; j <= r; j++)
			T[I[j]]++;

		t_dfs(0);
		for (int j = 0; j < n; j++) {
			int v = 0;
			for (char c : S[j]) {
				v = nxt[v][c - 'a'];
				C[i][j] += T[v];
			}
		}
	}

	for (int i = 1; i <= q; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		l--, r--, k--;

		if (r / SQ <= l / SQ + 1) {
			Q[k].push_back({i, {l, r}});
			continue;
		}

		if (l % SQ) {
			int tl = l;
			l = (l / SQ + 1) * SQ;
			Q[k].push_back({i, {tl, l - 1}});
		}

		if (r % SQ != SQ - 1) {
			Q[k].push_back({i, {r - r % SQ, r}});
			r -= r % SQ + 1;
		} 

		for (int j = l / SQ; j <= r / SQ; j++)
			ans[i] += C[j][k];
	}

	for (int i = 0; i < n; i++) {
		vector<int> vec;
		int v = 0;

		for (char c : S[i]) {
			v = nxt[v][c - 'a'];
			vec.push_back(tin[v]);
		}

		sort(all(vec));
		for (auto e : Q[i]) {
			int ind = e.X;
			for (int v = e.Y.X; v <= e.Y.Y; v++)
				ans[ind] += upper_bound(all(vec), tout[I[v]]) - lower_bound(all(vec), tin[I[v]]);
		}
	}

	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}