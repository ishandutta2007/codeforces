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
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 4007;
 
const int MOD = 998244353;
 
const double Pi = acos(-1.0);
 
bool r[MAX];
bool c[MAX];


int dpR[MAX][MAX];
int dpC[MAX][MAX];

Int C[MAX][MAX];
Int F[MAX];

int main(int argc, char* argv[])
{
    // freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false); cin.tie(0);
 
	F[0] = 1;
	FOR(i,1,MAX)
		F[i] = F[i - 1] * i % MOD;
	
	FOR(i,0,MAX)
	{
		C[i][0] = C[i][i] = 1;
		FOR(j,1,i)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}

    int h, w, n;
	cin >> h >> w >> n;

	FOR(i,0,n)
	{
		int x1, y1, x2 , y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;--y1;--x2;--y2;
		r[x1] = r[x2] = 1;
		c[y1] = c[y2] = 1;
	}

	dpR[0][0] = 1;
	FOR(i,0,h)
		FOR(j,0,i + 1)
		{
			if (dpR[i][j] == 0)
				continue;
			dpR[i + 1][j] += dpR[i][j];
			dpR[i + 1][j] %= MOD;

			if(i + 1 < h && !r[i] && !r[i + 1])
			{
				dpR[i + 2][j + 1] += dpR[i][j];
				dpR[i + 2][j + 1] %= MOD;
			} 
		}

	dpC[0][0] = 1;
	FOR(i,0,w)
		FOR(j,0,i + 1)
		{
			if (dpC[i][j] == 0)
				continue;
			dpC[i + 1][j] += dpC[i][j];
			dpC[i + 1][j] %= MOD;

			if(i + 1 < w && !c[i] && !c[i + 1])
			{
				dpC[i + 2][j + 1] += dpC[i][j];
				dpC[i + 2][j + 1] %= MOD;
			} 
		}


	Int res = 0;

	int freeR = 0;
	int freeC = 0;
	FOR(i,0,h)
		if (!r[i])
			++freeR;
	FOR(i,0,w)
		if (!c[i])
			++freeC;

	FOR(r,0,h + 1)
		FOR(c,0,w + 1)
		{
			if (dpR[h][r] == 0 || dpC[w][c] == 0)
				continue;
			
			if (2 * r + c > freeR)
				continue;
			if (2 * c + r > freeC)
				continue;
			
			Int val = (Int)dpR[h][r] * dpC[w][c] % MOD;
			val *= C[freeC - 2 * c][r] * F[r] % MOD;
			val %= MOD;
			val *= C[freeR - 2 * r][c] * F[c] % MOD;
			val %= MOD;
			// cout << r << ' ' << c << ' ' << val << endl;
			res += val;
			res %= MOD;
		}

	cout << res << endl;

 
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
    
}