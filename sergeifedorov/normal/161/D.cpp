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
const int kmax = 510;

int n, k;
int t[nmax][kmax];
int used[nmax];
vector<int> g[nmax];
long long res;

void dfs(int v){
    used[v] = 1;
    t[v][0] = 1;
    for (int i = 0; i < g[v].size(); i ++)
        if (!used[g[v][i]]){
            dfs(g[v][i]);
            for (int j = 0; j < k; j ++){
                res = res + 1ll * t[v][k-j - 1] * t[g[v][i]][j];
            }
            for (int j = 0; j < k; j ++)
                t[v][j+1] += t[g[v][i]][j];
        }
}

int main ()
{
    cin >> n >> k;
    forn(i, n - 1){
        int u, v;
        scanf("%d %d", &u, &v);
        u --; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    memset(used, 0, sizeof used);
    dfs(0);
    cout << res << endl;
    

    return 0;
}