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
#include <functional>
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
const double Pi = acos(-1.0);

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;

int a[100007];
int b[100007];

int dp[100007][307];
vector<int> nx[100007];

int main()
{
	//freopen("in.txt" , "r" , stdin);
	
	int n,m,s,e;
	
	cin >> n >> m >> s >> e;

	FOR(i,0,n)
	{
		cin >> a[i];
	}
	FOR(i,0,m)
	{
		cin >> b[i];
		nx[b[i]].push_back(i);
	}

	int k = s / e;
	FOR(i,0,100007)
		FOR(j,0,307)
			dp[i][j] = INF;

	dp[0][0] = 0;

	int res = 0;

	FOR(i,0,n + 1)
	{
		FOR(j,0,k + 1)
		{
			if (dp[i][j] == INF)
				continue;

			int E = j * e + i + dp[i][j];
			if (E <= s)
			{
				res = max(res , j);
			}
			else
			{
				continue;
			}

			if (i == n)
			{
				continue;
			}

			dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j]);

			if (nx[a[i]].size() > 0 && nx[a[i]].back() >= dp[i][j])
			{
				int L = 0;
				int R = nx[a[i]].size() - 1;
				while (R - L > 1)
				{
					int X = (L + R) / 2;
					if (nx[a[i]][X] >= dp[i][j])
					{
						R = X;
					}
					else
					{
						L = X;
					}
				}
				if (nx[a[i]][L] >= dp[i][j])
				{
					R = L;
				}
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1] , nx[a[i]][R] + 1);
			}
		}
	}

	cout << res << endl;

	return 0;
}