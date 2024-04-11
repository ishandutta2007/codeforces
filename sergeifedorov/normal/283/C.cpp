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

int n, q, t;
int dp[nmax];
int a[nmax];
vector<int> g[nmax], e[nmax];
int in[nmax];
int used[nmax];
vector<int> w;

const int mod = 1e9 + 7;

void write(int x) {
    cout << x << endl;
    exit(0);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n >> q >> t;
    forn(i, n)
        scanf("%d", &a[i]);
    forn(i, q) {
         int v, u;
         scanf("%d %d", &v, &u);
         v --;
         u --;
         g[v].pb(u);
         in[u] ++;
    }
    int m = 0;
    forn(i, n)
        if (in[i] == 0) {
            int now = i;
            while (1) {
                used[now] = 1;
                e[m].pb(now);
                if (g[now].size() == 0) break;
                now = g[now][0];
                if (used[now])
                    write(0);
            }
            m ++;
        }
    forn(i, n)
        if (!used[i])
            write(0);
    forn(i, m) {
        int now = 0;
        forn(j, e[i].size()) {
            t -= now;
            if (t < 0) write(0);
            now += a[e[i][j]];
            w.pb(now);
        }
    }
    if (t < 0) write(0);
    dp[0] = 1;
    forn(i, w.size()) {
        int q = w[i];
        for (int j = 0; j + q <= t; j ++) {
            dp[j + q] += dp[j];
            if (dp[j + q] >= mod)
                dp[j + q] -= mod;
        }
    }
    cout << dp[t] << endl;
    return 0;
}