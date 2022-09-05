

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
#define free adsgasdg


typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 1000007;
const int MAX2 = 200000;
const int BASE = 1000000007;
const int MOD = 1000000007;
const int CNT = 1000;

string s[23];
Int d[500][500];
int dirx[4] = {1,0,-1,0};
int diry[4] = {0,1,0,-1};
int n , m ,k , l;

bool ok(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m && s[x][y] == '.';
}
int N , S, T;
int c[2000][2000];
int f[2000][2000];
int D[2000], ptr[2000], q[2000];

bool bfs()
{
    int qh=0, qt=0;
    q[qt++] = S;
    FILL(D,-1);
    D[S] = 0;
    while (qh < qt) {
        int v = q[qh++];
        for (int to=0; to<N; ++to)
            if (D[to] == -1 && f[v][to] < c[v][to]) {
                q[qt++] = to;
                D[to] = D[v] + 1;
            }
    }
    return D[T] != -1;
}


int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == T)  return flow;
    for (int & to=ptr[v]; to<N; ++to) {
        if (D[to] != D[v] + 1)  continue;
        int pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
        if (pushed) {
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
vector<pair <pair<int,int> , int> > a;
vector<pair< pair<int,int> , int> > b;
int F(Int MID)
{
    FILL(c,0);
    FILL(f,0);
    FOR(i,0,a.size())
    {
        c[0][i + 1] = 1;
    }
    FOR(i,0,a.size())
    {
        FOR(x,0,n)
        {
            FOR(y,0,m)
            {
                int X = a[i].first.first;
                int Y = a[i].first.second;
                Int dist = d[X * m + Y][x * m + y];
                if (s[x][y] == '.' && dist < INF && 1LL * dist * a[i].second <= MID)
                {
                    //cout << dist << ' ' << i + 1 << ' ' << 1 + a.size() + x * m + y << endl;
                    c[i + 1][1 + a.size() + x * m + y] = 1;
                }
            }
        }
    }
    FOR(x,0,n)
    {
        FOR(y,0,m)
        {
            c[1 + a.size() + x * m + y][1 + a.size() + x * m + y + n * m] = 1;
        }
    }

    FOR(i,0,b.size())
    {
        FOR(x,0,n)
        {
            FOR(y,0,m)
            {
                int X = b[i].first.first;
                int Y = b[i].first.second;
                Int dist = d[X * m + Y][x * m + y];
                if (dist < INF && 1LL * dist * b[i].second <= MID)
                {
                    //cout << dist << ' ' << 1 + a.size() + x * m + y << ' ' << 1 + a.size() + n * m + i << endl;
                    c[1 + a.size() + x * m + y + n * m][1 + a.size() + 2 * n * m + i] = 1;
                }
            }
        }
        c[1 + a.size() + 2 * n * m + i][T] = 1;
    }
    //cout << 'x' << endl;
    int flow = dinic();
    //cout << flow << endl;
    return flow == a.size();
}


int main()
{
    //freopen("in.txt", "r", stdin);


    cin >> n >> m >> k >> l;


    FOR(i,0,n)
    {
        cin >> s[i];
    }

    int x , y, v;
    scanf("%d%d%d" , &x , &y , &v);
    --x;--y;

    FOR(i,0,k)
    {
        int x , y, v;
        scanf("%d%d%d" , &x , &y , &v);
        --x;--y;
        a.push_back(MP(MP(x , y) , v));
    }
    FOR(i,0,l)
    {
        int x , y, v;
        scanf("%d%d%d" , &x , &y , &v);
        --x;--y;
        b.push_back(MP(MP(x , y) , v));
    }
    if (a.size() < b.size())
    {
            a.push_back(MP(MP(x , y) , v));
    }
    else
    {
        b.push_back(MP(MP(x , y) , v));
    }

    if (a.size() != b.size())
    {
        cout << -1 << endl;
        return 0;
    }

    FOR(i,0,500)
    {
        FOR(j,0,500)
        {
            d[i][j] = 1LL * INF * INF;
        }
        d[i][i] = 0;
    }

    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            if (ok(i, j))
            {
                FOR(dd,0,4)
                {
                    int x = i + dirx[dd];
                    int y = j + diry[dd];
                    if (ok(x, y))
                    {
                        d[i * m + j][x * m + y] = 1;
                    }
                }
            }
        }
    }

    FOR(k,0,n * m)
    {
        FOR(i,0,n * m)
        {
            FOR(j,0,n * m)
            {
                d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
            }
        }
    }

    /*FOR(i,0,n * m)
    {
            FOR(j,0,n * m)
            {

                cout << d[i][j] << ' ';
            }
            cout << endl;
    }*/

    N = 2 + a.size() + b.size() + 2 * n * m;
    S = 0;
    T = N - 1;

    Int L = 0;
    Int R = 1LL * INF * INF;
    while (R - L > 1)
    {
        Int MID = (L + R) / 2;
        //cout << MID << endl;
        if (F(MID))
        {
            R = MID;
        }
        else
        {
            L = MID;
        }
    }
    if (!F(R))
    {
        cout << -1 << endl;
        return 0;
    }
    if (F(L))
    {
        R = L;
    }
    cout << R << endl;



    return 0;
}