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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	REP(i, n) REP(j, m)
	{
		char c;
		cin >> c;
		v[i][j] = (c == '*');
	}

	int centr = 0;
	FOR(i, 1, n - 2) FOR(j, 1, m - 2)
	{
		if(v[i][j] && v[i - 1][j] && v[i + 1][j] && v[i][j - 1] && v[i][j + 1])
			centr++;
	}

	if(centr != 1)
	{
		cout << "NO\n";
		return 0;
	}

	FOR(i, 1, n - 2) FOR(j, 1, m - 2)
	{
		if(v[i][j] && v[i - 1][j] && v[i + 1][j] && v[i][j - 1] && v[i][j + 1])
		{
			int x = i, y = j;
			DB(x, y);
			while(x != 0 && v[x - 1][y]) v[--x][y] = 0;
			x = i, y = j;
			while(x != n - 1 && v[x + 1][y]) v[++x][y] = 0;
			x = i, y = j;
			while(y != 0 && v[x][y - 1]) v[x][--y] = 0;
			x = i, y = j;
			while(y != m - 1 && v[x][y + 1]) v[x][++y] = 0;
		}
	}

	REP(i, n)
		DB(i, v[i]);

	int cnt = 0;
	REP(i, n) REP(j, m)
		if(v[i][j]) cnt++;

	if(cnt == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
}