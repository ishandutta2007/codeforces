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

const int tmax = 110;
const int nmax = 1010;

vector<int> g[tmax];
int dp[tmax][nmax];
int n, st;

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> st;
    forn(i, n) {
        int t, q;
        cin >> t >> q;
        if (t <= st)
            g[st - t].pb(q);
    }

    for (int i = 0; i <= st; i ++) {
        sort(all(g[i]));
        reverse(all(g[i]));
    }

    memset(dp, 255, sizeof dp);
    dp[0][1] = 0;
    int res = 0;
    for (int i = 0; i <= st; i ++) 
        for (int j = 0; j <= n; j ++)
            if (dp[i][j] >= 0) {
                int sum = 0;
                for (int k = 0; k <= g[i].size() && k <= j; k ++) {
                    int np = min(n, (j - k) * 2);
                    dp[i+1][np] = max(dp[i+1][np], dp[i][j] + sum);
                    res = max(res, dp[i+1][np]);
                    if (k < g[i].size())
                        sum += g[i][k];                 
                }
            }
    cout << res << endl;    

    return 0;
}