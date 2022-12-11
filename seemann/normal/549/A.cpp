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
const int MAXN = 110;

char c[MAXN][MAXN];

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m;
    cin >> n >> m;
    FOR(i, n) {
        FOR(j, m) {
            cin >> c[i][j];
        }
    }
    int ans = 0;
    FOR(i, n - 1)  {
        FOR(j, m - 1) {
            set<char> s;
            FOR(x, 2)
                FOR(y, 2) {
                    s.insert(c[i + x][j + y]);
                }
            if (s.count('f') > 0 && s.count('a') > 0 && s.count('c') > 0 && s.count('e') > 0)
                ans++;





        }
    }
    cout << ans << '\n';
    return 0;
}