
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
const int MAX = 200007;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 0;

VI G[MAX];


bool C[MAX];
int sz[MAX];
int P[MAX];

void dfsSZ(int v, int p)
{
	P[v] = p;
	sz[v] = 1;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		dfsSZ(to, v);
		sz[v] += sz[to];
	}
}

vector<pair<int, PII> > res;

vector<PII> A;

void dfs(int v, int p)
{
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		dfs(to, v);
	}
	A.push_back(MP(v , p));
}

void solve(int v, int p)
{
	A.clear();
	dfs(v, p);
	int last = v;
	FOR(i,0,SZ(A) - 1)
	{
		res.push_back(MP(p, MP(last , A[i].first)));
		res.push_back(MP(A[i].first , MP(A[i].second , v)));
		last = A[i].first;
	}
	res.push_back(MP(p , MP(last , v)));
}


int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	cin >> n;
	FOR(i,0,n - 1)
	{
		int a , b;
		scanf("%d%d" , &a , &b);
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfsSZ(0,-1);

	FOR(i,0,n)
	{
		C[i] = 1;
		FOR(j,0,SZ(G[i]))
		{
			int to = G[i][j];
			if (to == P[i]) continue;
			if (sz[to] * 2 > n) C[i] = 0;
		}
		if (2 * (n - sz[i]) > n) C[i] = 0;
	}

	FOR(i,0,n)
	{
		if (!C[i]) continue;
		FOR(j,0,SZ(G[i]))
		{
			int to = G[i][j];
			if (C[to]) continue;
			solve(to, i);
		}
	}

	cout << SZ(res) << endl;
	FOR(i,0,SZ(res))
	{
		printf("%d %d %d\n" , res[i].first + 1 , res[i].second.first + 1 , res[i].second.second + 1);
	}

	return 0;
}