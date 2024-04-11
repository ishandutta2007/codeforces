// Sohsoh84 :)))
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

struct Fen {
	int n;
	vector<int> fen;
		
	Fen() {}

	Fen(int tn) {
		tn += 2;
		n = tn;
		fen.resize(n + 4);
	}

	inline void Add(int ind, int val) {
		for (++ind; ind < n; ind += ind & -ind)
			fen[ind] += val;
	}

	inline void Add(int L, int R, int val) {
		if (R < L) return;
		Add(L, val);
		Add(R + 1, -val);
	}

	inline int Query(int ind) {
		int ans = 0;
		for (++ind; ind > 0; ind -= ind & -ind)
			ans += fen[ind];
		return ans;		
	}
};

Fen F, A[MAXN];
int n, q, c, sz, id[MAXN], H[MAXN], ans1;
vector<int> adj[MAXN];

void dfs(int v, int p) {
	sz++;
	H[v] = H[p] + 1;
	id[v] = c;

	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	F = Fen(n);

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int u : adj[1]) {
		dfs(u, 1);
		A[c++] = Fen(sz);
		sz = 0;
	}

	while (q--) {
		int c;
		cin >> c;
		if (c == 0) {
			int v, x, d;
			cin >> v >> x >> d;
			if (v != 1) A[id[v]].Add(max({H[v] - d, d - H[v] + 1, 1}), min(H[v] + d, A[id[v]].n - 2), x);
			F.Add(1, d - H[v], x);
			if (d >= H[v]) ans1 += x;	
		} else {
			int v;
			cin >> v;
			if (v == 1) cout << ans1 << endl;
			else cout << A[id[v]].Query(H[v]) + F.Query(H[v]) << endl;
		}
	}
	return 0;
}