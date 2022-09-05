
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

VI G[MAX];

bool ok = 1;

int root = -1;
int res = -1;

int dfs(int v, int p)
{
	if (!ok) return -1;
	set<int> S;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		int c = dfs(to, v) + 1;
		if (!ok) return -1;
		S.insert(c);
	}

	if (SZ(S) == 0) return 0;
	if (SZ(S) == 1)
	{
		if (p == -1)
		{
			int len = *S.begin();
			while (len % 2 == 0)
			{
				len /= 2;
			}
			res = len;
			return res;
		}
		return *S.begin();
	}
	if (SZ(S) > 2)
	{
		ok = 0;
		return -1;
	}
	if (SZ(S) == 2)
	{
		if (p == -1)
		{
			int len = *S.begin();
			S.erase(S.begin());
			len += *S.begin();

			while (len % 2 == 0) len /= 2;
			res = len;
			return res;
		}
		ok = 0;
		root = v;
		return -1;
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
	FOR(i,0,n - 1)
	{
		int a , b;
		scanf("%d%d" , &a , &b);
		-- a; -- b;
		G[a].push_back(b);
		G[b].push_back(a);
	}


	dfs(0, -1);
	if (res > 0)
	{
		cout << res << endl;
		return 0;
	}


	if (root != -1)
	{
		ok = 1;
		dfs(root, -1);
	}


	if (res > 0)
	{
		cout << res << endl;
		return 0;
	}

	cout << -1 << endl;

    return 0;
}