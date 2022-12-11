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
void dfs(int v, vector<int> &par, vector<int> &sub) {
	for(int u : adj[v]) if(u != par[v]) {
		par[u] = v;
		dfs(u, par, sub);
		sub[v] += sub[u];
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

	vector<vector<int>> par(n, vector<int>(n, -1));
	vector<vector<int>> sub(n, vector<int>(n, 1));
	REP(i, n) dfs(i, par[i], sub[i]);

	vector<vector<LL>> dp(n, vector<LL>(n, -1));
	function<LL(int, int)> get_dp;
	get_dp = [&](int a, int b) -> LL {
		if(a == b) return 0;
		LL &ret = dp[a][b];
		if(ret != -1) return ret;
		ret = (LL) sub[a][b] * sub[b][a];
		ret += max(get_dp(a, par[a][b]), get_dp(b, par[b][a]));
		return ret;
	};

	LL ans = 0;
	REP(i, n) REP(j, n) ans = max(ans, get_dp(i, j));
	cout << ans << "\n";
}