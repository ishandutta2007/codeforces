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
	
	int n;
	cin >> n;

	V<V<bool>> table(n, V<bool>(n));
	REP(i, n)
	{
		REP(j, n / 4)
		{
			char x;
			cin >> x;

			int q;
			if('0' <= x && x <= '9') q = x - '0';
			else q = x - 'A' + 10;

			int k = (j + 1) * 4;
			REP(c, 4)
			{
				k--;
				table[i][k] = q % 2;
				q /= 2;
			}
		}
	}

	int ans = -1;
	REP(i, n)
	{
		DB(i, table[i]);
		int len = 0;
		REP(j, n)
		{
			if(j == 0 || table[i][j] == table[i][j - 1])
				len++;
			else
			{
				if(ans == -1)
					ans = len;
				else
					ans = __gcd(ans, len);
				len = 1;
			}
		}

		if(len != 0)
		{
			DB(len);
			if(ans == -1)
				ans = len;
			else
				ans = __gcd(ans, len);
		}
	}	

	REP(j, n)
	{
		int len = 0;
		REP(i, n)
		{
			if(i == 0 || table[i][j] == table[i - 1][j])
				len++;
			else
			{
				if(ans == -1)
					ans = len;
				else
					ans = __gcd(ans, len);
				len = 1;
			}
		}

		if(len != 0)
		{
			if(ans == -1)
				ans = len;
			else
				ans = __gcd(ans, len);
		}
	}

	cout << ans << "\n";
}