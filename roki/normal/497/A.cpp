#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

typedef long long li;
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

int n, m;
const int N = 1005;
char c[N][N];

bool read() 
{
    if (scanf("%d%d\n", &n, &m) != 2)
        return false;
    forn (i, n)
        gets(c[i]);
    return true;
}

bool any[N];

void solve() 
{
    int ans = 0;
    forn (j, m)
    {
        bool ok = true;
        forn (i, n - 1)
        {
            if (any[i])
                continue;
            if (c[i][j] != c[i + 1][j])
                if (c[i][j] > c[i + 1][j])
                    ok = false;
        }
        if (ok)
        {
            forn (i, n - 1)
            {
                if (any[i])
                    continue;
                if (c[i][j] < c[i + 1][j])
                    any[i] = true;
            }
        }
        else
            ans++;
    }
    printf("%d\n", ans);
}

int main() 
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    while(read())   
        solve();

    return 0;
}