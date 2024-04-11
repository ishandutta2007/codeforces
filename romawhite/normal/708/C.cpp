#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:64000000")
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
const int MAX = 400007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int d[MAX];
VI G[MAX];

void dfs(int v , int p)
{
	d[v] = 1;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		dfs(to, v);
		d[v] += d[to];
	}
}

multiset<int> S;

bool R[MAX];
int n;

void dfs2(int v, int p, int sz)
{
	if (p == -1)
	{
		R[v] = 1;
	}
	else
	{
		S.erase(S.find(sz));
		S.insert(sz - d[v]);
		int mx = *S.rbegin();
		if (n - d[v] - mx <= n / 2)
			R[v] = 1;
		S.erase(S.find(sz - d[v]));
		S.insert(sz);
	}

	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		if (p == -1)
		{
			dfs2(to , v , d[to]);
		}
		else
		{
			dfs2(to , v , sz);
		}
	}

}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	cin >> n;
	FOR(i,0,n - 1)
	{
		int a , b;
		scanf("%d%d" , &a , &b);
		-- a; -- b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(0, -1);

	int s = -1;
	FOR(i,0,n)
	{
		bool ok = 1;
		if (n - d[i] > n / 2) ok = 0;
		FOR(j,0,SZ(G[i]))
		{
			int to = G[i][j];
			if (d[to] > d[i]) continue;
			if (d[to] > n / 2) ok = 0;
		}
		if (ok)
		{
			s = i;
			break;
		}
	}


	dfs(s, -1);

	FOR(i,0,SZ(G[s]))
	{
		S.insert(d[G[s][i]]);
	}

	dfs2(s , -1 , -1);

	FOR(i,0,n)
	{
		printf("%d " , R[i]);
	}

	cout << endl;

    return 0;
}