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

const int nmax = 5500;

vector<pii> w[nmax], g[nmax];
int n;
bool used[nmax];
int res[nmax], c[nmax], l[nmax], r[nmax], p[nmax], a[nmax];


void go(int v){
    used[v] = 1;
    forn(i, g[v].size())
        if (!used[g[v][i].fs]){
            c[g[v][i].fs] = g[v][i].sc;
            p[g[v][i].fs] = v;
            go(g[v][i].fs);
        }
}

int main ()
{
    scanf("%d", &n);
    forn(i, n){
        scanf("%d", &a[i]);
        w[i].pb(mp(a[i], i));
    }
    forn(i, n-1){
        int u,v,w;
        scanf("%d%d%d", &v,&u,&w);
        v--;u--;
        g[v].pb(mp(u,w));
        g[u].pb(mp(v,w));
    }
    go(0);
    c[0] = 0;
    memset(res, 255, sizeof res);
    res[0] = 0;
    forn(i, n+3){
        for (int j = 1; j < n; j++){
            r[j] = w[j].size();
            sort(w[j].begin() + l[j], w[j].end());
        }
        for (int j = 1; j < n; j++){
            for (int k = l[j]; k < r[j] && k < l[j] + c[j]; k++){
                w[p[j]].pb(w[j][k]);
                if (p[j] == 0)
                    res[w[j][k].sc] = i+1;
            }
            l[j] = min(r[j], l[j] + c[j]);
        }
      }
      forn(i, n)
        cout << res[i] << " ";
      cout << endl;


    return 0;
}