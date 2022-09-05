

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
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
#define MANY 18000000000000000000ull

typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 20007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 20;

int p[MAX];

int deg[207];
int c[207][207];
int f[207][207];
int N, S, F;
int d[207];
int ptr[207];
int q[207];

bool bfs()
{
    int L = 0, R = 0;
    q[R++] = S;
    FILL(d, -1);
    d[S] = 0;
    while (L < R) {
        int v = q[L++];
        FOR(i,0,N)
            if (d[i] == -1 && f[v][i] < c[v][i])
            {
                q[R++] = i;
                d[i] = d[v] + 1;
            }
    }
    return d[F] != -1;
}

int dfs (int v, int flow)
{
    if (!flow)  return 0;
    if (v == F)  return flow;
    for (int &to = ptr[v]; to < N; ++to)
    {
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
        if (pushed)
        {
            f[v][to] += pushed;
            f[to][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic()
{
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        FILL(ptr, 0);
        while (int pushed = dfs (S, INF))
            flow += pushed;
    }
    return flow;
}

vector< vector<int> > res;
vector<int> r;
bool U[207];

void dfs2(int v)
{
    U[v] = 1;
    r.push_back(v);
    FOR(i,1,N - 1)
    {
        if (f[v][i] && !U[i])
        {
            dfs2(i);
        }
    }
}

int main()
{

   //freopen("in.txt", "r", stdin);
    for(int i = 2; i * i <MAX; ++i)
    {
        if (!p[i])
        {
            for(int j = i * i; j < MAX; j += i)
            {
                p[j] = 1;
            }
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i,0,n)
    {
        cin >> a[i];
    }
    S = 0;
    F = n + 1;
    N = n + 2;
    FOR(i,0,n)
    {
        if (a[i] % 2 == 0)
            c[S][i + 1] = 2;
        else
            c[i + 1][F] = 2;
    }

    FOR(i,0,n)
    {
        if (a[i] % 2 == 0)
        {
            FOR(j,0,n)
            {
                if (a[j] % 2 == 1 && !p[a[i] + a[j]])
                {
                    c[i + 1][j + 1] = 1;
                }
            }
        }
    }

 /*   FOR(i,0,N)
    {
        FOR(j,0,N)
        {
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }*/

    int flow = dinic();
    if (flow != n)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    FOR(i,1,n + 1)
    {
        if (!U[i])
        {
            dfs2(i);
            res.push_back(r);
            r.clear();
        }
    }

    cout << res.size() << endl;
    FOR(i,0,res.size())
    {
        cout << res[i].size();
        FOR(j,0,res[i].size())
        {
            cout << ' ' << res[i][j];
        }
        cout << endl;
    }


    return 0;
}