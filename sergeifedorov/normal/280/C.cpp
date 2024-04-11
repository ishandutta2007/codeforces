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

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 100100;

int n;
vector<int> g[nmax];
int used[nmax];
double res;

void dfs(int v, int dep) {
    used[v] = 1;
    res += 1.0 / dep;
    forn(i, g[v].size()) 
        if (!used[g[v][i]]) {
            dfs(g[v][i], dep + 1);
    }
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        u --; v --;
        g[u].pb(v);
        g[v].pb(u);
    }                      
    res = 0;
    dfs(0, 1);
    printf("%0.9lf\n", res);

    return 0;
}