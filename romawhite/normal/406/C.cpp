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

vector<int> g[MAXN];

vector<pair<int,pair<int,int> > > res;

bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

bool dfs(int v, int p)
{
    tin[v] = fup[v] = timer++;
    vector<int> b;
    used[v] = 1;
    FOR(i,0,g[v].size())
        if (g[v][i] != p)
        {
            int to = g[v][i];
            if (used[to])
            {
                fup[v] = min (fup[v], tin[to]);
                if (tin[to] >= tin[v])
                {
                    b.push_back(to);
                }
            }
            else {
                if (dfs (to, v))
                {
                    b.push_back(to);
                }
                fup[v] = min (fup[v], fup[to]);

            }
        }
    FOR(i,0,b.size() / 2)
    {
            res.push_back(MP(b[2 * i] , MP(v , b[2 * i + 1])));
    }
    if (b.size() % 2 == 1)
    {
        res.push_back(MP(b.back() , MP(v,p)));
        return 0;
    }
    return 1;
}

int main()
{
   int n,m;
   cin >> n >> m;
   if (m % 2 == 1)
   {
        cout << "No solution" << endl;
        return 0;
   }

    FOR(i,0,m)
    {
        int a,b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0,-1);

    FOR(i,0,res.size())
        cout << res[i].first + 1 << ' ' << res[i].second.first + 1 << ' ' << res[i].second.second + 1 << endl;

}