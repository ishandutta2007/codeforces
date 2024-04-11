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
const int MAX = 507;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000009;
const int CNT = 0;

const double eps = 1e-9;

int G[MAX][MAX];

int clr[MAX];

bool ok = 1;

int n, m;

void dfs(int v)
{
	FOR(i,0,n)
	{
		if (i == v) continue;
		if (G[v][i]) continue;
		if (clr[i] == -1)
		{
			clr[i] = (clr[v] ^ 1);
			dfs(i);
		}
		if (clr[v] == clr[i]) ok = 0;
	}
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	cin >> n >> m;
	FOR(i,0,m)
	{
		int a , b;
		scanf("%d%d" , &a , &b);
		--a;--b;
		G[a][b] = G[b][a] = 1;
	}
	FILL(clr, -1);

	FOR(i,0,n)
	{
		if (clr[i] == -1)
		{
			clr[i] = 0;
			dfs(i);
		}
	}

	string s = "";
	FOR(i,0,n)
	{
		int c = 0;
		FOR (j,0,n)
		{
			if (G[i][j] == 0) ++c;
		}
		if (c == 1)
		{
			s += 'b';
		}
		else
		{
			if (clr[i] == 0)
			{
				s += 'a';
			}
			else
			{
				s += 'c';
			}
		}
	}

	FOR(i,0,n)
	{
		FOR(j,i + 1 , n)
		{
			if (G[i][j])
			{
				if (abs(s[i] - s[j]) == 2) ok = 0;
			}
			else
			{
				if (abs(s[i] - s[j]) < 2) ok = 0;
			}
		}
	}

	if (!ok)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
		cout << s << endl;
	}

}