#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000000;
const int MAX = 200007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int dp[2][107][1007];

int main()
{
    //freopen("in.txt",  "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n , m;
	cin >> n >> m;
	vector<int> a(n);
	FOR(i,0,n)
	{
		cin >> a[i];
	}
	sort(ALL(a));

	dp[0][0][0] = 1;
	int prev = 0;
	int next = 1;

	FOR(i,0,n)
	{
		FILL(dp[next] , 0);
		FOR(j,0,n / 2 + 1)
		{
			FOR(k,0,m + 1)
			{
				if (!dp[prev][j][k]) continue;

				int delta = 0;
				if (i != n - 1)
				{
					delta = a[i + 1] - a[i];
				}

				if (k + (j + 1) * delta <= m)
				{
					dp[next][j + 1][k + (j + 1) * delta] += dp[prev][j][k];
					dp[next][j + 1][k + (j + 1) * delta] %= MOD;
				}
				if (k + j * delta <= m)
				{
					dp[next][j][k + j * delta] += 1LL * dp[prev][j][k] * (j + 1) % MOD;
					dp[next][j][k + j * delta] %= MOD;
				}


				if (j > 0 && k + (j - 1) * delta <= m)
				{
					dp[next][j - 1][k + (j - 1) * delta] += 1LL * dp[prev][j][k] * j % MOD;
					dp[next][j - 1][k + (j - 1) * delta] %= MOD;
				}
			}
		}
		swap(prev , next);
	}

	int res = 0;
	FOR(i,0,m + 1)
	{
		res += dp[prev][0][i];
		res %= MOD;
	}

	cout << res << endl;

    return 0;
}