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

V<VPII> g;
LL t;
VI s;

int DFS(int v = 0, int p = -1)
{
	int ret = 1;
	for(PII a : g[v])
	{
		int u = a.ST;
		int c = a.ND;
		if(u != p)
		{
			LL x = DFS(u, v);
			if(c) s.EB(x);
			else ret += x;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, k;
	cin >> n >> k;
	t = n;
	g.RS(n);
	REP(i, n - 1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a - 1].EB(b - 1, c);
		g[b - 1].EB(a - 1, c);
	}

	s.EB(DFS());
	int q = S(s);
	LL sum = 1;
	LL mod = 1e9 + 7;
	REP(i, k) sum = (sum * n) % mod;
	REP(j, q)
	{
		LL ret = 1;
		REP(i, k) ret = (ret * s[j]) % mod;
		sum = (sum - ret + mod) % mod;
	}
	cout << sum << "\n";
}