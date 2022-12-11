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

	int n, q;
	cin >> n >> q;
	VPII v(q);
	VI cnt(n + 1);
	for(PII &x : v)
	{
		cin >> x.ST >> x.ND;
		FOR(i, x.ST, x.ND)
			cnt[i]++;
	}

	VI only(q);
	VVI avi(n + 1);
	REP(i, q)
	{
		PII x = v[i];
		FOR(j, x.ST, x.ND)
		{
			if(cnt[j] == 1)
				only[i]++;
			if(cnt[j] == 2)
				avi[j].EB(i);
		}
	}

	int ans = 0;
	int total = 0;

	REP(i, n + 1) if(cnt[i] != 0) total++;

	DB(v);
	DB(cnt);
	DB(only);
	DB(avi);
	DB(total);
	
	REP(i, q)
	{
		VI tmp = only;
		PII x = v[i];
		FOR(j, x.ST, x.ND)
		{
			cnt[j]--;
			if(cnt[j] == 1) for(int k : avi[j]) if(k != i) tmp[k]++;
		}

		DB(i, tmp);

		FOR(j, x.ST, x.ND) cnt[j]++;

		int mn = 1e9;
		REP(r, q) if(r != i)  mn = min(mn, tmp[r]);
		ans = max(ans, total - only[i] - mn);
	}

	cout << ans << "\n";
}