#include<bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }

using LL = long long;
using PII = pair<int, int>;

vector<vector<int>> graph;
vector<int> par, sz, dep;

int get_size(int v) {
	for(int u : graph[v]) {
		dep[u] = dep[v] + 1;
		sz[v] = max(sz[v], get_size(u) + 1);
	}
	return sz[v];
}

vector<int> ord, out;
int t = 0;
void trav(int v) {
	ord[t++] = v;
	vector<PII> adj;
	for(int u : graph[v])
		adj.emplace_back(sz[u], u);
	sort(adj.begin(), adj.end());
	for(auto [s, u] : adj)
		trav(u);
	out[v] = t;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	graph.resize(n);
	dep = ord = out = sz = par = vector<int>(n);
	FOR(i, 1, n - 1){
		cin >> par[i];
		graph[par[i]].emplace_back(i);
	}

	get_size(0);
	trav(0);

	vector<int> m;
	debug(dep);
	FOR(i, 1, n - 1) {
		debug(i, ord[i - 1], ord[i]);
		REP(j, dep[ord[i - 1]] - dep[ord[i]] + 1)
			m.emplace_back(ord[i]);
	}

	for(int x : ord) cout << x << " ";
	cout << "\n" << size(m) << "\n";
	for(int x : m) cout << x << " ";
	cout << "\n";
}