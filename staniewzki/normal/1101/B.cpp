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

	string str;
	cin >> str;
	int state = 0;
	int id = -1;
	REP(i, S(str))
	{
		if(state == 0 && str[i] == '[')
			state++;
		if(state == 1 && str[i] == ':')
		{
			id = i;
			break;
		}
	}

	if(id == -1)
	{
		cout << -1 << "\n";
		return 0;
	}

	state = 0;
	int eid = -1;
	for(int i = S(str) - 1; i >= 0; i--)
	{
		if(state == 0 && str[i] == ']')
			state++;
		if(state == 1 && str[i] == ':')
		{
			eid = i;
			break;
		}
	}

	if(eid == -1 || eid <= id)
	{
		cout << -1 << "\n";
		return 0;
	}

	int ans = 4;
	FOR(i, id + 1, eid - 1)
		if(str[i] == '|')
			ans++;

	cout << ans << "\n";
}