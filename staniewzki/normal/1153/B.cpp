#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define V vector
#define EB emplace_back
#define ST first
#define ND second

template<class T> ostream& operator<<(ostream &ost, V<T> &vec)
{
	ost << "{";
	REP(i, vec.size()) ost << (i == 0 ? "" : ", ") << vec[i];
	return ost << "}";
}

template<class L, class R> ostream& operator<<(ostream &ost, pair<L, R> p)
{
	return ost << "(" << p.ST << ", " << p.ND << ")";
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

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, m, h;
	cin >> n >> m >> h;

	VI a(m);
	REP(i, m)
		cin >> a[i];

	VI b(n);
	REP(i, n)
		cin >> b[i];

	VVI ans(n, VI(m));

	REP(i, n) REP(j, m)
		cin >> ans[i][j];

	REP(i, n)
	{
		REP(j, m)
			if(ans[i][j] == 1)
				ans[i][j] = a[j];
	}

	REP(i, n)
	{
		REP(j, m)
		{
			ans[i][j] = min(ans[i][j], b[i]);
		}
	}

	REP(i, n)
	{
		REP(j, m)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}