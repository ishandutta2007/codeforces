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

const int MAX = 2007;
const int MOD = 1000000007;

vector<int> g[MAX];
bool used[MAX];
int tin[MAX];
int fup[MAX];
int T = 0;

vector<int> G[MAX];

vector<pair<int,int> > e;
set<pair<int,int> > S;

void dfs (int v, int p)
{
    used[v] = 1;
    tin[v] = fup[v] = T++;
    FOR(i,0,g[v].size())
    {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
        {
            fup[v] = min(fup[v], tin[to]);
        }
        else
        {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
            {
                e.push_back(MP(to,v));
                //cout << to << ' ' << v << endl;
                S.insert(MP(to,v));
                S.insert(MP(v,to));
            }
        }
    }
}

int cmp = 0;
int cnt[MAX];
int c[MAX];
void dfs2(int v)
{
    cnt[cmp]++;
    c[v] = cmp;
    used[v] = 1;
    FOR(i,0,g[v].size())
    {
        if (!used[g[v][i]] && S.find(MP(v, g[v][i])) == S.end())
        {
            dfs2(g[v][i]);
        }
    }
}

int r = 0;
int d[MAX];
int dfs3(int v)
{
    used[v] = 1;
    d[v] = cnt[v];
    int t = 0;
    FOR(i,0,G[v].size())
    {
        if (!used[G[v][i]])
        {
            t += dfs3(G[v][i]);
            d[v] += d[G[v][i]];
            t += cnt[v] * d[G[v][i]];
        }
    }
    return t;
}

bool dp[MAX];

int main()
{
    //freopen("in.txt" , "r" , stdin);
  //  freopen("out.txt" , "w" , stdout);

    int n,m;
    cin >> n >> m;

    FOR(i,0,m)
    {
        int a,b;
        scanf("%d%d" , &a , &b);
        --a;--b;

        g[a].push_back(b);
        g[b].push_back(a);

    }

    dfs(0, -1);

    FILL(used,0);
    Int res = 0;
    FOR(i,0,n)
    {
        if (!used[i])
        {
            dfs2(i);
            res += cnt[cmp] * cnt[cmp];
            cmp++;
        }
    }

    FOR(i,0,e.size())
    {
        int a = e[i].first;
        int b = e[i].second;
        G[c[a]].push_back(c[b]);
        G[c[b]].push_back(c[a]);
    }

    int R = 0;
    //cout << res << endl;
    FOR(v,0,cmp)
    {
        FILL(used,0);
        FILL(dp,0);
        FILL(d,0);
        used[v] = 1;
        vector<int> a;
        int rr = 0;
        FOR(i,0,G[v].size())
        {
            rr += dfs3(G[v][i]);
            a.push_back(d[G[v][i]]);
        }
        //FOR(i,0,a.size())
        //{
        //    cout << a[i] << ' ';
        //}
        //cout << endl;
        rr += cnt[v] * (n - cnt[v]);
        dp[0] = 1;
        FOR(i,0,a.size())
        {
            RFOR(j,MAX,0)
            {
                if (dp[j])
                {
                    dp[j + a[i]] = 1;
                }
            }
        }

        int r = 0;
        FOR(i,0,MAX)
        {
            if (dp[i])
            {
                r = max(r, i * (n - cnt[v] - i));
            }
        }
        rr += r;
        R = max(R , rr);
    }

    cout << res + R << endl;

    return 0;
}