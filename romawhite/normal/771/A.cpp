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
const int MAX = 200000;
const int MAX2 = 7000;
const int BASE = 1000000000;

int n, m;
VI G[MAX];
int U[MAX];
int e, c;

void dfs(int v)
{
	++ c;
	U[v] = 1;
	FOR (i,0,SZ(G[v]))
	{
		int to = G[v][i];
		++ e;
		if (U[to] == 0)
			dfs(to);
	}
}

int main()
{
    //freopen("in.txt", "r", stdin);

    cin >> n >> m;
    FOR (i,0,m)
    {
    	int u, v;
    	scanf("%d %d", &u, &v);
    	-- u;
    	-- v;
    	G[u].PB(v);
    	G[v].PB(u);
    }

    bool ok = 1;
    FOR (i,0,n)
    	if (U[i] == 0)
    	{
    		e = 0, c = 0;
    		dfs(i);
    		e /= 2;
    		if (e != Int(c) * (c-1) / 2)
    			ok = 0;
    	}

    cout << (ok ? "YES" : "NO") << endl;




    return 0;
}