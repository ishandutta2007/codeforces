#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-4;
const double pi = 4 * atan(double(1));
const int N = int(2e5) + 100;

int a[N], b[N], f[N], fa[N], fb[N];

inline void build(int *a, int *fa, int n) {
    for (int i = 1; i <= n; ++i) {
        f[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        ++f[i];
        if ((i | (i + 1)) <= n) {
            f[(i | (i + 1))] += f[i];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int num = 0;
        for (int j = a[i]; j > 0; j = (j & (j + 1)) - 1) {
            num += f[j];
        }
        fa[n - i - 2] = num - 1;
        for (int j = a[i]; j <= n; j = (j | (j + 1))) {
            --f[j];
        }
    }
}

inline int find(int n, int num) {
    int res = -1, l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnum = 0;
        for (int i = mid; i > 0; i = (i & (i + 1)) - 1) {
            cnum += f[i];
        }
        if (cnum >= num) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    assert(res != -1);
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++a[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        ++b[i];
    }
    if (n == 1) {
        puts("0");
        return 0;
    }
    build(a, fa, n);
    build(b, fb, n);
    for (int i = 0; i < n - 1; ++i) {
        fa[i] += fb[i];
        if (fa[i] >= i + 2) {
            fa[i + 1] += fa[i] / (i + 2);
            fa[i] %= (i + 2);
        }
    }
    for (int i = 1; i <= n; ++i) {
        f[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        ++f[i];
        if ((i | (i + 1)) <= n) {
            f[(i | (i + 1))] += f[i];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        a[n - 2 - i] = find(n, fa[i] + 1);
        for (int j = a[n - 2 - i]; j <= n; j = (j | (j + 1))) {
            --f[j];
        }
    }
    a[n - 1] = find(n, 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i] - 1);
    }
    puts("");
    return 0;
}