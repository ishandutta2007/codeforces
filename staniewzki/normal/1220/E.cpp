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
 
mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) {
	return uniform_int_distribution<int>(a, b)(_gen);
}

vector<int> w;
vector<vector<int>> graph;
vector<bool> vis;
vector<LL> dp;
LL sum = 0;

bool dfs(int v, int par = -1) {
	vis[v] = true;
	bool ret = false;
	for(int u : graph[v]) {
		if(not vis[u]) {
			ret |= dfs(u, v);
			dp[v] = max(dp[v], dp[u]);
		}
		else ret |= u != par;
	}

	if(ret) sum += w[v];
	else dp[v] += w[v];

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	w.resize(n);
	REP(i, n) cin >> w[i];	

	graph.resize(n);
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].emplace_back(b - 1);
		graph[b - 1].emplace_back(a - 1);
	}

	int s;
	cin >> s;

	vis.resize(n);
	dp.resize(n);
	dfs(s - 1);	
	cout << sum + dp[s - 1] << "\n";
}