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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n), r(n);
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		g[a - 1].emplace_back(b - 1);
		r[b - 1].emplace_back(a - 1);
	}

	int k;
	cin >> k;
	vector<int> p(k);
	REP(i, k) cin >> p[i], p[i]--;

	auto bfs = [&](int s, vector<vector<int>> &adj) {
		vector<int> dst(n, -1);
		dst[s] = 0;
		deque<int> Q;
		Q.emplace_back(s);

		while(!Q.empty()) {
			int v = Q.front();
			Q.pop_front();

			for(int u : adj[v]) {
				if(dst[u] == -1) {
					dst[u] = dst[v] + 1;
					Q.emplace_back(u);
				}
			}
		}

		return dst;
	};

	auto rev = bfs(p.back(), r);
	debug(rev);

	int mn = 0, mx = 0;
	REP(i, k - 1) {
		int v = p[i], u = p[i + 1];
		debug(v, u, rev[v], rev[u]);
		if(rev[v] - 1 != rev[u]) {
			mn++, mx++;
			continue;
		}

		int cnt = 0;
		for(int x : g[v]) {
			if(rev[v] - 1 == rev[x])
				cnt++;
		}

		if(cnt != 1) mx++;
	}

	cout << mn << " " << mx << "\n";
}