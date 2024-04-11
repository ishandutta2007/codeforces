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

vector< int > b[100];
vector< int > a[100];
int n, m;
bool u[100];
int ans;

bool read()
{
    if(scanf("%d%d", &n, &m) != 2)
        return false;
    int t = 0;
    forn (i, n)
    {
        int k;
        scanf("%d", &k);
        if(k == 0)
            t++;
        forn (j, k)
        {
            int l;
            scanf("%d", &l);
            l--;
            b[l].pb(i);
            a[i].pb(l);
        }
    }
    if(t == n)
    {
        printf("%d\n", n);
        return false;
    }
    return true;
}


void dfs(int v)
{
    u[v] = true;
    forn (i, a[v].size())
        forn (j, b[a[v][i]].size())
            if(!u[b[a[v][i]][j]])
                dfs(b[a[v][i]][j]);
}

void solve()
{
    int ans = 0;
    forn (i, n)
        if(!u[i])
        {
            ans++;
            dfs(i);
        }
    printf("%d\n", ans - 1);
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