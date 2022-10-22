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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

// state: 0: ;), 1: red, 2: blue

bool Q[MAXN];
int state[MAXN], par[MAXN], c_par[MAXN], S[MAXN], C[3][MAXN], cost[MAXN], col[MAXN], tot_cost, n, k;
vector<int> V[MAXN], BP_C[MAXN], CC_C[MAXN];

inline void Update(int v, int c, bool neg = false) {
	state[v] = c;
	if (c == 0) {
		if (neg) tot_cost -= cost[v];
		cost[v] = min(C[1][v], C[2][v]);
		tot_cost += cost[v];
		return;
	}

	if (neg) tot_cost -= cost[v];
	cost[v] = C[c][v];
	tot_cost += cost[v];
}

inline void Union(int v, int u, int t1, int t2) {
	tot_cost -= cost[v];
	tot_cost -= cost[u];
	if (BP_C[v].size() > BP_C[u].size()) swap(v, u);
	if (col[t1] == col[t2]) {
		if (state[v]) state[v] = 3 - state[v];
		for (int e : BP_C[v]) col[e] = 3 - col[e];
		swap(C[1][v], C[2][v]);
	}

	for (int e : BP_C[v]) {
		c_par[e] = u;
		C[col[e]][u] += S[e];
		BP_C[u].push_back(e);
	}

	if (state[u] == 0) state[u] = state[v];
	Update(u, state[u]);
	BP_C[v].clear();
	C[1][v] = C[2][v] = 0;
}

inline void Union2(int v, int u) {
	if (CC_C[v].size() > CC_C[u].size()) swap(v, u);
	if (v == u) return;

	int t1 = u, t2 = v;
	u = c_par[u], v = c_par[v];

	if (u != v) {	
		tot_cost -= cost[v];
		tot_cost -= cost[u];
		
		if (BP_C[v].size() > BP_C[u].size()) swap(v, u);
		if (col[t1] != col[t2]) {
			if (state[v]) state[v] = 3 - state[v];
			for (int e : BP_C[v]) col[e] = 3 - col[e];
			swap(C[1][v], C[2][v]);
		}
		
		C[1][u] += C[1][v];
		C[2][u] += C[2][v];
		for (int e : BP_C[v]) {
			c_par[e] = u;
			BP_C[u].push_back(e);
		}

		if (state[u] == 0) state[u] = state[v];
		Update(u, state[u]);
		BP_C[v].clear();
		C[1][v] = C[2][v] = 0;
	}	
	

	u = t1;
	v = t2;
	for (int e : CC_C[v]) {
		par[e] = u;
		CC_C[u].push_back(e);
	}

	S[u] += S[v];
	S[v] = 0;	
	CC_C[v].clear();	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		Q[i] = (c == '1');
	}

	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		while (c--) {
			int e;
			cin >> e;
			V[e].push_back(i);
		}
		
		par[i] = i;
		CC_C[i].push_back(i);
		S[i] = 1;
		col[i] = 1;
		C[1][i] = 1;
		c_par[i] = i;
		BP_C[i].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (V[i].size() == 1) {
			int ind = V[i].front(), v = par[ind], p_st = c_par[v], c = col[v];
			if (Q[i]) Update(p_st, 3 - c, true);
			else Update(p_st, c, true);
		} else if (V[i].size() == 2) {
			int ind1 = V[i][0], ind2 = V[i][1], v = par[ind1], u = par[ind2], p1 = c_par[v], p2 = c_par[u];
			if (Q[i] == 0) {
				if (p1 != p2) Union(p1, p2, u, v);
			} else {
				Union2(u, v);
			}
		}
		
		cout << tot_cost << endl;
	}
	return 0;
}