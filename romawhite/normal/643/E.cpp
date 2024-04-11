#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 500007;
const int MAX2 = 207;
const int BASE = 1000000000;
const int CNT = 500;
const int MOD = 1000000007;

double dp[MAX][107];

int p[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);

	int n = 1;
	p[0] = -1;

	FOR(i,0,107)
	{
		dp[0][i] = 1;
	}

	int q;
	cin >> q;
	FOR(qq,0,q)
	{
		int t;
		scanf("%d" , &t);
		if (t == 1)
		{
			int par;
			scanf("%d" , &par);
			--par;
			int v = n;
			p[v] = par;
			++ n;
			FOR(j,0,107)
			{
				dp[v][j] = 1;
			}
			double prevV = dp[par][0];
			dp[par][0] *= 0.5;
			int j = 1;
			while (p[par] != -1 && j <= 102)
			{
				int pp = p[par];
				double pV = dp[pp][j];
				dp[pp][j] /= (0.5 + 0.5 * prevV);

				prevV = pV;
				dp[pp][j] *= (0.5 + 0.5 * dp[par][j - 1]);
				par = pp;
				++j;
			}

		}
		else
		{
			int v;
			scanf("%d" , &v);
			--v;
			double res = 0;

			FOR(i,1,100)
			{
				res += (dp[v][i] - dp[v][i - 1]) * i;
			}
			printf("%.10f\n" , res);
		}
	}

    return 0;
}