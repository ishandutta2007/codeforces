#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int n, m, k;
char c[500][500];


bool read()
{
	if (!(cin >> n >> m >> k))
		return false;
	forn (i, n)
		forn (j, m)
		cin >> c[i][j];
	return true;
}

bool used[500][500];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y)
{
	used[x][y] = true;
	forn (i, 4)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx == n || ny < 0 || ny == m)
			continue;
		if (!used[nx][ny] && c[nx][ny] == '.')
			dfs(nx, ny);
	}
	if (k > 0)
	{
		c[x][y] = 'X';
		k--;
	}
}

void solve()    
{
	forn (i, n)
		forn (j, m)
			if (!used[i][j] && c[i][j] == '.')
		{
				dfs(i, j);		
			forn (q, n)
			{
				forn (w, m)
					cout << c[q][w];
				cout << endl;
			}	
			return;
	}
	
}

int main()
{
#ifdef Baster
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	read();
	solve();
	return 0;
}