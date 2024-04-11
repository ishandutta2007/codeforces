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
const int MAXN = 5e5 + 100;

int a[MAXN];

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    scanf("%d", &n);
    FOR(i, n)
        scanf("%d", &a[i]);
    int ans = 0;
    int c = 0;
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || i == n - 1 || a[i] == a[i - 1] || a[i] == a[i + 1]) {
            if (c > 0) {
                r = i;
                if (a[l] == a[r]) {
                    for (int j = l + 1; j < r; ++j) {
                        a[j] = a[l];
                    }
                } else {
                    for (int j = l + 1; j < l + (r - l + 1) / 2; ++j) {
                        a[j] = a[l];
                    }
                    for (int j = l + (r - l + 1) / 2; j < r; ++j) {
                        a[j] = a[r];
                    }
                }
                ans = max(ans, (c + 1) / 2);
                c = 0;
            }
            l = i;
        } else {
            c++;
        }

    }
    ans = max(ans, (c + 1) / 2);
    printf("%d\n", ans);
    FOR(i, n) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}