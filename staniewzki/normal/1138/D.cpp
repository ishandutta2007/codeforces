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

	string s, t;
	cin >> s >> t;

	int n = S(s);
	int m = S(t);
	VI pi(m);

	pi[0] = 0;
	int len = 0;
	int pos = 1;

	while(pos < m)
	{
		if(t[pos] == t[len])
		{
			len++;
			pi[pos] = len;
			pos++;
		}
		else
		{
			if(len != 0)
				len = pi[len - 1];	
			else
				pi[pos] = 0, pos++;
		}
	}

	int a = 0, b = 0;
	REP(i, n)
	{
		if(s[i] == '0') a++;
		else b++;
	}

	m -= pi[m - 1];
	pos = 0;
	REP(i, n)
	{
		DB(i);
		if(t[pos] == '0' && a != 0) cout << 0, a--;
		else if(t[pos] == '0') cout << 1, b--;
		else if(t[pos] == '1' && b != 0) cout << 1, b--;
		else cout << 0, a--;		

		pos++;
		if(pos == m) pos = 0;
	}	
	cout << "\n";
}