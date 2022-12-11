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


vector<int> g[nmax], w[nmax];
int t[nmax], res[nmax], used[nmax], vis[nmax];
int n, m;

long long gcd(long long a, long long b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

void dfs(int v){
    used[v] = 1;
    forn(i, g[v].size()){
        if (!used[g[v][i]] && t[g[v][i]] != 1)
            dfs(g[v][i]);
        used[g[v][i]] = 1;
    }
}

void go(int v){
    vis[v] = 1;
    forn(i, w[v].size())
        if (!vis[w[v][i]] && t[w[v][i]] != 1)
            go(w[v][i]);
}

int main ()
{
     cin >> n >> m;
     forn(i, n)
        scanf("%d", &t[i]);
     forn(i, m){
        int u, v;
        scanf("%d %d", &u, &v);
        u --;
        v --;
        g[v].pb(u);
        w[u].pb(v);
     }
     memset(used, 0, sizeof used);
     memset(vis, 0, sizeof vis);
     forn(i, n)
        if (!used[i] && t[i] == 2)
            dfs(i);
    forn(i, n)
        if (!vis[i] && t[i] == 1)
            go(i);              
    forn(i, n)
        if (vis[i] && used[i])
            printf("1\n");
        else
            printf("0\n");
    

    return 0;
}