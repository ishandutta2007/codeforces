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

const int nmax = 4040;

int n, k;
int a[nmax][nmax], s[nmax][nmax], g[nmax][nmax];
int dp[nmax][nmax];
char buf[1000100];

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> k;
    gets(buf);
    forn(i, n) {
        gets(buf);
        int j = 0;
        int m = strlen(buf);
        int now = 0;
        forn(q, m + 1) {
            if (buf[q] >= '0' && buf[q] <= '9') {
                now = now * 10 + buf[q] - '0';
                continue;
            }
            a[i][j] = now;
            now = 0;
            j ++;
        }
    }
                    
    forn(i, n) {
        s[i][0] = 0;
        for (int j = 0; j <= i; j ++) 
            s[i][j+1] = s[i][j] + a[i][j];
    }
    forn(i, n) {
        g[i][i] = 0;
        for (int j = i + 1; j < n; j ++) {
            g[i][j] = g[i][j-1] + s[j][j + 1] - s[j][i];
        }
    }   
    g[1][0] = 0;
    forn(i, n)
        dp[1][i + 1] = g[0][i];
    for (int i = 2; i <= k; i ++) {
        int pos = 0;
        dp[i][0] = 0;
        for (int j = 0; j < n; j ++) {
            while (1) {
                bool upd = 0;
                int now = dp[i-1][pos] + g[pos][j];
                for (int k = pos + 1; k <= j && k < pos + 100; k ++) {
                    int nxt = dp[i-1][k] + g[k][j];
                    if (nxt <= now) {
                        pos = k;
                        upd = 1;
                        break;
                    }
                }
                if (!upd) break;
            }
            dp[i][j+1] = dp[i-1][pos] + g[pos][j];
        }
    }
    cout << dp[k][n] << endl;
    cerr << clock() << endl;

    return 0;
}