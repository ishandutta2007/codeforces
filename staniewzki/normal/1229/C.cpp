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

	vector<int> in(n), out(n);
	vector<vector<int>> graph(n);

	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if(a > b) swap(a, b);
		in[a]++, out[b]++;
		graph[a].emplace_back(b);
	}

	LL ans = 0;
	REP(i, n)
		ans += (LL) in[i] * out[i];
	cout << ans << "\n";

	int q;
	cin >> q;
	REP(i, q) {
		int v;
		cin >> v;
		v--;
		ans -= (LL) in[v] * out[v];
		for(int u : graph[v]) {
			ans -= (LL) in[u] * out[u];
			in[v]--, out[v]++;
			in[u]++, out[u]--;
			ans += (LL) in[u] * out[u];
			graph[u].emplace_back(v);
		}
		graph[v].clear();

		cout << ans << "\n";
	}
}