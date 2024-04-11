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

const int nmax = 55;
const int mod = 1e9 + 7;

int n, k, e, w;
pii dp[nmax][nmax][2];
queue<pair<pii, int> > q;
int a[nmax];
int64 cnk[nmax][nmax];

void add(int x, int y, int b, int dep, int64 cnt)  {
    if (dp[x][y][b].fs == -1) {
        dp[x][y][b] = mp(dep, 0);
        q.push(mp(mp(x, y), b));
    }
    if (dp[x][y][b].fs < dep) return;
    dp[x][y][b].sc += cnt;
    if (dp[x][y][b].sc >= mod)
        dp[x][y][b].sc -= mod;

}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cnk[0][0] = 1;
    for (int i = 1; i < nmax; i ++)
        for (int j = 0; j <= i; j ++) {
            if (j > 0) cnk[i][j] += cnk[i-1][j-1];
            cnk[i][j] += cnk[i-1][j];
//          cnk[i][j] %= mod;
        }

    cin >> n >> k;
    k /= 50;
    forn(i, n) {
        cin >> a[i];
        a[i] /= 50;
        if (a[i] == 1)
            e ++;
        else
            w ++;
    }
    memset(dp, 255, sizeof dp);
    add(e, w, 0, 0, 1);
    while (!q.empty()) {
        pair<pii, int> now = q.front();
        q.pop();
        int x = now.fs.fs, y = now.fs.sc, v = now.sc;
        if (v == 0) {
            for (int i = 0; i <= x; i ++)
                for (int j = 0; j <= y && i + j * 2 <= k; j ++)
                    if (i + j > 0)
                        add(x - i, y - j, 1, dp[x][y][v].fs + 1, (dp[x][y][v].sc * cnk[x][i] % mod) * cnk[y][j] % mod);
        } else {
            int nx = e - x;
            int ny = w - y;
            for (int i = 0; i <= nx; i ++)
                for (int j = 0; j <= ny && i + j * 2 <= k; j ++)
                    if (i + j > 0)
                        add(x + i, y + j, 0, dp[x][y][v].fs + 1, (dp[x][y][v].sc * cnk[nx][i] % mod) * cnk[ny][j] % mod);
        }
     }
     if (dp[0][0][1].fs == -1) dp[0][0][1].sc = 0;
     cout << dp[0][0][1].fs << endl;
     cout << dp[0][0][1].sc << endl;

    

    return 0;
}