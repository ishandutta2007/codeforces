#include <bits/stdc++.h>

#pragma GCC optimize("no-stack-protector,unroll-loops,fast-math")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 5e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int par[MAXN], n, m, q, A[MAXN], ind;
bool b_edge[MAXN], used_val[MAXN];
vector<pair<int, int>> edges, r_edge, Q;
vector<int> C[MAXN];
set<int> st[MAXN];
stack<vector<int>> rev_st;

inline void union_sets(int u, int v, bool undo_t = false) {
	u = par[u];
	v = par[v];
	if (u == v) {
		if (undo_t) rev_st.push({});
		return;
	}

	if (C[u].size() < C[v].size()) swap(u, v);
	
	if (undo_t) rev_st.push(C[v]);
	for (int e : C[v]) {
		C[u].push_back(e);
		if (!used_val[A[e]]) st[u].insert(A[e]);
		par[e] = u;
	}

	C[v].clear();
	st[v].clear();
}

inline void undo_edge() {	
	vector<int> v = rev_st.top();
	rev_st.pop();
	for (int e : v) {
		if (!used_val[A[e]]) {
			st[par[e]].erase(A[e]);
			st[ind].insert(A[e]);
		}

		par[e] = ind;
		C[ind].push_back(e);
	}

	ind++;
}

inline int query(int v) {
	v = par[v];
	if (st[v].empty()) return 0;
	int ans = *st[v].rbegin();
	st[v].erase(ans);
	used_val[ans] = true;
	return ans;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%d", A + i), par[i] = i, C[i].push_back(i), st[i].insert(A[i]);
	ind = n + 1;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edges.push_back({u, v});
	}

	while (q--) {
		int i, v;
		scanf("%d %d", &i, &v);
		Q.push_back({i, v});
		if (i == 2) r_edge.push_back(edges[v - 1]), b_edge[v] = true;
	}


	for (int i = 0; i < edges.size(); i++) {
		if (!b_edge[i + 1]) {
			union_sets(edges[i].X, edges[i].Y);
		}
	}
		
	reverse(all(r_edge));
	for (pair<int, int> e : r_edge) {
		union_sets(e.X, e.Y, true);
	}
		
	for (pair<int, int> qr : Q) {
		if (qr.X == 2) {
			undo_edge();
		} else {
			printf("%d \n", query(qr.Y));
		}
	}
	return 0;
}