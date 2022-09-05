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
const int MAX = 50007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

int c[107][107];
int f[107][107];

int s, t;
int d[107], ptr[107], q[107];
int N;

bool bfs()
{
    int l = 0, r = 0;
    q[r++] = s;
    FILL(d, -1);
    d[s] = 0;
    while (l < r)
    {
        int v = q[l++];
        FOR(j,0,N)
            if (d[j] == -1 && f[v][j] < c[v][j])
            {
                q[r++] = j;
                d[j] = d[v] + 1;
            }
    }


    return d[t] != -1;
}

int dfs (int v, int flow)
{
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (int & to = ptr[v]; to < N; ++to)
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
    while(1)
    {
        if (!bfs())  break;
        FILL(ptr, 0);
        while (int pushed = dfs (s, INF))
        {
            flow += pushed;
        }
    }
    return flow;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    #endif

    vector<int> p;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    FOR(i,0,n)
    {
        cin >> a[i];
        int x = a[i];
        for(int j = 2; j * j <= x; ++j)
        {
            if (x % j == 0)
            {
                p.push_back(j);
                while (x % j == 0)
                {
                    x /= j;
                }
            }
        }
        if (x != 1)
        {
            p.push_back(x);
        }
    }

    sort(ALL(p));
    p.resize(unique(ALL(p)) - p.begin());

    vector<pair<int, int> > e;

    FOR(i,0,m)
    {
        int a , b;
        cin >> a >> b;
        e.push_back(MP(a, b));
    }
    int res = 0;
    FOR(i,0,p.size())
    {
        FILL(f,0);
        FILL(c,0);
        N = n + 2;
        s = 0;
        t = N - 1;

        FOR(j,0,n)
        {
            int x = a[j];
            int cc = 0;
            while(x % p[i] == 0)
            {
                ++cc;
                x /= p[i];
            }
            if (j % 2 == 0)
            {
                c[s][j + 1] = cc;
               // cout << s << ' ' << j + 1 << ' ' << cc << endl;
            }
            else
            {
                c[j + 1][t] = cc;
                //cout << j + 1 << ' ' << t << ' ' << cc << endl;
            }
        }

        FOR(j,0,m)
        {
            if (e[j].first % 2 == 0)
            {
                swap(e[j].first , e[j].second);
            }
            //cout << e[j].first << ' ' << e[j].second << endl;
            c[e[j].first][e[j].second] = 100;

        }

        res += dinic();
        //cout << endl;
    }

    cout << res << endl;



    return 0;
}