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
const int MAX = 500007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

const int MAGIC = 400;

VI G[MAX];

VI c;

void dfs(int v, int p, int d)
{
	if (G[v].size() == 1)
	{
		c.push_back(d);
	}
	FOR(i,0,G[v].size())
	{
		int to = G[v][i];
		if (to == p) continue;
		dfs(to, v , d + 1);
	}
}

int solve()
{
	sort(ALL(c));
	int res = 0;
	FOR(i,0,c.size())
	{
		res = max(res , c[i]) + 1;
	}
	return res;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("distance.in",  "r", stdin);
	//freopen("distance.out", "w", stdout);
	//freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;

	FOR(i,0,n - 1)
	{
		int a, b;
		scanf("%d%d" , &a , &b);
		--a;--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int res = 0;

	FOR(i,0,G[0].size())
	{
		c.clear();
		dfs(G[0][i] , 0 , 0);
		res = max(res , solve());
	}

	cout << res << endl;

	return 0;
}