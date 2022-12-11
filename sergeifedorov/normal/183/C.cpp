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
#include <bitset>
#include <sstream>
#include <complex>

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

long long gcd(long long a, long long b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

const int nmax = 100500;

int n, m, k;
vector<int> g[nmax], og[nmax];
int dep[nmax], used[nmax], in[nmax], out[nmax];
int step = 2;

void dfs(int v, int dp){
    used[v] = 1;
    dep[v] = dp;
    forn(i, g[v].size()){
        if (used[g[v][i]] == 0){
            dfs(g[v][i], dp + 1);
            continue;
        }
        int now = 0;
        now = abs(dep[v] - dep[g[v][i]] + 1);
        k = gcd(k, now);
    }
    forn(i, og[v].size()){
        if (used[og[v][i]] == 0){
            dfs(og[v][i], dp - 1);
            continue;
        }
        int now = 0;
        now = abs(dep[v] - dep[og[v][i]] - 1);
        k = gcd(k, now);
    }
    used[v] = 2;
}



int main ()
{
    cin >> n >> m;
    vector<pii> e;
    forn(i, m){
        int u, v;
        scanf("%d %d", &u, &v);
        u --; v--;
        if (u == v){
            puts("1");
            exit(0);
        }
        e.pb(mp(u, v));
    }
    sort(all(e));
    e.erase(unique(all(e)), e.end());
    forn(i, e.size()){
        int v = e[i].fs;
        int u = e[i].sc;
        g[v].pb(u);
        og[u].pb(v);
        in[u] ++;  
        out[v] ++;
    }
/*
    vector<int> a;
    forn(i, n)
        if (in[i] == 0)
            a.pb(i);
    forn(i, n)
        if (out[i] == 0)
            a.pb(i);    
    forn(i, a.size()){
        if (used[a[i]] == 10)
            continue;
        used[a[i]] = 10;
        forn(j, g[a[i]].size()){
            in[g[a[i]][j]] --;
            if (in[g[a[i]][j]] == 0)
                a.pb(g[a[i]][j]);
        }
        forn(j, og[a[i]].size()){
            out[og[a[i]][j]] --;
            if (out[og[a[i]][j]] == 0)
                a.pb(og[a[i]][j]);
        }
    }  */
    k = 0;
    forn(i, n)
        if (!used[i])
            dfs(i, 0);
    if (k == 0) k = n;
    cout << k << endl;

    return 0;
}