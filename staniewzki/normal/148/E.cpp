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
	VVI dp(n + 1, VI(m + 1));
	FOR(i, 1, n)
	{
		int k;
		cin >> k;
		VI val(k);
		REP(j, k) cin >> val[j];

		VI len(k + 1);
		int left = 0;
		REP(l, k)
		{
			left += (l != 0 ? val[l - 1] : 0);
			int right = 0;
			for(int r = 0; r + l <= k; r++)
			{
				right += (r != 0 ? val[k - r] : 0);
				len[l + r] = max(len[l + r], left + right);
			}
		}

		DB(i, len);

		FOR(j, 1, m)
		{
			FOR(l, 0, min(j, k))
				dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + len[l]);
		}
	}

	cout << dp[n][m] << "\n";
}