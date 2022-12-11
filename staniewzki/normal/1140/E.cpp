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

	int n, k;
	cin >> n >> k;
	
	int mod = 998244353;
	VI v(n);
	REP(i, n)
	{
		cin >> v[i];
		if(i >= 2 && v[i] != -1 && v[i - 2] == v[i])
		{
			cout << "0\n";
			return 0;
		}
	}

	VLL dp[2];
	dp[0].RS(n + 1);
	dp[1].RS(n + 1);

	LL a = (LL) (k - 1) * (k - 2);
	a %= mod;
	LL b = a + 1;

	dp[0][1] = k - 1;
	dp[1][1] = k - 2;
	dp[0][2] = a;
	dp[1][2] = b;
	FOR(i, 3, n)
	{
		dp[0][i] = dp[0][i - 2] * (k - 1) + dp[1][i - 2] * a;
		dp[1][i] = dp[0][i - 2] * (k - 2) + dp[1][i - 2] * b;
		dp[0][i] %= mod;
		dp[1][i] %= mod;
	}

	DB(dp[0]);
	DB(dp[1]);

	VLL p(n + 1);
	p[0] = 1;
	FOR(i, 1, n)
		p[i] = (p[i - 1] * (k - 1)) % mod;

	LL ans = 1;
	REP(j, 2)
	{
		int beg = -1;
		int size = 0;
		for(int i = j; i < n; i += 2)
		{
			if(v[i] == -1)
				size++;
			else
			{
				if(size != 0)
				{
					if(beg == -1)
						ans = (ans * p[size]) % mod;
					else
						ans = (ans * dp[beg != v[i]][size]) % mod;
					DB(dp[beg != v[i]][size]);
					size = 0;
				}
				beg = v[i];
			}
		}

		if(size != 0 && beg != -1)
			ans = (ans * p[size]) % mod;
		else if(size != 0)
			ans = (ans * p[size - 1] * k) % mod;
	}

	cout << ans << "\n";
}