#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<ld, ld> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second
#define x first
#define y second

const int INF = 1e9;
const ld EPS = 1e-10;

const int N = 2000;
int dist[N][N];
int n;

bool read()
{
    scanf("%d", &n);
    
    forn (i, n)
        forn (j, n)
            scanf("%d", &dist[i][j]);

    return true;
}

vector<pair<int, int> > g[N];

int u[N];
int T = 1;
int d[N];

void dfs(int v)
{
    u[v] = T;
    forn (i, g[v].size())
    {
        int to = g[v][i].ft;
        if (u[to] == T)
            continue;
        d[to] = d[v] + g[v][i].sc;
        dfs(to);
    }
}

void solve() 
{
    forn (i, n)
        forn (j, n)
        if (dist[i][j] != dist[j][i] || dist[i][i] != 0)
        {
            puts("NO");
            return;
        }

    vector<bool> used(n, false);
    vector<int> D(n, INF);
    vector<int> p(n, 0);
    D[0] = 0;

    forn (i, n)
    {
        int cur = 0;
        
        forn (j, n)
        {
            if (used[cur] || D[j] < D[cur] && !used[j])
                cur = j;
        }

        if (D[cur] == 0 && i != 0)
        {
            puts("NO");
            return;
        }

        used[cur] = true;

        if (i != 0)
        {
            g[cur].pb(mp(p[cur], D[cur]));
            g[p[cur]].pb(mp(cur, D[cur]));
            d[cur] = 0;
            T++;
            dfs(cur);
            forn (j, n)
                if (used[j] && dist[cur][j] != d[j])
                {
                    puts("NO");
                    return;
                }
        }

        forn (j, n)
            if (dist[cur][j] < D[j])
                D[j] = dist[cur][j], p[j] = cur;
    }
    
    cout << "YES" << endl;
}   

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    read();
    solve();

    return 0;
}