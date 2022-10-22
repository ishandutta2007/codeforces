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

const ll MAXN = 2e6 + 10;

int cmp, pos[MAXN], n, q, par[MAXN], f[MAXN];
vector<int> C[MAXN];
set<pll> st; // pos, cmp

inline int init(int i, int x) {
	pos[++cmp] = x;
	par[cmp] = cmp;
	f[i] = cmp;
	C[cmp].push_back(cmp);
	st.insert({x, cmp});
	
	return cmp;
}

inline void unite(int u, int v, int p) {	
	if (u == v) return;
	if (C[u].size() < C[v].size()) swap(u, v);

	st.erase({pos[v], v});
	st.erase({pos[u], u});
	pos[u] = p;
	st.insert({pos[u], u});
	
	for (int e : C[v]) {
		par[e] = u;
		C[u].push_back(e);
	}

	C[v].clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		init(i, x);
	}

	int tmp = n;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;

		if (c == 1) {
			int k, w;
			cin >> k >> w;
			init(k, w);
		} else if (c == 3) {
			int l, r;
			cin >> l >> r;
			l--, r++;

			int cl = init(++tmp, l);
			int cr = init(++tmp, r);

			auto it = st.lower_bound({l + 1, -1});
			while (it != st.end() && (it -> X) < r) {
				int p = it -> X, c = it -> Y;
				if (p - l < r - p) unite(cl, c, l);
				else unite(cr, c, r);
				
				it = st.lower_bound({l + 1, -1});
				
				cl = par[cl];
				cr = par[cr];
			}	
		} else {
			int x;
			cin >> x;
			cout << pos[par[f[x]]] << endl;
		}
	}
	return 0;
}