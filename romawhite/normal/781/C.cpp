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
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

VI A;
VI G[MAX];
bool U[MAX];

void dfs(int v)
{
	U[v] = 1;
	A.push_back(v);
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (U[to]) continue;
		dfs(to);
		A.push_back(v);
	}
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n , m, k;
	cin >> n >> m >> k;
	FOR(i,0,m)
	{
		int a , b;
		scanf("%d %d" , &a , &b);
		-- a; -- b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(0);


	int s = (SZ(A) + k - 1) / k;
	int c1 = SZ(A) % k;
	if (c1 == 0) c1 = k;
	int c2 = k - c1;
	int ptr = 0;
	FOR(i,0,c1)
	{
		printf("%d" , s);
		FOR(j,0,s)
		{
			printf(" %d" , A[ptr ++] + 1);
		}
		printf("\n");
	}
	FOR(i,0,c2)
	{
		printf("%d" , s - 1);
		FOR(j,0,s - 1)
		{
			printf(" %d" , A[ptr ++] + 1);
		}
		printf("\n");
	}

    return 0;
}