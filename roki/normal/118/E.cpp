#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

vector<int> g[100000], ng[100000];
vector<int> color(100000, 0);
vector<int> tin(100000), fup(100000);
int tim = 1;
bool good = true;

void dfs(int v, int p)
{
    tin[v] = fup[v] = tim++;
    color[v] = 1;
    forn (i, g[v].size())
    {
        if(color[g[v][i]] != 0 && g[v][i] != p)
            fup[v] = min(fup[v], tin[g[v][i]]);
        if(color[g[v][i]] == 0)
        {
            ng[v].pb(g[v][i]);
            dfs(g[v][i], v);
            fup[v] = min(fup[v], fup[g[v][i]]);
            if(fup[g[v][i]] > tin[v])
                good = false;
        }
        if(color[g[v][i]] == 1 && g[v][i] != p)
            ng[v].pb(g[v][i]);
    }
    color[v] = 2;
}

int main()
{
   int n, m;
    cin >> n >> m;
    forn (i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a); 
    }
    dfs(0, 0);
    if(!good)
        cout << 0 << endl;
    else
        forn (i, n)
        forn (j, ng[i].size())
            cout << i + 1 << ' ' << ng[i][j] + 1 << endl;
    return 0;
}