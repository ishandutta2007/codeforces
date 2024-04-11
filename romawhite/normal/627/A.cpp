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
const int BASE = 1000000007;
const int MAX = 100007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

Int dp[50][2];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	Int s , x;
	cin >> s >> x;
	if (x > s)
	{
		cout << 0 << endl;
		return 0;
	}

	dp[0][0] = 1;
	FOR(i,0,47)
	{
		FOR(j,0,2)
		{
			if (!dp[i][j]) continue;
			FOR(a,0,2)
			{
				FOR(b,0,2)
				{
					int ss = 0;
					if (s & (1LL << i)) ss = 1;
					int xx = 0;
					if (x & (1LL << i)) xx = 1;
					if ((a ^ b) != xx) continue;
					if ((a + b + j) % 2 != ss) continue;
					dp[i + 1][(a + b + j) / 2] += dp[i][j];
				}
			}
		}
	}

	if (s == x) dp[47][0] -= 2;

	cout << dp[47][0] << endl;


    return 0;
}