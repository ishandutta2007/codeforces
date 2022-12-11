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

const int nmax = 155;
const int mod = 1e9 + 7;

int n, m;
int dp[nmax][nmax][nmax][2][2];

void add(int &a, int b) {
    a = a + b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> m;

    int res = 0;

    for (int i = 0; i < n; i ++) {
        for (int l = 0; l < m; l ++)
            for (int r = l; r < m; r ++)
                dp[i][l][r][0][0] ++;
        for (int l = 0; l < m; l ++)
            for (int r = l; r < m; r ++) {
                add(dp[i+1][l][r][0][0], dp[i][l][r][0][0]);
            }
        for (int len = 0; len < m; len ++)
            for (int l = 0; l + len < m; l ++) {
                int r = l + len;
                add(dp[i+1][l][r][0][0], dp[i+1][l + 1][r][0][0]);
                add(dp[i+1][l][r][0][0], dp[i+1][l][r - 1][0][0]);
                add(dp[i+1][l][r][0][0], -dp[i+1][l+1][r - 1][0][0]);
            }
        
        for (int l = 0; l < m; l ++)
            for (int r = l; r < m; r ++) {
                add(dp[i+1][l][r][0][1], dp[i][l][r][0][1]);
                if (l < r) 
                    add(dp[i+1][l][r-1][0][1], dp[i][l][r][0][0]);
            }
        for (int l = m - 1; l >= 0; l --)
            for (int r = m - 1; r >= l; r --) {
                add(dp[i+1][l][r][0][1], dp[i+1][l + 1][r][0][1]);
                add(dp[i+1][l][r][0][1], dp[i+1][l][r + 1][0][1]);
                add(dp[i+1][l][r][0][1], -dp[i+1][l + 1][r + 1][0][1]);
            }

        for (int l = 0; l < m; l ++)
            for (int r = l; r < m; r ++) {
                add(dp[i+1][l][r][1][0], dp[i][l][r][1][0]);
                if (l < r) 
                    add(dp[i+1][l+1][r][1][0], dp[i][l][r][0][0]);
            }
        for (int l = 0; l < m; l ++)
            for (int r = l; r < m; r ++) {
                if (l > 0) add(dp[i+1][l][r][1][0], dp[i+1][l - 1][r][1][0]);
                if (r > 0) add(dp[i+1][l][r][1][0], dp[i+1][l][r - 1][1][0]);
                if (l > 0 && r > 0) add(dp[i+1][l][r][1][0], -dp[i+1][l - 1][r - 1][1][0]);
            }
        for (int l = 0; l < m; l ++)
            for (int r = l; r < m; r ++) {
                add(dp[i+1][l][r][1][1], dp[i][l][r][1][1]);
                if (l < r) add(dp[i+1][l][r-1][1][1], dp[i][l][r][1][0]);
                if (l < r) add(dp[i+1][l+1][r][1][1], dp[i][l][r][0][1]);
                if (l + 1 < r) add(dp[i+1][l+1][r-1][1][1], dp[i][l][r][0][0]);
            }
        for (int len = m - 1; len >= 0; len --)
            for (int l = 0; l + len < m; l ++) {
                int r = l + len;
                add(dp[i+1][l][r][1][1], dp[i+1][l-1][r][1][1]);
                add(dp[i+1][l][r][1][1], dp[i+1][l][r + 1][1][1]);
                add(dp[i+1][l][r][1][1], -dp[i+1][l-1][r + 1][1][1]);
            }

        for (int l = 0; l < m; l ++)
            for (int r = l; r < m; r ++)
                forn(j, 2)
                    forn(k, 2)
                        add(res, dp[i][l][r][j][k]);
    }
    cout << res << endl;
//  cerr << clock() << endl;
    return 0;
}