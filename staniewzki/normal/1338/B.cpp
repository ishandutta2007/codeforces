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

vector<vector<int>> adj;

vector<int> dep;
void dfs(int v, int p = -1) {
	for(int u : adj[v]) {
		if(u != p) {
			dep[u] = dep[v] + 1;
			dfs(u, v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	adj.resize(n);
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].emplace_back(b - 1);
		adj[b - 1].emplace_back(a - 1);
	}

	dep.resize(n);
	dfs(0);
	int leaf_dep = -1, same = true;
	REP(i, n) {
		if(size(adj[i]) == 1) {
			if(leaf_dep == -1) leaf_dep = dep[i] % 2;
			if(leaf_dep != dep[i] % 2) {
				same = false;
			}
		}
	}

	cout << (same ? 1 : 3) << " ";

	vector<int> used(n);
	int ans = n - 1;
	REP(i, n) if(size(adj[i]) == 1) {
		if(used[adj[i][0]]) ans--;
		else used[adj[i][0]] = true;
	}

	cout << ans << "\n";
}