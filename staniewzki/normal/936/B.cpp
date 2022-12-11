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
vector<array<int, 2>> vis;

void dfs(int v, int t, int last = -1) {
	debug(v, t, last);
	vis[v][t] = last;
	for(int u : adj[v]) {
		if(vis[u][t ^ 1] == -2)
			dfs(u, t ^ 1, v);
	}
}

vector<int> on_stack;
bool cycle = false;
void cyc(int v) {
	on_stack[v] = 1;
	for(int u : adj[v]) {
		if(on_stack[u] == -1)
			cyc(u);
		else if(on_stack[u])
			cycle = true;
	}
	on_stack[v] = 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	adj.resize(n);
	REP(i, n) {
		int deg;
		cin >> deg;
		REP(j, deg) {
			int k;
			cin >> k;
			adj[i].emplace_back(k - 1);
		}

		debug(i, adj[i]);
	}

	int s;
	cin >> s;
	vis.resize(n, {-2, -2});
	dfs(s - 1, 0);

	REP(i, n) {
		if(size(adj[i]) == 0 && vis[i][1] != -2) {
			cout << "Win\n";	
			vector<int> out;
			int t = 1;
			while(i != -1) {
				out.emplace_back(i);
				i = vis[i][t];
				t ^= 1;
			}
			reverse(out.begin(), out.end());
			for(int v : out) cout << v + 1 << " ";
			cout << "\n";
			return 0;
		}
	}

	on_stack.resize(n, -1);
	cyc(s - 1);

	if(cycle) cout << "Draw\n";
	else cout << "Lose\n";
}