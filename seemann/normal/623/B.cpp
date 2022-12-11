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

const ll INF = 1e18L;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e6 + 100;

int a[MAXN];
int b[MAXN];
vector<int> c;
int n;

void fact(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            c.pb(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1)
        c.pb(x);
}
ll ans = INF;

ll A, B;
void test(int p) {
    forn(i, n)
        b[i] = a[i] % p;
    int l = -1, r = -1;
    int m = 0;
    forn(i, n) {
        if (b[i] != 0 && b[i] != 1 && b[i] != p - 1) {
            if (l == -1 || i < l)
                l = i;
            if (r == -1 || i > r)
                r = i;
        }
        if (b[i] == 1 || b[i] == p - 1)
            m++;
    }
    ll mx = 0;
    ll cur = 0;
    ll res = INF;
    if (l == -1)
        res = 0;
    forn(i, n) {
        cur += A;
        if (b[i] == 1 || b[i] == p - 1)
            cur -= B;
        if (i >= r || r == -1) {
            res = min(res, cur - mx);
        }
        if (cur > mx && (l == -1 || i < l)) {
            mx = cur;
        }
    }
    ans = min(ans, res + B * m);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int wa, wb;
    scanf("%d%d%d", &n, &wa, &wb);
    A = wa, B = wb;
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    fact(a[0]);
    fact(a[0] - 1);
    fact(a[0] + 1);
    fact(a[n - 1]);
    fact(a[n - 1] - 1);
    fact(a[n - 1] + 1);
    for (auto x : c) {
        test(x);
    }
    cout << ans << '\n';

    
    return 0;
}