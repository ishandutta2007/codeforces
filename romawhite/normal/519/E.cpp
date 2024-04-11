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
#include <complex>

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
#define y1 adsfadsfadfs

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 15000000;

vector<int> g[MAX];
int up[MAX][19];
int cnt[MAX];
int d[MAX];
int tin[MAX];
int tout[MAX];
int timer = 0;

void dfs(int v, int p)
{
    tin[v] = timer++;
    up[v][0] = p;
    FOR(i,1,19)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    cnt[v] = 1;
    FOR(i,0,g[v].size())
    {
        int to = g[v][i];
        if (to == p) continue;
        d[to] = d[v] + 1;
        dfs(to, v);
        cnt[v] += cnt[to];
    }
    tout[v] = timer ++;
}

int upper(int a , int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a , int b)
{
    if (upper(a , b)) return a;
    if (upper(b , a)) return b;
    RFOR(i,19,0)
    {
        if (!upper(up[a][i] , b))
        {
            a = up[a][i];
        }
    }
    return up[a][0];
}

int dist(int a , int b , int c = -1)
{
    if (c == -1) c = lca(a , b);
    return d[a] + d[b] - 2 * d[c];
}
int Up(int v , int d)
{
    RFOR(i,19,0)
    {
        if (d >= (1 << i))
        {
            v = up[v][i];
            d -= (1 << i);
        }
    }
    return v;
}

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    FOR(i,0,n - 1)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,0);
    int m;
    cin >> m;
    FOR(i,0,m)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        if (a == b)
        {
            printf("%d\n" , n);
            continue;
        }
        int c = lca(a , b);
        int D = dist(a, b , c);
        int dd = dist(a , c, c);
        if (D % 2 == 1)
        {
            printf("0\n");
            continue;
        }

        if (dd < D / 2)
        {
            swap(a , b);
            dd = D - dd;
        }
        if (dd * 2 == D)
        {
            a = Up(a , dd - 1);
            b = Up(b , dd - 1);

            int res = n - cnt[a] - cnt[b];
            printf("%d\n" , res);
        }
        else
        {
            a = Up(a,D / 2 - 1);
            int p = up[a][0];
            int res = cnt[p] - cnt[a];
            printf("%d\n" , res);
        }
    }

    return 0;
}