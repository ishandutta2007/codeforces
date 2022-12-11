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
template<class L, class R> void db(pair<L, R> a) { cerr << "(" << a.ST << ", " << a.ND << ")"; }
template<class T> void db(V<T> v) { cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}"; }
template<class T> void dump(const char *s, T a){ cerr << s << ": "; db(a); cerr << "\n"; }
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

	string str;
	cin >> str;

	int n = S(str);
	bool all_letters_same = true;
	REP(i, n) if(str[i] != str[0] && i * 2 + 1 != n) all_letters_same = false;
	if(all_letters_same)
	{
		cout << "Impossible\n";
		return 0;
	}

	FOR(q, 1, n - 1)
	{
		string s = str;
		REP(i, n)
		{
			int pos = (i + q) % n;
			s[i] = str[pos];
		}

		DB(q, s);

		bool is_palindrome = true;
		REP(i, n)
		{
			int pos = n - 1 - i;
			if(s[i] != s[pos]) is_palindrome = false;	
		}

		if(is_palindrome && str != s)
		{
			cout << 1 << "\n";
			return 0;
		}
	}

	cout << 2 << "\n";
}