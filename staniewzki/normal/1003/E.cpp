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

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, d, k;
	cin >> n >> d >> k;

	auto no_ans = []() { cout << "NO\n"; exit(0); };
	if(k == 1 && n > 2) no_ans();
	if(d >= n) no_ans();

	vector<int> dist(n);
	vector<vector<int>> graph(n);
	vector<int> Q;
	int added = d + 1;
	REP(i, d + 1)
	{
		if(i != 0) graph[i].EB(i - 1);
		if(i != d) graph[i].EB(i + 1);
		dist[i] = max(i, d - i);
		Q.EB(i);
	}

	while(!Q.empty() && added != n)
	{
		int v = Q.back();
		if(graph[v].size() == k || dist[v] == d)
		{
			Q.pop_back();
			continue;
		}

		graph[v].EB(added);
		graph[added].EB(v);
		dist[added] = dist[v] + 1;
		Q.EB(added++);
	}

	if(added != n) no_ans();
	cout << "YES\n";
	REP(i, n)
		for(int j : graph[i])
			if(i < j) cout << i + 1 << " " << j + 1 << "\n";
}