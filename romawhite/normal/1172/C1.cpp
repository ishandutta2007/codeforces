#include "bits/stdc++.h"
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const Int LINF = INF * (Int) INF;
 
const int MAX = 57;
 
const int MOD = 998244353;

int A[MAX];
int W[MAX];

Int dp[MAX][MAX][MAX];

Int bpow(Int a, int k)
{
	Int res = 1;
	while (k)
	{
		if (k & 1)
		{
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		k /= 2;
	}
	return res;
}

int main(int argc, char* argv[])
{
	// freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	FOR(i,0,n)
		cin >> A[i];
	FOR(i,0,n)
		cin >> W[i];
	
	FOR(i,0,n)
	{
		int SA = W[i];
		int SPLUS = 0;
		int SMINUS = 0;
		FOR(j,0,n)
		{
			if (A[j])
				SPLUS += W[j];
			else
				SMINUS += W[j];
		}
		FILL(dp, 0);
		dp[0][0][0] = 1;
		FOR(it,0,m)
			FOR(a,0,it + 1)
				FOR(b,0,it + 1)
				{
					if (!dp[it][a][b]) continue;
					if (a + b > it) break;
					int c = it - a - b;
					int sa = SA;
					int sp = SPLUS + b;
					int sm = SMINUS - c;
					if (A[i] == 1)
					{
						sa += a;
						sp += a;
					}
					else
					{
						sa -= a;
						sm -= a;
					}
					Int q = bpow(sp + sm, MOD - 2);
					dp[it + 1][a + 1][b] += dp[it][a][b] * sa % MOD * q % MOD;
					dp[it + 1][a + 1][b] %= MOD;
					if (A[i] == 1)
					{
						dp[it + 1][a][b + 1] += dp[it][a][b] * (sp - sa) % MOD * q % MOD;
						dp[it + 1][a][b + 1] %= MOD;
						dp[it + 1][a][b] += dp[it][a][b] * sm % MOD * q % MOD;
						dp[it + 1][a][b] %= MOD;
					} else {
						dp[it + 1][a][b + 1] += dp[it][a][b] * sp % MOD * q % MOD;
						dp[it + 1][a][b + 1] %= MOD;
						dp[it + 1][a][b] += dp[it][a][b] * (sm - sa) % MOD * q % MOD;
						dp[it + 1][a][b] %= MOD;
					}
				}
		Int res = 0;
		FOR(a,0,MAX)
			FOR(b,0,MAX)
			{
				if (A[i] == 1)
				{
					res += dp[m][a][b] * (SA + a);
					res %= MOD;
				}
				else
				{
					res += dp[m][a][b] * (SA - a);
					res %= MOD;
				}
			}
		cout << res << endl;
	}

	// cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
}