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
const int MAXA = 30;
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 100;
ll ans[MAXA];
int last[MAXA];
char s[MAXN];

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    forn(i, k) {
        last[i] = -1;
        ans[i] = 0;
    }
    ll sum = 1;
    scanf("%s", s);
    int m = strlen(s);
    n += m;
    forn(i, n) {
        int c = 0;
        if (i < m) {
            c = s[i] - 'a';
        } else {
            c = 0;
            forn(i, k) {
                if (last[i] < last[c])
                    c = i;
            }
        }
        last[c] = i;
        ll dt = sum - ans[c];
        if (dt < 0)
            dt += MOD;
        ans[c] = sum;
        sum += dt;
        if (sum >= MOD)
            sum -= MOD;
    }
    cout << sum % MOD<< '\n';
    
    return 0;
}