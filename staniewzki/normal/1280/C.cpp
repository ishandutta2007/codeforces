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

LL ans;
vector<vector<PII>> adj;
int dfs(int v, int p = -1) {
	int sz = 1;
	for(auto [u, w] : adj[v]) {
		if(u != p) {
			if(dfs(u, v)) {
				sz ^= 1;
				ans += w;
			}
		}
	}
	return sz;
}

int centro;
int get(int v, int p = -1) {
	int sz = 1;
	bool good = true;
	for(auto [u, w] : adj[v]) if(u != p) {
		int x = get(u, v);
		sz += x;
		if(x * 2 > size(adj)) good = false;
	}
	if((size(adj) - sz) * 2 > size(adj)) good = false;
	if(good) centro = v;
	return sz;
}

int cal(int v, int p = -1) {
	int sz = 1;
	for(auto [u, w] : adj[v]) {
		if(u != p) {
			int x = cal(u, v);
			sz += x;
			ans += LL(w) * x;
		}
	}
	return sz;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(it, t) {
		int n;
		cin >> n;
		n *= 2;

		adj.clear();
		adj.resize(n);
		REP(i, n - 1) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a - 1].emplace_back(b - 1, c);
			adj[b - 1].emplace_back(a - 1, c);
		}

		ans = 0;
		dfs(0);
		LL G = ans;

		get(0);
		debug(centro);

		ans = 0;
		cal(centro);
		LL B = ans;
		cout << G << " " << B << "\n";
	}
}