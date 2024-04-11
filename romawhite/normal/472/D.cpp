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
#define Pi acos(-1.0)
#define y1 adsfasdgasg
#define x2 asdfagdsasdg
#define x1 twretwret
#define y2 oupoupoupo
#define eps 1e-10

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 1024;
const int MAX2 = 7000;
const int BASE = 1000000007;
const int CNT = 300;
const int MOD = 1000000007;

int a[2007][2007];

vector<pair<int,int> > g[2007];
bool used[2007];
Int d[2007];

void dfs(int v)
{
    used[v] = 1;
    FOR(i,0,g[v].size())
    {
        if (!used[g[v][i].first])
        {
            d[g[v][i].first] = d[v] + g[v][i].second;
            dfs(g[v][i].first);
        }
    }
}

int p[2007];

int find_set(int v)
{
    if (v == p[v]) return v;
    return p[v] = find_set(p[v]);
}

void union_sets(int a, int b, int c)
{
    int A = find_set(a);
    int B = find_set(b);
   // cout << a << ' ' << b << endl;
    if (A != B)
    {
        g[a].push_back(MP(b,c));
        g[b].push_back(MP(a,c));

       // cout << a << ' ' << b << ' ' << c << endl;

        p[B] = A;
    }
}

int main()
{
        #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        #endif

    //freopen("tetrahedron.in", "r", stdin);
    //freopen("tetrahedron.out", "w", stdout);

    int n;
    cin >> n;

    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            scanf("%d" , &a[i][j]);
        }
    }

    FOR(i,0,n)
    {
        if (a[i][i] != 0)
        {
            cout << "NO\n";
            return 0;
        }
    }


    int m = 0;

    vector<pair<int, pair<int,int> > > e;

    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
                if (a[i][j] != a[j][i] || (a[i][j] == 0 && i != j))
                {
                    cout << "NO\n";
                    return 0;
                }
                if (i > j)
                {
                    e.push_back(MP(a[i][j] , MP(i,j)));
                }
        }
    }


    sort(ALL(e));

    FOR(i,0,n)
    {
        p[i] = i;
    }

    FOR(i,0,e.size())
    {
        union_sets(e[i].second.first , e[i].second.second, e[i].first);
    }


    FOR(i,0,n)
    {
        FILL(used,0);
        FILL(d,0);
        dfs(i);
        FOR(j,0,n)
        {
            if (d[j] != a[i][j] || !used[j])
            {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}