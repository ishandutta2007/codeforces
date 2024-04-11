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

int a[MAX];
VI G[MAX];

Int dp[MAX][3][2];

void dfs(int v, int p)
{
	dp[v][0][1] = a[v];
	dp[v][1][0] = a[v];
	vector<pair<Int,int> > b , c , d;
	FOR(i,0,G[v].size())
	{
		int to = G[v][i];
		if (to == p) continue;
		dfs(to, v);
		dp[v][2][0] = max(dp[v][2][0] , dp[to][2][0]);
		dp[v][2][0] = max(dp[v][2][0] , dp[to][1][0] + a[v]);
		dp[v][1][0] = max(dp[v][1][0] , dp[to][1][0]);
		FOR(t,0,2)
		{
			dp[v][t][1] = max(dp[v][t][1] , dp[to][t][1] + a[v]);
			dp[v][t + 1][0] = max(dp[v][t + 1][0] , dp[to][t][1] + a[v]);
			dp[v][t + 1][1] = max(dp[v][t + 1][1] , dp[to][t][1] + a[v]);
		}
		b.push_back(MP(dp[to][0][1], to));
		c.push_back(MP(dp[to][1][1], to));
		d.push_back(MP(dp[to][1][0] , to));
	}


	sort(ALL(b));
	reverse(ALL(b));
	sort(ALL(c));
	reverse(ALL(c));
	sort(ALL(d));
	reverse(ALL(d));
	if (b.size() >= 2)
	{
		dp[v][1][0] = max(dp[v][1][0] , b[0].first + b[1].first + a[v]);

		dp[v][2][0] = max(dp[v][2][0] , d[0].first + d[1].first);

		if (b[0].second != d[0].second)
		{
			dp[v][1][1] = max(dp[v][1][1] , b[0].first + d[0].first + a[v]);
		}
		else
		{
			dp[v][1][1] = max(dp[v][1][1] , b[0].first + d[1].first + a[v]);
			dp[v][1][1] = max(dp[v][1][1] , b[1].first + d[0].first + a[v]);
		}

		if (b[0].second != c[0].second)
		{
			dp[v][2][0] = max(dp[v][2][0] , b[0].first + c[0].first + a[v]);
		}
		else
		{
			dp[v][2][0] = max(dp[v][2][0] , b[0].first + c[1].first + a[v]);
			dp[v][2][0] = max(dp[v][2][0] , b[1].first + c[0].first + a[v]);
		}
	}

	if (b.size() >= 3)
	{
		FOR(q,0,3)
		{
			int cnt = 0;
			Int add = 0;
			FOR(i,0,3)
			{
				if (b[i].second != d[q].second)
				{
					++cnt;
					add += b[i].first;
				}
				if (cnt == 2) break;
			}
			dp[v][2][0] = max(dp[v][2][0] , d[q].first + add + a[v]);
		}
	}

}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;
	FOR(i,0,n)
	{
		scanf("%d" , &a[i]);
	}

	FOR(i,0,n - 1)
	{
		int u , v;
		scanf("%d%d" , &u , &v);
		--u;--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(0, -1);



	cout << dp[0][2][0] << endl;

    return 0;
}