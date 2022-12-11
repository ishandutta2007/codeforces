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
const int MAXN = 2e5 + 100;

int a[MAXN], b[MAXN], mleft[MAXN], mright[MAXN], st[MAXN];



int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    FOR(i, n)
        scanf("%d", &a[i]);
    FOR(i, n - 1) {
        b[i] = abs(a[i + 1] - a[i]);
    }
    n--;
    FOR(i, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        int ss = 0;
        for (int i = l; i < r; ++i) {
            while (ss > 0 && b[st[ss - 1]] <= b[i]) {
                ss--;
            }
            mleft[i] = ss > 0 ? st[ss - 1] : l - 1;
            st[ss++] = i;
        }
        ss = 0;
        for (int i = r - 1; i >= l; --i) {
            while (ss > 0 && b[st[ss - 1]] < b[i]) {
                ss--;
            }
            mright[i] = ss > 0 ? st[ss - 1] : r;
            st[ss++] = i;
        }
        ll ans = 0;
        for (int i = l; i < r; ++i) {
            ans += ((ll)b[i]) * (i - mleft[i]) * (mright[i] - i);
        }
        cout << ans << '\n';
    }



    return 0;
}