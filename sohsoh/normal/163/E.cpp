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

int nxt[MAXN][SIG], F[MAXN], sz, fen[MAXN], tin[MAXN], tout[MAXN],
    t, I[MAXN], q, k;
bool B[MAXN];
vector<int> adj[MAXN];

inline int addTrie(string s) {
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

inline void update(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] += val;
}

inline void update(int l, int r, int val) {
	update(l, val);
	update(r + 1, -val);
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

void dfs(int v) {
	tin[v] = ++t;
	for (int u : adj[v])
		dfs(u);

	tout[v] = t;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> q >> k;
	for (int i = 1; i <= k; i++) {
		string s;
		cin >> s;
		I[i] = addTrie(s);
		B[i] = true;
	}

	buildAho();
	dfs(0);
	for (int i = 1; i <= k; i++)
		update(tin[I[i]], tout[I[i]], 1);

	while (q--) {
		char c;
		cin >> c;
		if (c == '?') {
			string s;
			cin >> s;

			ll ans = 0;
			int v = 0;
			for (char c : s) {
				v = nxt[v][c - 'a'];
				ans += query(tin[v]);
			}

			cout << ans << endl;
		} else if (c == '+') {
			int i;
			cin >> i;
			if (!B[i]) {
				update(tin[I[i]], tout[I[i]], 1);
				B[i] = true;
			}
		} else {
			int i;
			cin >> i;
			if (B[i]) {
				update(tin[I[i]], tout[I[i]], -1);
				B[i] = false;
			}
		}	
	}
	return 0;
}