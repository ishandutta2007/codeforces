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
const int MAXM = MAXN * MAXN;


ldb p[MAXM];
ldb q[MAXM];
ldb a[MAXN];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif

    int n;
    scanf("%d", &n);
    ldb s = 0;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        p[i] = x * 0.01L;
        q[i] = 1/ p[i];
        s += q[i];
    }
    forn(j, n)
        a[j] = 1;
    ldb sum = 0;
    forn(i, 500000) {
        ldb bt =1;
        forn(j, n) {
            bt *= (1 - a[j]);
        }
        sum += (1 - bt);
        int mj = 0;
        if (i < n) {
            mj = i;
        } else {
            bt = -INF;
            forn(j, n) {
                ldb na = (1 - a[j] * (1 - p[j])) / (1 -  a[j]) ;
                if (na > bt) {
                    bt = na;
                    mj = j;
                }
            }
        }
        a[mj] *= (1 - p[mj]);
//        cerr << b[i] << '\n';
    }
    cout << fixed << setprecision(25) << sum << '\n';
    return 0;
}