
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
const int MAX = 200007;
const int MAX2 = 1000007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

VI A[3];

int dp[77][77][77][3];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	string s;
	cin >> n >> s;

	FOR(i,0,SZ(s))
	{
		if (s[i] == 'V')
		{
			A[0].push_back(i);
		}
		if (s[i] == 'K')
		{
			A[1].push_back(i);
		}
		if (s[i] != 'V' && s[i] != 'K')
		{
			A[2].push_back(i);
		}
	}

	FOR(i,0,77)
		FOR(j,0,77)
			FOR(k,0,77)
				FOR(t,0,3)
					dp[i][j][k][t] = INF;

	dp[0][0][0][2] = 0;

	FOR(i,0,SZ(A[0]) + 1)
	{
		FOR(j,0,SZ(A[1]) + 1)
		{
			FOR(k,0,SZ(A[2]) + 1)
			{
				FOR(t,0,3)
				{
					if (dp[i][j][k][t] == INF) continue;
					if (i < SZ(A[0]))
					{
						int pos1 = i + j + k;

						int pos2 = A[0][i];

						FOR(ii,0,i)
						{
							if (A[0][ii] > A[0][i]) ++ pos2;
						}
						FOR(jj,0,j)
						{
							if (A[1][jj] > A[0][i]) ++ pos2;
						}
						FOR(kk,0,k)
						{
							if (A[2][kk] > A[0][i]) ++ pos2;
						}

						dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0] , dp[i][j][k][t] + abs(pos1 - pos2));
					}
					if (j < SZ(A[1]) && t != 0)
					{
						int pos1 = i + j + k;
						int pos2 = A[1][j];


						FOR(ii,0,i)
						{
							if (A[0][ii] > A[1][j]) ++ pos2;
						}
						FOR(jj,0,j)
						{
							if (A[1][jj] > A[1][j]) ++ pos2;
						}
						FOR(kk,0,k)
						{
							if (A[2][kk] > A[1][j]) ++ pos2;
						}

						dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1] , dp[i][j][k][t] + abs(pos1 - pos2));
					}
					if (k < SZ(A[2]))
					{
						int pos1 = i + j + k;
						int pos2 = A[2][k];


						FOR(ii,0,i)
						{
							if (A[0][ii] > A[2][k]) ++ pos2;
						}
						FOR(jj,0,j)
						{
							if (A[1][jj] > A[2][k]) ++ pos2;
						}
						FOR(kk,0,k)
						{
							if (A[2][kk] > A[2][k]) ++ pos2;
						}

						dp[i][j][k + 1][2] = min(dp[i][j][k + 1][2] , dp[i][j][k][t] + abs(pos1 - pos2));
					}
				}
			}
		}
	}


	int res = min(dp[SZ(A[0])][SZ(A[1])][SZ(A[2])][0] , min(dp[SZ(A[0])][SZ(A[1])][SZ(A[2])][1] , dp[SZ(A[0])][SZ(A[1])][SZ(A[2])][2]));

	cout << res << endl;

    return 0;
}