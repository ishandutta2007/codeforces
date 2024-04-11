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
#include <fstream>
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
#define y0 gfdssdfer
#define y1 wetgwervbwqr

typedef long long Int;

const int INF = 1000000000;
const Int INF2 = 5LL * INF * INF;

const int MAXN = 100007;

int x[MAXN];
Int y[MAXN];

vector<int> g[MAXN];

vector<int> a;


int tin[MAXN];
int tout[MAXN];
int timer;
int up[MAXN][20];

void dfs (int v, int p) {
    tin[v] = timer++;
    up[v][0] = p;
    FOR(i,1,20)
        up[v][i] = up[up[v][i-1]][i-1];
    FOR(i,0,g[v].size())
    {
        if (g[v][i] != p)
            dfs(g[v][i], v);
    }
    tout[v] = timer++;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    RFOR(i,20,0)
        if (!upper(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}


int main()
{
    int n;
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d %I64d" , &x[i] , &y[i]);
    }

    a.push_back(n - 1);

    RFOR(i,n - 1,0)
    {
        int r = -1;
        pair<Int,Int> mx = MP(0,-1);

        RFOR(j,a.size(),0)
        {
            Int Y = y[a[j]] - y[i];
            int X = x[a[j]] - x[i];

            if (1LL * Y * mx.first > 1LL * X * mx.second)
            {
                r = j;
                mx = MP(X,Y);
            }
            else
            {
                break;
            }
        }
        while (a.size() > r + 1)
            a.pop_back();

        g[a.back()].push_back(i);
        //cout << i << ' ' << a.back() << endl;
        a.push_back(i);

    }

    dfs(n - 1 , n - 1);

    int m;
    cin >> m;
    FOR(i,0,m)
    {
        int a,b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        printf("%d " , lca(a,b) + 1);
    }

    cout << endl;
}