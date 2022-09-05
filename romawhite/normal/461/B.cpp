#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:160777216")
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
const int MAX = 4007;
const int MAX2 = 7000;
const int MOD = 1000000007;
 
vector<int> g[100007];
int c[100007];

Int dp[100007][2];

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

void dfs(int v)
{
	if (c[v] == 1)
	{
		dp[v][1] = 1;
		FOR(i,0,g[v].size())
		{
			dfs(g[v][i]);
			dp[v][1] *= dp[g[v][i]][0] + dp[g[v][i]][1];
			dp[v][1] %= MOD;
		}
	}
	else
	{
		dp[v][0] = 1;
		FOR(i,0,g[v].size())
		{
			dfs(g[v][i]);
			dp[v][0] *= dp[g[v][i]][0] + dp[g[v][i]][1];
			dp[v][0] %= MOD;
		}
		dp[v][1] = 0;
		FOR(i,0,g[v].size())
		{
			Int r = dp[v][0];
			r *= bpow((dp[g[v][i]][0] + dp[g[v][i]][1]) % MOD , MOD - 2);
			r %= MOD;
			r *= dp[g[v][i]][1];
			r %= MOD;
			dp[v][1] += r;
			dp[v][1] %= MOD;
		}
	}
}

int main()
{
        #ifndef ONLINE_JUDGE
               // freopen("in.txt", "r", stdin);
        #endif
   
		//freopen("input.txt" , "r" , stdin);
		//freopen("output.txt" , "w", stdout);

		int n;
		cin >> n;
		FOR(i,1,n)
		{
			int x;
			cin >> x;
			g[x].push_back(i);
		}

		FOR(i,0,n)
		{
			scanf("%d" , &c[i]);
		}

		dfs(0);

		cout << dp[0][1] << endl;

        return 0;
}