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
const int MAX = 1024;
const int MAX2 = 7000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int n, m, k;
char S[MAX][MAX];
int R[MAX][MAX][2];
pair<PII, int> Q[MAX*MAX*2];
char dc[4] = {'D','L','R','U'};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

bool OK(int x, int y)
{
	return (x >= 0 && y >= 0 && x < n && y < m);
}

void fail()
{
	cout << "IMPOSSIBLE" << endl;
}

int main()
{

	cin >> n >> m >> k;
	FOR (i,0,n)
		scanf("%s", S[i]);
	int x = -1, y = -1;
	FOR (i,0,n)
		FOR (j,0,m)
			if (S[i][j] == 'X')
			{
				x = i;
				y = j;
			}

	bool was = 0;
	FOR (d,0,4)
	{
		int xx = x+dx[d];
		int yy = y+dy[d];
		if (OK(xx, yy) && S[xx][yy] != '*')
			was = 1;
	}

	if (!was)
	{
		fail();
		return 0;
	}


	FOR (i,0,n)
		FOR (j,0,m)
			FOR (p,0,2)
				R[i][j][p] = INF;
	R[x][y][0] = 0;
	int l = 0, r = 1;
	Q[0] = MP(MP(x, y), 0);

	while (l < r)
	{
		int tx = Q[l].first.first;
		int ty = Q[l].first.second;
		int tp = Q[l].second;
		++ l;
		FOR (d,0,4)
		{
			int nx = tx+dx[d];
			int ny = ty+dy[d];
			int np = tp^1;
			if (OK(nx, ny) && S[nx][ny] != '*' && R[nx][ny][np] == INF)
			{
				R[nx][ny][np] = R[tx][ty][tp] + 1;
				Q[r ++] = MP(MP(nx, ny), np);
			}
		}
	}

	string res = "";
	int tx = x, ty = y;
	FOR (i,0,k)
	{
		int td = -1;
		int len = k-i-1;
		FOR (d,0,4)
		{
			int nx = tx+dx[d];
			int ny = ty+dy[d];
			if (OK(nx, ny) && S[nx][ny] != '*' && R[nx][ny][len%2] <= len)
			{
				td = d;
				break;
			}
		}
		if (td == -1)
		{
			fail();
			return 0;
		}
		res += dc[td];
		tx += dx[td];
		ty += dy[td];
	}

	printf("%s\n", res.c_str());







	return 0;
}