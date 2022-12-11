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
const int MAXN = 1e5;

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    int f1 = 0;
    int f2 = 1;
    forn(i, q) {
        int tp;
        scanf("%d", &tp);
        if (tp == 2) {
            swap(f1, f2);
        } else {
            int s;
            scanf("%d", &s);
            if (s < 0)
                s += n;
            bool flag = false;
            if (s % 2 == 1) {
                s--;
                flag = true;
            }
            f1 = (f1 - s + n) % n;
            f2 = (f2 - s + n) % n;
            if (flag) {
                f2 = (f2 - 2 + n) % n;
                swap(f1, f2);
            }
        }
    }
    forn(i, n / 2) {
        printf("%d %d ", f1 + 1, f2 + 1);
        f1 = (f1 + 2) % n;
        f2 = (f2 + 2) % n;
    }
    return 0;
}