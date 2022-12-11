#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 210;
int d[MAXN][MAXN];
ll sum[MAXN][MAXN];
//int up[MAXN];

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m;
    cin >> n >> m;
    FOR(i, n)
        FOR(j, m) {
            char c;
            cin >> c;
            d[i][j] = 1;
            if (c == 'B')
                d[i][j] = -1;
        }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ll r = 0;
        for (int j = m - 1; j >= 0; --j) {
            ll cur = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
            sum[i][j] = cur;
//            cerr << i << ' ' << j << ' ' << cur << ' ' << d[i][j] << '\n';
            if (cur == d[i][j])
                continue;
            ll dt = d[i][j] - cur;
            ans++;
            sum[i][j] += dt;
        }
        /*
        FOR(j, m)
            cerr << up[j] << ' ';
        cerr << '\n';*/
    }
    cout << ans << '\n';

    return 0;
}