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

	int n;
	cin >> n;
	VPII v(n);
	REP(i, n)
	{
		char x;
		cin >> x;
		v[i].ST = x - '0';
	}

	REP(i, n)
	{
		char x;
		cin >> x;
		v[i].ND = x - '0';
	}

	int a = 0, b = 0, c = 0, d = 0;
	REP(i, n)
	{
		if(v[i] == PII(1, 0)) a++;
		if(v[i] == PII(0, 1)) b++;
		if(v[i] == PII(1, 1)) c++;
		if(v[i] == PII(0, 0)) d++;
	}

	REP(x, n / 2 + 1)
	{
		FOR(a1, 0, min(a, 2 * x - c))
		{
			int b2 = 2 * x - c - a1;
			int c1 = x - a1;
			int c2 = x - b2;
			int a2 = a - a1;
			int b1 = b - b2;
			int d1 = n / 2 - x - b1;
			int d2 = n / 2 - x - a2;
			if(a1 + b1 + c1 + d1 == a2 + b2 + c2 + d2 && 0 <= b2 && b2 <= b && c1 + c2 == c && 0 <= c1 && 0 <= c2 && 0 <= a2 && 0 <= d1 && 0 <= d2 && d1 + d2 == d)
			{
				DB(a1, b1, c1, d1, a2, b2, c2, d2);
				REP(i, n)
				{
					auto out = [&]() { cout << i + 1 << " "; };
					if(v[i] == PII(1, 0) && a1-- > 0) out();
					if(v[i] == PII(0, 1) && b1-- > 0) out();
					if(v[i] == PII(1, 1) && c1-- > 0) out();
					if(v[i] == PII(0, 0) && d1-- > 0) out();
				}

				return 0;
			}
		}	
	}

	cout << "-1\n";
}