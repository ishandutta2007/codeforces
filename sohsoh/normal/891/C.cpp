#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int par[MAXN], H[MAXN], n, m, q;
pair<pll, int> edges[MAXN];
vector<int> W[MAXN];
vector<pair<int, vector<int>>> QW[MAXN];
bool ans[MAXN];
stack<int> st;

inline bool cmp(int i, int j) { 
	return edges[i].Y < edges[j].Y;
}

int Find(int v) {
	if (v == par[v]) return v;
	return Find(par[v]);
}

inline bool Union(int v, int u) {
	v = Find(v), u = Find(u);
	if (v == u) {
		st.push(0);
		return false;
	}
	if (H[v] > H[u]) swap(v, u);
	if (H[v] == H[u]) H[u]++;
	par[v] = u;
	st.push(v);
	return true;
} 

inline void rollback() {
	if (!st.empty()) {
		int v = st.top();
		st.pop();
		par[v] = v;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = {{u, v}, w};
		W[w].push_back(i);
	}

	cin >> q;
	for (int t = 1; t <= q; t++) {
		ans[t] = true;
		int k;
		cin >> k;
		vector<int> qr;
		for (int i = 1; i <= k; i++) {
			int ind;
			cin >> ind;
			qr.push_back(ind);
		}

		sort(all(qr), cmp);
		for (int i = 0; i < (int)qr.size(); i++) {
			int ind = qr[i];
			if (i == 0 || edges[ind].Y != edges[qr[i - 1]].Y) QW[edges[ind].Y].push_back({t, {}});
			QW[edges[ind].Y].rbegin() -> Y.push_back(ind);
		}
	}
	
	for (int w = 1; w < MAXN; w++) {
		for (auto e : QW[w]) {
			int ind = e.X;
			vector<int> qr = e.Y;
			for (int edge : qr) ans[ind] &= Union(edges[edge].X.X, edges[edge].X.Y);
			for (int i = 0; i < qr.size(); i++) rollback();
		}

		for (int e : W[w]) Union(edges[e].X.X, edges[e].X.Y);
	}

	for (int i = 1; i <= q; i++) {
		if (ans[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}