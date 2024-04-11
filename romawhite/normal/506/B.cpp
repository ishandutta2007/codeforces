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

const int INF = 1000100000;
const int MAX = 100007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

int clr[MAX];
bool U[MAX];
vector<int> G[MAX];
vector<int> g[MAX];

vector<int> a;
void dfs1(int v)
{
    U[v] = 1;
    a.push_back(v);
    FOR(i,0,G[v].size())
    {
        if (!U[G[v][i]])
        {
            dfs1(G[v][i]);
        }
    }
}

bool ok;

void dfs2(int v)
{
    clr[v] = 1;
    FOR(i,0,g[v].size())
    {
        int to = g[v][i];
        if (clr[to] == 0)
        {
            dfs2(to);
        }
        else
        {
            if (clr[to] == 1)
            {
                ok = 0;
            }
        }
    }
    clr[v] = 2;
}


int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt" , "w" , stdout);
    #endif

    int n, m;
    cin >> n >> m;
    FOR(i,0,m)
    {
        int  a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
        g[a].push_back(b);
    }

    int res = 0;

    FOR(i,0,n)
    {
        if (!U[i])
        {
            a.clear();
            dfs1(i);
            ok = 1;
            FOR(j,0,a.size())
            {
                if (clr[a[j]] == 0)
                {
                    dfs2(a[j]);
                }
            }
            res += a.size() - ok;
        }
    }

    cout << res << endl;



    return 0;
}