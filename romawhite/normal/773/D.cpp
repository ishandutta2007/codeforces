#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 2007;
const int ADD = 500107;

int g[MAX][MAX];

Int d[MAX];
bool U[MAX];

int minOut[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	cin >> n;

	int mn = INF + 7;
	int s = -1;

	FOR(i,0,n)
	{
		FOR(j,i + 1 , n)
		{
			scanf("%d" , &g[i][j]);
			if (g[i][j] < mn)
			{
				mn = g[i][j];
				s = i;
			}
		}
	}

	FOR(i,0,n)
		FOR(j,i + 1 , n)
		{
			g[i][j] -= mn;
			g[j][i] = g[i][j];
		}

	FOR(i,0,n)
	{
		minOut[i] = INF;
		FOR(j,0,n)
		{
			if (j == i) continue;
			minOut[i] = min(minOut[i] , g[i][j]);
		}
	}

	FOR(i,0,n)
	{
		g[i][s] = g[s][i] = min(g[s][i] , 2 * minOut[i]);
	}

	FOR(i,0,n)
	{
		d[i] = 1LL * INF * INF;
	}
	d[s] = 0;

	FOR(it,0,n)
	{
		Int M = 1LL * INF * INF;
		int v = -1;

		FOR(i,0,n)
		{
			if (U[i]) continue;
			if (d[i] < M)
			{
				M = d[i];
				v = i;
			}
		}

		U[v] = 1;

		FOR(i,0,n)
		{
			d[i] = min(d[i] , d[v] + g[v][i]);
		}
	}

	FOR(i,0,n)
	{
		Int res = d[i] + 1LL * (n - 1) * mn;
		cout << res << endl;
	}


    return 0;
}