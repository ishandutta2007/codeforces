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
#include <assert.h>
#include <time.h>


#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 4007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int dp[2][MAX][MAX][2];
int a[MAX];
int s[MAX];

int Get(int l, int r)
{
	return s[r + 1] - s[l];
}

int main() {

	//freopen("in.txt" , "r" , stdin);

	int n;
	cin >> n;
	FOR(i,0,n)
	{
		cin >> a[i];
	}
	FOR(i,1,n + 1)
	{
		s[i] = s[i - 1] + a[i - 1];
	}

	int it = 0;

	int prev = 0;
	int next = 1;

	RFOR(step , 100, 1)
	{
		int minTake = step * (step - 1) / 2;

		RFOR(len,n + 1 , minTake)
		{
			FOR(player , 0 , 2)
			{
				FOR(tl,len / 2 - step / 2 - 3 , len / 2 + step / 2 + 3)
				{
					if (tl < 0) continue;
					if (tl > len) continue;
					int tr = len - tl;
					int l = tl;
					int r = n - 1 - tr;

					if (player == 0)
					{

						int val = -INF;

						if (l + step - 1 <= r)
						{
							val = max(val , Get(l, l + step - 1) + dp[prev][l + step][r + 1][1]);
						}
						else
						{
							val = 0;
						}
						if (l + step<= r)
						{
							val = max(val , Get(l, l + step) + dp[next][l + step + 1][r + 1][1]);
						}

						dp[prev][l][r + 1][0] = val;

					}
					else
					{
						int val = INF;
						if (l + step - 1 <= r)
						{
							val = min(val , -Get(r - step + 1, r) + dp[prev][l][r - step + 1][0]);
						}
						else
						{
							val = 0;
						}
						if (l + step<= r)
						{
							val = min(val , -Get(r - step , r) + dp[next][l][r - step][0]);
						}
						dp[prev][l][r + 1][1] = val;


					}


				}
			}
		}
		swap(prev , next);
	}

	cout << dp[next][0][n][0] << endl;

    return 0;
}