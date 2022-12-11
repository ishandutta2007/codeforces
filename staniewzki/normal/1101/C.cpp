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

template<class T> void db(T a) {cerr << a;}
template<class L, class R> void db(pair<L, R> a) {cerr << "(" << a.ST << ", " << a.ND << ")";}
template<class T> void db(V<T> v) 
{cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}";}
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

	int t;
	cin >> t;
	REP(_t, t)
	{
		int n;
		cin >> n;
		VPII s(n);
		VPII e;
		REP(i, n)
		{
			cin >> s[i].ST >> s[i].ND;
			e.EB(s[i].ST, 0);
			e.EB(s[i].ND, 1);
		}

		sort(ALL(e));

		int pos = -1;
		int open = 0;
		REP(i, 2 * n)
		{
			PII &x = e[i];
			
			if(x.ND == 0)
				open++;
			else
				open--;
			
			if(open == 0 && i != 2 * n - 1)
			{
				pos = x.ST;
				break;
			}
		}

		DB(e);

		if(pos == -1)
		{
			cout << "-1\n";
			continue;
		}
			
		REP(i, n)
		{
			if(s[i].ST <= pos)
				cout << "1 ";
			else
				cout << "2 ";
		}

		cout << "\n";
	}
}