#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <random>
#include <bitset>
#include <time.h>
using namespace std;

//#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;

const int MAXN = 50000;

ll p;

void fix(ll &x) {
    while (x >= p) {
        x -= p;
    }
    while (x < 0) {
        x += p;
    }
}
/*
ll mul(ll a, ll b) {
    ll ret = 0;
    while (b) {
        if (b & 1)  ret += a;
        a = a + a;
        fix(a);
        b >>= 1;
    }
    return ret;
}
 */

ll mul(ll a,ll b) {return ((a*b-ll((long double)a*b/p)*p)%p+p)%p;}

ll powMod(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

void FWT(ll *a, int l, int r) {
    if (r - l == 1) return;
    int mid = (l + r) >> 1;
    FWT(a, l, mid);
    FWT(a, mid, r);
    int len = mid - l;
    for (int i = l; i < mid; ++ i) {
        ll x1 = a[i];
        ll x2 = a[i + len];
        a[i] = x1 + x2;
        a[i + len] = x1 - x2 + p;
        fix(a[i]);
        fix(a[i + len]);
    }
}

ll e[1 << 20], bb[21], b[1 << 20];

void domain() {
    int m;
    ll t;
    scanf("%d%lld%lld", &m, &t, &p);
    int n = (1 << m);
    p = p * n;
    for (int i = 0; i < n; ++ i) {
        scanf("%lld", &e[i]);
    }
    for (int i = 0; i < m + 1; ++ i) {
        scanf("%lld", &bb[i]);
    }
    for (int i = 0; i < n; ++ i) {
        b[i] = bb[__builtin_popcount(i)];
    }
    FWT(e, 0, n);
    FWT(b, 0, n);
    for (int i = 0; i < n; ++ i) {
        b[i] = powMod(b[i], t);
    }
    for (int i = 0; i < n; ++ i) {
        e[i] = mul(e[i], b[i]);
    }
    FWT(e, 0, n);
    for (int i = 0; i < n; ++ i) {
        printf("%lld\n", (e[i] >> m));
    }
}

int main() {

    //freopen("/Users/zyeric/Desktop/workspace/workspace/in.txt", "r", stdin);
    //freopen("/Users/zyeric/Desktop/workspace/workspace/out.txt", "w", stdout);

    srand((int)time(0));

    ios::sync_with_stdio(false);
    cout << fixed << setprecision(16);

    domain();

    return 0;
}