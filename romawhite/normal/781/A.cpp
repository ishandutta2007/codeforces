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

int U[MAX];

VI G[MAX];
int C[MAX];

void dfs(int v , int p)
{
	U[C[v]] = v;
	if (p != -1)
		U[C[p]] = v;
	int ptr = 0;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		while (U[ptr] == v) ++ ptr;
		C[to] = ptr;
		U[ptr] = v;
	}

	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		dfs(to, v);
	}

}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	FILL(U, -1);

	int n;
	cin >> n;
	FOR(i,0,n - 1)
	{
		int a , b;
		scanf("%d%d" , &a , &b);
		-- a;
		-- b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	C[0] = 0;
	dfs(0,-1);
	int res = 0;
	FOR(i,0,n)
	{
		res = max(res , C[i] + 1);
	}
	cout << res << endl;
	FOR(i,0,n)
	{
		printf("%d " , C[i] + 1);
	}


    return 0;
}