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

int n , k;
VI G[MAX];
int a[MAX];
bool U[MAX];

int res;
int cnt;

int c[MAX];
int d[MAX];

void dfs2(int v, int p)
{
	c[v] = U[v];
	d[v] = 1;
	FOR(i,0,G[v].size())
	{
		int to = G[v][i];
		if (to == p) continue;
		dfs2(to, v);
		c[v] += c[to];
		d[v] += d[to];
	}
}

PII dfs(int v, int p)
{
	VI A;
	VI B;
	bool bad = 0;

	FOR(i,0,G[v].size())
	{
		int to = G[v][i];
		if (to == p) continue;
		if (U[to])
		{
			bad = 1;
		}
		PII pr = dfs(to , v);
		if (pr.second == 0)
		{
			A.push_back(pr.first);
		}
		else
		{
			bad = 1;
			B.push_back(pr.first);
		}
	}

	if (U[v]) return MP(0 , 1);

	sort(ALL(B));
	reverse(ALL(B));
	int add = 1;
	FOR(i,0,A.size())
	{
		add += A[i];
	}
	int add2 = add;
	if (B.size() > 0) add += B[0];
	if (B.size() > 1) add += B[1];

	if (cnt == c[v])
	{
		add += n - d[v];
	}

	res = max(res , add);
	if (B.size() > 0)
		add2 += B[0];
	return MP(add2 , bad);
}

bool check(int X)
{
	FILL(U, 0);
	cnt = 0;
	FOR(i,0,n)
	{
		if (a[i] < X)
		{
			U[i] = 1;
			cnt++;
		}
	}
	dfs2(0, -1);

	res = 0;
	dfs(0, -1);

	return res >= k;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);


	cin >> n >> k;

	FOR(i,0,n)
	{
		scanf("%d" , &a[i]);
	}

	FOR(i,0,n - 1)
	{
		int a , b;
		scanf("%d%d" , &a , &b);
		--a;--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int L = 0;
	int R = 1000007;
	while (R - L > 1)
	{
		int X = (L + R) / 2;
		if (check(X))
		{
			L = X;
		}
		else
		{
			R = X;
		}
	}

	cout << L << endl;

    return 0;
}