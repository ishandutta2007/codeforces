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

vector<vector<PII>> adj;
vector<array<LL, 2>> dp;
int k;

void dfs(int v, int p) {
	vector<LL> profit;
	for(PII e : adj[v]) {
		int u = e.ST;
		if(u == p) continue;
		dfs(u, v);
		profit.emplace_back(dp[u][1] + e.ND);
		dp[v][0] += dp[u][0];
	}

	sort(profit.rbegin(), profit.rend());

	LL b = 0;
	REP(i, min(k, size(profit))) {
		b += max(0LL, profit[i]);
	}
	dp[v][0] += b;
	
	if(size(profit) >= k) 
		dp[v][1] = -max(0LL, profit[k - 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	REP(_q, q) {
		int n;
		cin >> n >> k;
	
		adj.clear();
		adj.resize(n);
		REP(i, n - 1) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a - 1].emplace_back(b - 1, c);
			adj[b - 1].emplace_back(a - 1, c);
		}

		dp.clear();
		dp.resize(n, array<LL, 2>{0, 0});

		dfs(0, -1);

		cout << dp[0][0] << "\n";
	}
}