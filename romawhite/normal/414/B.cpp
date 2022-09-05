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
const int MAX = 100;
const int MAX2 = 7000;
const Int BASE = 1000000007;

const int MOD = 1000000007;

int dp[2005][2005];

int main()
{


	int n,k;
	cin >> n >> k;
	dp[0][1] = 1;
	FOR(i,0,k)
		FOR(j,1,n + 1)
			if (dp[i][j]){
				FOR(t,1,n / j + 2)
					if (t * j <= n){
						dp[i + 1][t * j] += dp[i][j];
						if (dp[i + 1][t * j] >= MOD)
							dp[i + 1][t * j] -= MOD;
					}
			}

	Int res = 0;
	FOR(i,1,n + 1)
	{
		res += dp[k][i];
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}