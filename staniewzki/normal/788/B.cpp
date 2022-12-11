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

vector<vector<int>> graph;
vector<bool> vis;
void dfs(int v)
{
	vis[v] = true;
	for(int u : graph[v])
		if(!vis[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, m;
	cin >> n >> m;
	graph.resize(n);
	LL c = 0;
	vector<int> e(n);
	REP(i, m)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u]++, e[v]++;
		if(u == v) c++;
		else
		{
			graph[u].EB(v);
			graph[v].EB(u);
		}
	}

	vis.resize(n);
	REP(i, n)
	{
		if(e[i] != 0)
		{
			dfs(i);
			break;
		}
	}

	REP(i, n) if(!vis[i] && e[i] != 0)
	{
		cout << "0\n";
		return 0;
	}

	LL ans = c * (m - c) + c * (c - 1) / 2;
	DB(c, (m - c));
	REP(i, n)
	{
		LL deg = graph[i].size();
		DB(i, deg);
		ans = ans + deg * (deg - 1) / 2;
	}

	cout << ans << "\n";
}