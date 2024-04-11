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
string s;
char res[nmax];
int dp[nmax];
int step = 0;
int kill[nmax];

void dfs(int v, vector<int> &a) {
    a.pb(v);
    used[v] = step;
    dp[v] = 1;
    forn(i, g[v].size())
        if (!kill[g[v][i]] && used[g[v][i]] < step) {
            dfs(g[v][i], a);
            dp[v] += dp[g[v][i]];
        }
}

int get(int rt, vector<int> &a) {
    step ++;
    dfs(rt, a);
    int res = a[0];
    int bst = 1e9;
    forn(i, a.size()) {
        int now = a.size() - dp[a[i]];
        forn(j, g[a[i]].size()) {
            int u = g[a[i]][j];
            if (!kill[u] && dp[u] <= dp[a[i]])
                now = max(now, dp[u]);          
        }
        if (now < bst) {
            bst = now;
            res = a[i];
        }
    }
    return res; 
}

void go(int rt, char c) {
    vector<int> a;
    int v = get(rt, a);
    res[v] = c;
    kill[v] = 1;
    int nd = step;
    step ++;
    forn(i, a.size())
        if (used[a[i]] == nd && !kill[a[i]])
            go(a[i], c + 1);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        g[u].pb(v);
        g[v].pb(u);
    }   
    go(0, 'A');

    forn(i, n)
        printf("%c ", res[i]);
    puts("");

    return 0;
}