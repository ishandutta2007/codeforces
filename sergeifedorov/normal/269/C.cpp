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
#include <complex>
#include <bitset>
#include <queue>

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
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const long double eps = 1e-9;
const int inf = (int)1e9 + 100;//(1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x; }

const int nmax = 500100;

struct edge{
     int v, u, w, us, res;
     edge () {};
     edge(int v, int u, int w) : v(v), u(u), w(w), us(0) {};
};

int n, m;
edge e[nmax];
vector<int> g[nmax];
queue<int> q;
int sum[nmax], in[nmax], used[nmax];

void update(int v) {
    forn(i, g[v].size()) {
        int p = g[v][i];
        if (e[p].us) continue;
        e[p].us = e[p^1].us = 1;
        e[p].res = 0;
        e[p^1].res = 1;
        in[e[p].u] += e[p].w;
    }
    forn(i, g[v].size()) {
        int u = e[g[v][i]].u;
        if (in[u] == sum[u] / 2 && !used[u]) {
            if (u != n - 1) q.push(u);
            used[u] = 1;
        }
    }
}

int main ()
{
    cin >> n >> m;
    forn(i, m) {
         int u, v, w;
         scanf("%d %d %d", &u, &v, &w);
         u --; v--;
         e[2 * i] = edge(u, v, w);
         e[2 * i + 1] = edge(v, u, w);
        g[v].pb(2 * i + 1);
        g[u].pb(2 * i);
    }
    forn(i, n) {
        sum[i] = 0;
        in[i] = 0;
        forn(j, g[i].size())
            sum[i] += e[g[i][j]].w;
    }
    q.push(0);
    used[0] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        update(v);
    }
    forn(i, m)
        printf("%d\n", e[2*i].res);
        

    return 0;
}