#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == --x.end() ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#ifdef DEBUG
  const int seed = 1;
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (#x != "" ? #x ":  " : ""), dump(x), Nl(), cerr
#else
  const int seed = chrono::system_clock::now().time_since_epoch().count();
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(seed);
int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

int mod = 998244353;
LL mul(LL a, LL b) { return (a * b) % mod; }
int fpow(int a, int n)
{
	if(n == 0) return 1;
	if(n % 2 == 1) return mul(a, fpow(a, n - 1));
	LL f = fpow(a, n / 2);
	return mul(f, f);
}

vector<vector<int>> graph;
array<vector<int>, 3> dp;

void dfs(int v = 0, int p = -1)
{
	// 0 - niezmatchowany
	// 1 - zmatchowany
	// 2 - niezmatchowany, a chcemy eby zmatchowany
	
	dp[0][v] = 1;
	dp[1][v] = 1;
	for(int u : graph[v]) if(u != p)
	{
		dfs(u, v);
		dp[0][v] = mul(dp[0][v], dp[0][u]);
		dp[1][v] = mul(dp[1][v], dp[0][u] + dp[2][u]);
	}

	for(int u : graph[v]) if(u != p)
	{
		LL q = mul(dp[1][v], fpow(dp[0][u] + dp[2][u] , mod - 2));
		dp[2][v] += mul(dp[1][u], q);
		if(dp[2][v] >= mod) dp[2][v] -= mod;
	}

	dp[0][v] += dp[2][v];
	if(dp[0][v] >= mod) dp[0][v] -= mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	graph.resize(n);
	REP(i, n - 1)
	{
		int u, v;
		cin >> u >> v;
		graph[u - 1].emplace_back(v - 1);
		graph[v - 1].emplace_back(u - 1);
	}

	for(auto &vec : dp)
		vec.resize(n);
	dfs();	

	cout << dp[0][0] << "\n";
}