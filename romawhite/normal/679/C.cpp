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
const int MOD = 1000000007;
const int CNT = 0;

string s[MAX];
int cmp = 0;
int c[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int cnt[MAX * MAX];

int n , k;


void dfs(int x, int y)
{
	c[x][y] = cmp;
	cnt[cmp] ++;
	FOR(dir,0,4)
	{
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		if (xx >= 0 && yy >= 0 && xx < n && y < n && s[xx][yy] == '.' && c[xx][yy] == -1)
		{
			dfs(xx , yy);
		}
	}
}

int U[MAX * MAX];

int main()
{
	//freopen("in.txt" , "r" , stdin);


	cin >> n >> k;

	FOR(i,0,n)
	{
		cin >> s[i];
	}

	FILL(c, -1);

	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			if (c[i][j] == -1 && s[i][j] == '.')
			{
				dfs(i, j);
				++ cmp;
			}
		}
	}

	int res = -1;

	int tm = 0;

	FOR(i,0,n - k + 1)
	{
		int x = i;
		int y = 0;
		FOR(dx,0,k)
		{
			FOR(dy,0,k)
			{
				if (c[x + dx][y + dy] != -1)
					cnt[c[x + dx][y + dy]] --;
			}
		}

		FOR(j,0,n - k + 1)
		{
			++ tm;

			int cur = k * k;

			if (i != 0)
			{
				FOR(dy,0,k)
				{
					int cm = c[i - 1][j + dy];
					if (cm == -1) continue;
					if (U[cm] == tm) continue;
					U[cm] = tm;
					cur += cnt[cm];
				}
			}
			if (i + k < n)
			{
				FOR(dy,0,k)
				{
					int cm = c[i + k][j + dy];
					if (cm == -1) continue;
					if (U[cm] == tm) continue;
					U[cm] = tm;
					cur += cnt[cm];
				}
			}
			if (j != 0)
			{
				FOR(dx,0,k)
				{
					int cm = c[i + dx][j - 1];
					if (cm == -1) continue;
					if (U[cm] == tm) continue;
					U[cm] = tm;
					cur += cnt[cm];
				}
			}
			if (j + k < n)
			{
				FOR(dx,0,k)
				{
					int cm = c[i + dx][j + k];
					if (cm == -1) continue;
					if (U[cm] == tm) continue;
					U[cm] = tm;
					cur += cnt[cm];
				}
			}

			res = max(res , cur);

			if (j + k == n)
			{
				FOR(dx,0,k)
				{
					FOR(dy,0,k)
					{
						int cm = c[i + dx][j + dy];
						if (cm == -1) continue;
						cnt[cm] ++;
					}
				}
			}
			else
			{
				FOR(dx,0,k)
				{
					int cm = c[i + dx][j];
					if (cm == -1) continue;
					cnt[cm] ++;
				}
				FOR(dx,0,k)
				{
					int cm = c[i + dx][j + k];
					if (cm == -1) continue;
					cnt[cm] --;
				}
			}


		}

	}

	cout << res << endl;


    return 0;
}