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

long long gcd(long long a, long long b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

struct edge{
    int v, u, w, c;
    edge () {}
    edge (int v1, int u1, int c1, int w1){
        v = v1;
        u = u1;
        c = c1;
        w = w1;
    }
};

const int nmax = 10100;
const int emax = 100100;

edge e[emax];
pair<pii, pii> a[nmax];
int n, k;
int res[nmax];
vector<int> g[nmax];
int posi[nmax];
int sz;

void add(int v, int u, int f, int w){
//  cerr << v << " " << u << " " << w << endl;
    e[sz] = edge(v, u, f, w);
    e[sz^1] = edge(u, v, 0, -w);
    g[v].pb(sz);
    g[u].pb(sz ^ 1);
    sz += 2;
}

int d[nmax], p[nmax];
int q[nmax * 100];
int h, t;
int used[nmax];

void add(int v, int dp){
    if (d[v] > dp){
        if (!used[v]){
            q[t] = v;
            t ++;
            if (t == nmax * 100)
                t = 0;
        }
        d[v] = dp;
    }
}

void flow(){
    forn(i, 2 * n + 2)
        d[i] = inf;
    h = t = 0;
    memset(used, 0, sizeof used);
    add(2 * n, 0);
    while (h != t){
        int v = q[h];
        h ++;
        if (h == nmax * 100)
            h = 0;
        used[v] = 0;
        forn(i, g[v].size()){
            int ne = g[v][i];
            if (e[ne].c > 0 && d[e[ne].u] > d[v] + e[ne].w){
                p[e[ne].u] = ne;
                add(e[ne].u, d[v] + e[ne].w);
            }
        }
    }
//  cerr << d[2 * n + 1] << endl;
    if (d[2 * n + 1] >= 1e8)
        return;
    int now = 2 * n + 1;
    while (now != 2 * n){
        int pos = p[now];
        e[pos].c --;
        e[pos^1].c ++;
        now = e[pos].v;
        }
}

int main ()
{
    cin >> n >> k;
    forn(i, n){
        scanf("%d %d %d", &a[i].fs.fs, &a[i].fs.sc, &a[i].sc.fs);
        a[i].sc.sc = i;
    }

/*     n = 1000;
     k = 50;
     forn(i, n){
        a[i].fs.fs = i;
        a[i].fs.sc = i + k;
        a[i].sc.fs = rand();
        a[i].sc.sc = i;
     }
*/  
    int s = 2 * n;
    int t = 2 * n + 1;  

    forn(i, n)
        add(s, i, 10000, 0);
    forn(i, n){
        add(i, t, 10000, 0);
        add(n + i, t, 10000, 0);
    }

    
    forn(i, n){
        posi[i] = sz;
        add(i, n + i, 1, -a[i].sc.fs);
    }


    vector<pii> nc, kc;
    forn(i, n){
        nc.pb(mp(a[i].fs.fs, i));
        kc.pb(mp(a[i].fs.fs + a[i].fs.sc, i));
    }
    sort(all(nc));
    sort(all(kc));
    forn(i, nc.size() - 1)
        add(nc[i].sc, nc[i+1].sc, 10000, 0);
    int pos = 0;
    forn(i, kc.size()){
        while (pos < nc.size() && nc[pos].fs < kc[i].fs)
            pos ++;
        if (pos >= nc.size())
            break;
        add(n + kc[i].sc, nc[pos].sc, 10000, 0);
    }

    forn(i, k)
        flow();
    forn(i, n)
        if (e[posi[i]].c == 0)
            res[i] = 1;
        else
            res[i] = 0;
    forn(i, n)
        printf("%d ", res[i]);
    puts("");



    return 0;
}