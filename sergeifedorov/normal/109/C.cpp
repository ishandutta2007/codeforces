#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 100100;

map<int, bool> good;
vector<pii> g[nmax];
int res[nmax];
bool used[nmax];
int down[nmax];
int n;

void gen(long long now){
    if (now > 1e9)
        return;
    if (now != 0)
        good[now] = 1;
    gen(now * 10 + 4);
    gen(now * 10 + 7);
}

int go(int v){
    used[v] = 1;
    down[v] = 1;
    forn(i, g[v].size())
        if (!used[g[v][i].fs])
            down[v] += go(g[v][i].fs);
    return down[v];
}

int calc(int v){
    used[v] = 1;
    res[v] = 0;
    forn(i, g[v].size())
        if (!used[g[v][i].fs]){
             if (good[g[v][i].sc]){
                res[v] += down[g[v][i].fs];
                calc(g[v][i].fs);
               }else
                res[v] += calc(g[v][i].fs);
        }
    return res[v];
}

void solve(int v, bool last, int p){
    used[v] = 1;
    if (last)
        res[v] += n - down[v];
    if (!last && p != -1)
        res[v] = res[p];
    forn(i, g[v].size())
        if (!used[g[v][i].fs]){
             if (good[g[v][i].sc]){
                solve(g[v][i].fs, 1, v);
               }else
                solve(g[v][i].fs, 0, v);
        }
}



int main ()
{
    gen(0);
    cin >> n;
    forn(i, n-1){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }
    memset(res, 0, sizeof res);
    memset(down, 0, sizeof down);
    go(0);
//  forn(i, n)
//      cerr << down[i] << " ";
//  cerr << endl;
    memset(used, 0, sizeof used);
    calc(0);
//  forn(i, n)
//      cerr << res[i] << " ";
//  cerr << endl;
    memset(used, 0, sizeof used);
    solve(0, 0, -1);
//  forn(i, n)
//      cerr << res[i] << " ";
//  cerr << endl;

    long long ans = 0;
    forn(i, n)
        ans = ans + 1ll * res[i] * (res[i]-1);
    cout << ans << endl;

    return 0;
}