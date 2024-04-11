#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cassert>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);

int n, l, k;
const int N = 205;
ld p[N];
int d[N];

bool read() {
    if (!(cin >> n >> l >> k))
        return false;

    forn (i, n)
    {
        cin >> p[i];
        p[i] /= 100;
    }
    forn (i, n)
        cin >> d[i];
}

ld dp[N][N][2 * N + 5];

void solve() {
    dp[0][0][k + N] = 1;
    forn (i, n)
        forn (j, i + 1)
            forn (k, 2 * N + 5)
            {
                dp[i + 1][j + 1][min(2 * N + 4, k + d[i])] += dp[i][j][k] * p[i];
                dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i]);
            }

    ld ans = 0;
    for (int i = l; i <= n; ++i)
        for (int j = N; j < 2 * N + 5; ++j)
            ans += dp[n][i][j];

    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    while (read())
        solve();

    return 0;
}