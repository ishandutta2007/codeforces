#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()

template<class T> void db(T a) { cerr << a; }
template<class L, class R> void db(pair<L, R> a) {cerr << "(" << a.ST << ", " << a.ND << ")";}
template<class T> void db(V<T> v) 
{ cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}"; }
template<class T> void dump(const char *s, T a) { cerr << s << ": "; db(a); cerr << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{ while(*s != ',') cerr<< *s++; cerr << ": "; db(a); dump(s + 1, x...); }

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__); 
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

	int n, m;
	cin >> n >> m;
	VVI a(n, VI(m));
	REP(i, n) REP(j, m) cin >> a[i][j];
	
	VVI x(n, VI(m));
	VVI y(n, VI(m));
	VI x_d(n);
	VI y_d(m);
	REP(i, n)
	{
		VI values;
		REP(j, m) values.EB(a[i][j]);
		sort(ALL(values));
		map<int, int> M;
		int id = 0;
		REP(j, m)
		{
			if(j == 0 || values[j] != values[j - 1])
				M[values[j]] = ++id;
		}

		REP(j, m)
			x[i][j] = M[a[i][j]];

		x_d[i] = id;
	}

	REP(j, m)
	{
		VI values;
		REP(i, n) values.EB(a[i][j]);
		sort(ALL(values));
		map<int, int> M;
		int id = 0;
		REP(i, n)
		{
			if(i == 0 || values[i] != values[i - 1])
				M[values[i]] = ++id;
		}

		REP(i, n)
			y[i][j] = M[a[i][j]];

		y_d[j] = id;
	}

	REP(i, n) DB(i, x[i]);
	REP(i, n) DB(i, y[i]);

	REP(i, n) REP(j, m)
	{
		int X = x[i][j];
		int Y = y[i][j];
		int X_d = x_d[i];
		int Y_d = y_d[j];
		if(X > Y) Y_d += X - Y;
		else X_d += Y - X;
		cout << max(X_d, Y_d) << " ";
		if(j + 1 == m) cout << "\n";
	}
}