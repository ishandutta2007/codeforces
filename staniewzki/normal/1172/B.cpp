#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) for(int i = 0; i < a; i++)
#define EB emplace_back
#define ST first
#define ND second

using LL = long long;
using PII = pair<int, int>;

template<class L, class R> ostream& operator<<(ostream &ost, pair<L, R> p)
{
	return ost << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> ostream& operator<<(ostream &ost, vector<T> &vec)
{
	ost << "{";
	REP(i, vec.size()) ost << (i == 0 ? "" : ", ") << vec[i];
	return ost << "}";
}

template<class T> void dump(const char *s, T a) { cerr << s << ": " << a << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{
	while(*s != ',') cerr << *s++;
	cerr << ": " << a;
	dump(s + 1, x...);
}

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__)
#else
#define DB(...)
#endif

mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) { return uniform_int_distribution<int>(a, b)(_gen); }

vector<vector<int>> graph;
LL mod = 998244353;

LL fact(int k)
{
	LL ret = 1;
	for(LL i = 2; i <= k; i++)
		ret = (ret * i) % mod;
	return ret;
}

vector<LL> dp;
void DFS(int v, int p = -1)
{
	int size = (v != 0);
	dp[v] = (v == 0 ? dp.size() : 1);
	for(int u : graph[v]) if(u != p)
	{
		DFS(u, v);
		size++;
		dp[v] = (dp[v] * dp[u]) % mod;
	}

	dp[v] = (dp[v] * fact(size)) % mod;
	DB(v, dp[v]);
}

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n;
	cin >> n;
	graph.resize(n);
	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1].EB(b - 1);
		graph[b - 1].EB(a - 1);
	}

	dp.resize(n);
	DFS(0);
	cout << dp[0] << "\n";
}