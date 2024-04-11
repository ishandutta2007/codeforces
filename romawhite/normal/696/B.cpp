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
const int MAXV = 1200;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 999999999;

int d[MAX];
VI G[MAX];

double res[MAX];


void dfs1(int v, int p)
{
	d[v] = 1;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		dfs1(to, v);
		d[v] += d[to];
	}
}

void dfs2(int v, int p)
{
	int sum = d[v] - 1;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		res[to] = res[v] + 0.5 * (sum - d[to]) + 1;
		dfs2(to , v);
	}

}

int main()
{
    //freopen("in.txt",  "r", stdin);

	int n;
	cin >> n;
	FOR(i,1,n)
	{
		int p;
		scanf("%d" , &p);
		-- p;
		G[p].push_back(i);
		G[i].push_back(p);
	}

	dfs1(0 , -1);

	res[0] = 1.0;

	dfs2(0, -1);

	FOR(i,0,n)
	{
		printf("%.1f " , res[i]);
	}
	printf("\n");

    return 0;
}