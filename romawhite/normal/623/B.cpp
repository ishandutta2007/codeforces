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

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 1000007;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000009;
const int CNT = 0;

const double eps = 1e-9;

int n ;
Int a , b;

VI primes(int x)
{
	VI p;
	for(int i = 2; i * i <= x; ++i)
		if (x % i == 0)
		{
			p.push_back(i);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	if (x != 1)
		p.push_back(x);
	return p;
}

Int dp[MAX][3];

Int solve(VI c)
{
	VI p = primes(c[0]);
	VI p1 = primes(c[0] - 1);
	FOR(i,0,p1.size()) p.push_back(p1[i]);
	p1 = primes(c[0] + 1);
	FOR(i,0,p1.size()) p.push_back(p1[i]);
	p1 = primes(c.back());
	FOR(i,0,p1.size()) p.push_back(p1[i]);
	p1 = primes(c.back() + 1);
	FOR(i,0,p1.size()) p.push_back(p1[i]);
	p1 = primes(c.back() - 1);
	FOR(i,0,p1.size()) p.push_back(p1[i]);
	sort(ALL(p));
	p.resize(unique(ALL(p)) - p.begin());

	Int res = 1LL * INF * INF;
	FOR(t,0,p.size())
	{
		int pr = p[t];

		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		FOR(i,0,n)
		{
			int val = min(c[i] % pr , pr - c[i] % pr);

			dp[i + 1][0] = dp[i + 1][1] = dp[i + 1][2] = 1LL * INF * INF;
			if (val <= 1)
			{
				dp[i + 1][2] = min(dp[i][2] + a * val , min(dp[i][1] + a * val, dp[i][0] + a * val));
			}
			dp[i + 1][1] = min(dp[i][0] , dp[i][1]) + b;
			if (val <= 1)
			{
				dp[i + 1][0] = dp[i][0] + a * val;
			}
		}
		Int r = min(dp[n][2] , min(dp[n][1] , dp[n][0]));
		res = min(res , r);
	}
	return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	cin >> n >> a >> b;
	swap(a , b);
	VI c(n);
	FOR(i,0,n)
	{
		scanf("%d" , &c[i]);
	}
	Int res = solve(c);

	cout << res << endl;
	return 0;
}