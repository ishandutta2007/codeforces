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

vector<LL> b, w;
vector<int> sz;
vector<vector<int>> adj;
vector<vector<pair<int, LL>>> dp;

void dfs(int v = 0, int p = -1) {
	sz[v] = 1;
	dp[v].emplace_back(0, b[v]);
	for(int u : adj[v]) {
		if(u != p) {
			dfs(u, v);
			b[v] += b[u];

			vector<pair<int, LL>> nxt(sz[v] + sz[u], {-1e9, 0});
			for(int i = 0; i < sz[v]; i++) {
				for(int j = 0; j <= sz[u]; j++) {
					auto p1 = dp[v][i], p2 = dp[u][j];
					p1.ST += p2.ST, p1.ND += p2.ND;
					nxt[i + j] = max(nxt[i + j], p1);
				}
			}

			dp[v] = nxt;
			sz[v] += sz[u];
		}
	}

	dp[v].emplace_back(-1e9, 0);
	for(int i = sz[v]; i >= 1; i--) {
		auto m = dp[v][i - 1];
		m.ST += (m.ND > 0), m.ND = 0;
		dp[v][i] = max(dp[v][i], m);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(it, t) {
		int n, m;
		cin >> n >> m;
		auto re = [&](auto &vec) {
			vec.clear();
			vec.resize(n);
		};

		re(b), re(w);
		REP(i, n) cin >> b[i];
		REP(i, n) {
			cin >> w[i];
			b[i] = w[i] - b[i];
		}

		re(adj), re(dp);
		REP(i, n - 1) {
			int a, b;
			cin >> a >> b;
			adj[a - 1].emplace_back(b - 1);
			adj[b - 1].emplace_back(a - 1);
		}

		re(sz);
		dfs();

		auto d = dp[0][m - 1];
		if(d.ND > 0) d.ST++;
		cout << d.ST << "\n";
	}
}