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
	
	int k, n;
	cin >> k >> n;
	VI v(k);
	REP(i, k) cin >> v[i];
	string s;
	cin >> s;

	char last = 0;
	int len = 0;
	LL ans = 0;
	VI curr;

	REP(i, k + 1)
	{
		if(i == k || last != s[i])
		{
			sort(curr.rbegin(), curr.rend());
			DB(curr);
			REP(j, min(n, len))
				ans += curr[j];
			curr.clear();
			len = 0;
		}	

		if(i != k)
		{
			DB(s[i]);
			len++;
			curr.EB(v[i]);
			last = s[i];
		}
	}

	cout << ans << "\n";
}