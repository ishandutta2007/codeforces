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

vector<int> val;
vector<string> type;
vector<vector<int>> adj;

void dfs(int v) {
	for(int u : adj[v])
		dfs(u);

	if(type[v] == "NOT")
		val[v] = !val[adj[v][0]];
	else if(type[v] == "AND")
		val[v] = val[adj[v][0]] & val[adj[v][1]];
	else if(type[v] == "OR")
		val[v] = val[adj[v][0]] | val[adj[v][1]];
	else if(type[v] == "XOR")
		val[v] = val[adj[v][0]] ^ val[adj[v][1]];
}

vector<int> c;
void dfs2(int v, int s) {
	c[v] = s;
	if(type[v] == "AND" && val[adj[v][0]] == 0 && val[adj[v][1]] == 0)
		s = true;
	if(type[v] == "OR" && val[adj[v][0]] == 1 && val[adj[v][1]] == 1)
		s = true;

	if(size(adj[v]) == 2)
		debug(v, type[v], val[adj[v][0]], val[adj[v][1]]);

	for(int u : adj[v]) {
		if(type[v] == "AND" && val[u] == 1 && val[v] == 0) dfs2(u, 1);
		else if(type[v] == "OR" && val[u] == 0 && val[v] == 1) dfs2(u, 1);
		else dfs2(u, s);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	type.resize(n);
	adj.resize(n);
	val.resize(n);

	vector<int> in;
	REP(i, n) {
		cin >> type[i];
		if(type[i] == "IN") {
			cin >> val[i];
			in.emplace_back(i);
		}
		else if(type[i] == "NOT") {
			adj[i].resize(1);
			cin >> adj[i][0];
			adj[i][0]--;
		}
		else {
			adj[i].resize(2);
			cin >> adj[i][0] >> adj[i][1];
			adj[i][0]--;
			adj[i][1]--;
		}
	}

	c.resize(n);
	dfs(0);
	debug(val);
	dfs2(0, 0);
	debug(c);

	int def = val[0];
	for(int x : in) 
		cout << (def ^ c[x] ^ 1);
	cout << "\n";
}