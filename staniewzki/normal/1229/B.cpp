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

vector<LL> x;
vector<vector<int>> graph;
LL ans = 0;

void dfs(int v, int p, map<LL, int> &cnt) {
	map<LL, int> my_cnt;
	for(auto &p : cnt)
		my_cnt[__gcd(p.ST, x[v])] += p.ND;
	my_cnt[x[v]]++;	
	for(auto &p : my_cnt)
		ans = (ans + p.ST * p.ND) % int(1e9 + 7);
	for(int u : graph[v])
		if(u != p) dfs(u, v, my_cnt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	x.resize(n);
	REP(i, n) 
		cin >> x[i];

	graph.resize(n);
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].emplace_back(b - 1);
		graph[b - 1].emplace_back(a - 1);
	}

	map<LL, int> cnt;
	dfs(0, -1, cnt);

	cout << ans << "\n";
}