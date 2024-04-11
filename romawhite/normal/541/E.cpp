#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
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

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 1007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

vector<int> g[MAX];
int clr[MAX];
int comp[MAX];
int C;
bool ok = 1;

void dfs(int v)
{
    comp[v] = C;
    FOR(i,0,g[v].size())
    {
        if (comp[g[v][i]] == -1)
        {
            clr[g[v][i]] = (clr[v] ^ 1);
            dfs(g[v][i]);
        }
        else
        {
            if (clr[g[v][i]] == clr[v])
            {
                ok = 0;
            }
        }
    }
}

int res[MAX];

int q[MAX];
int d[MAX];

int n , m;

int go(int s)
{
    FOR(i,0,n)
    {
        d[i] = INF;
    }
    d[s] = 0;
    int L = 0;
    int R = 1;
    q[0] = s;

    int res = 0;

    while (L < R)
    {
        int v = q[L++];
        FOR(i,0,g[v].size())
        {
            int to = g[v][i];
            if (d[to] == INF)
            {

                d[to] = d[v] + 1;
                res = d[to];
                q[R++] = to;
            }
        }
    }

    return res;
}

int main()
{
   //   freopen("in.txt","r",stdin);
 //   freopen("C:/output.txt" , "w" , stdout);

    cin >> n >> m;

    FOR(i,0,m)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    FILL(comp, -1);
    C = 0;
    FOR(i,0,n)
    {
        if (comp[i] == -1)
        {
            clr[i] = 0;
            dfs(i);
            ++C;
        }
    }

    if (!ok)
    {
        cout << -1 << endl;
        return 0;
    }

    FOR(i,0,n)
    {
        res[comp[i]] = max(res[comp[i]] , go(i));
    }

    int R = 0;
    FOR(i,0,C)
    {
        R += res[i];
    }

    cout << R << endl;

    return 0;
}