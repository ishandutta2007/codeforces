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

vector<vector<int>> adj, rev;
vector<int> vis, ord;

void get_post(int v, int &t) {
	vis[v] = true;
	for(int u : rev[v])
		if(not vis[u])
			get_post(u, t);
	ord[t++] = v;
}

void mark_scc(int v) {
	vis[v] = true;
	for(int u : adj[v])
		if(not vis[u])
			mark_scc(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(_t, t) {
		int n, m;
		cin >> n >> m;

		adj.clear();
		adj.resize(n);
		rev = adj;
		REP(i, m) {
			int a, b;
			cin >> a >> b;
			adj[a - 1].emplace_back(b - 1);
			rev[b - 1].emplace_back(a - 1);
		}

		ord.clear();
		ord.resize(n);
		vis = ord;
		int tm = 0;
		REP(i, n) if(not vis[i])
			get_post(i, tm);

		fill(vis.begin(), vis.end(), false);
		mark_scc(ord[n - 1]);
	
		vector<int> l, r;
		REP(i, n) {
			if(vis[i]) l.emplace_back(i);
			else r.emplace_back(i);
		}

		if(size(r) == 0)
			cout << "No\n";
		else {
			cout << "Yes\n";
			cout << size(l) << " " << size(r) << "\n";
			auto out = [&](auto v) {
				for(int x : v) cout << x + 1 << " ";
				cout << "\n";
			};
			out(l), out(r);
		}
	}
}