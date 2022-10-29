#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<ctime>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int g[100][100];
int deg[100];
int n, m;

bool read()
{
    if(scanf("%d%d", &n, &m) != 2)
        return false;
    forn (i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a][b]++;
        g[b][a]++;
        deg[a]++;
        deg[b]++;
    }
    return true;
}

void solve()
{
    int ans = 0;
    while(1)
    {
        vector<int> v;
        forn (i, n)
            if(deg[i] == 1)
                v.pb(i);
        if(v.size() == 0)
            break;
        ans++;
        forn (i, n)
            forn (j, v.size())
            {
                if(g[v[j]][i])
                {
                    deg[v[j]]--;
                    deg[i]--;
                    g[v[j]][i]--;
                }
            }
    }
    printf("%d\n", ans);
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(read())
       solve();
    return 0;
}