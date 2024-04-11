#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:167772016")

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

const int INF = int(1e9) + 6;
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

int n;
const int N = 500;
int a[N];
int c[N];

bool read() 
{   
    cin >> n;
    forn (i, n)
        cin >> a[i];
    forn (i, n)
        cin >> c[i];
    return true;
}

vector<pt> fact[N];

void f(int id)
{
    int x = a[id];
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            int deg = 0;
            while (x % i == 0)
                x /= i, deg++;
            fact[id].pb(mp(i, deg));
        } 
    }
    if (x > 1)
        fact[id].pb(mp(x, 1));
}

const int M = 10;

int res[1 << M];

void move(int mask, int ct)
{
    forn (i, 1 << M)
        res[i | mask] = min(res[i | mask], res[i] + ct);
}

void solve() 
{   
    forn (i, n)
        f(i);

    int ans = INF;

    forn (i, n)
    {
        forn (j, 1 << M)
            res[j] = INF;
        res[0] = 0;

        forn (j, n)
        {
            int r = 0;
            int mask = 0;
            forn (l, fact[i].size())
            {
                while(r < fact[j].size() && fact[j][r].ft < fact[i][l].ft)
                    r++;
                if (r == fact[j].size() || fact[j][r].ft != fact[i][l].ft)
                    mask ^= 1 << l;
            }
            if (mask != 0)
                move(mask, c[j]);
        }

        ans = min(ans, res[(1 << fact[i].size()) - 1] + c[i]);
    }

    if (ans == INF)
        ans = -1;

    cout << ans << endl;
}

int main() 
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}