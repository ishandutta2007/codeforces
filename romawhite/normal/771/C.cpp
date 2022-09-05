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
const int MAX = 300000;
const int MAX2 = 7000;
const int BASE = 1000000000;

int n, k;
VI G[MAX];
int Up[7];
int Down[MAX][7];
Int C[MAX];
Int D[MAX];
Int add, res;

void dfs1(int v, int p)
{
	C[v] = 1;
	Down[v][0] = 1;
	FOR (i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p)
			continue;
		dfs1(to, v);
		C[v] += C[to];
		D[v] += D[to] + C[to];
		FOR (j,0,k)
			Down[v][(j+1)%k] += Down[to][j];
	}
}

int tUp[7];

void dfs2(int v, int p)
{
	FOR (i,1,k)
		add += Int(k-i) * (Down[v][i] + Up[i]);

	FOR (i,0,k)
		tUp[i] = Up[i];
	FOR (i,0,k)
		Up[(i+1)%k] = tUp[i];

	FOR (i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p)
			continue;
		FOR (j,0,k)
			Up[(j+2)%k] += Down[to][j];
	}
	FOR (i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p)
			continue;
		FOR (j,0,k)
			Up[(j+2)%k] -= Down[to][j];
		Up[1 % k] ++;
		dfs2(to, v);
		Up[1 % k] --;
		FOR (j,0,k)
			Up[(j+2)%k] += Down[to][j];
	}
	FOR (i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p)
			continue;
		FOR (j,0,k)
			Up[(j+2)%k] -= Down[to][j];
	}

	FOR (i,0,k)
		tUp[i] = Up[i];
	FOR (i,0,k)
		Up[(i-1+k)%k] = tUp[i];
}

void dfs3(int v, int p, Int d)
{
	res += d;
	FOR (i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p)
			continue;
		d += (n-C[to]) - C[to];
		dfs3(to, v, d);
		d -= (n-C[to]) - C[to];
	}
}

int main()
{
    //freopen("in.txt", "r", stdin);

    cin >> n >> k;
    FOR (i,0,n-1)
    {
    	int u, v;
    	scanf("%d %d", &u, &v);
    	-- u;
    	-- v;
    	G[u].PB(v);
    	G[v].PB(u);
    }

    dfs1(0, -1);
    dfs2(0, -1);
    //cout << D[0] << ' ' << C[0] << endl;
    dfs3(0, -1, D[0]);

    //cout << res << ' ' << add << ' ' << res+add << endl;

    Int ans = (res+add)/2/k;

    cout << ans << endl;








    return 0;
}