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

const int nmax = 2020;
const int64 mod = 1e9 + 7;


int n, m;
int64 dp2[nmax][nmax];
int64 dp[nmax][nmax];
int64 dp3[nmax][nmax];
int64 s[nmax];
        
int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;

    for (int i = 2; i <= m; i ++)
        dp[1][i] = 1;
    for (int i = 1; i <= n; i ++) {
        memset(s, 0, sizeof s);
        for (int j = 0; j <= m; j ++)
            s[j+1] = (s[j] + dp[i][j]) % mod;
        for (int j = 1; j <= m; j ++)
            dp[i+1][j] = (dp[i+1][j-1] + s[j+1]) % mod;
    }
    forn(i, n+1)
        forn(j, m + 1)
            dp[i][j] = (dp[i][j] * (m - j + 1)) % mod;

    for (int i = 1; i <= n; i ++) {
        memset(s, 0, sizeof s);
        for (int j = m; j >= 0; j --)
            s[j] = (s[j+1] + dp[i-1][j]) % mod;
        for (int j = m; j >= 2; j --)
            dp2[i][j] = (dp2[i][j] + dp2[i][j+1] + s[j]) % mod;
        for (int j = m; j >= 2; j --)
            dp2[i][j] = (dp2[i][j] + mod - dp[i-1][j]) % mod;
    }

    for (int i = 1; i <= n; i ++) {
        memset(s, 0, sizeof s);
        for (int j = m; j >= 0; j --)
            s[j] = (s[j+1] + dp2[i-1][j]) % mod;
        for (int j = m; j >= 2; j --)
            dp3[i][j] = (dp3[i][j+1] + s[j]) % mod;
        for (int j = m; j >= 2; j --)
            dp2[i][j] = (dp2[i][j] + dp3[i][j]) % mod;
    }


    int64 res = 0;
    forn(i, n + 1)
        forn(j, m + 1)
            res = (res + (dp[i][j] + dp2[i][j]) * (n - i + 1)) % mod;
    
    cout << res << endl;

    return 0;
}