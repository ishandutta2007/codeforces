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
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const ll inf = ll(1e17);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

struct ans {
    
    int l, r;
    ll max_left, max_right, ans;
    
};

int maxv;
ll sum[N];
int h[N];
ans rmq[4 * N];

inline ll get_sum(int l, int r) {
    return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

inline ans merge(ans a, ans b) {
    if (a.l == -1) {
        return b;
    }
    if (b.l == -1) {
        return a;
    }
    ans c;
    c.l = a.l;
    c.r = b.r;
    c.max_left = max(a.max_left, b.max_left + get_sum(a.l, a.r));
    c.max_right = max(b.max_right, a.max_right + get_sum(b.l - 1, b.r - 1));
    c.ans = max(a.ans, b.ans);
    c.ans = max(c.ans, a.max_right + b.max_left + get_sum(a.r, a.r));
    return c;
}

ans get(int v, int gl, int gr, int l, int r) {
    if (gl > r || gr < l || l > r) {
        ans res;
        res.l = -1;
        return res;
    }
    if (gl >= l && gr <= r) {
        return rmq[v];
    }
    int mid = (gl + gr) / 2;
    return merge(get(v * 2, gl, mid, l, r), get(v * 2 + 1, mid + 1, gr, l, r));
}

inline ans get(int l, int r) {
    return get(1, 0, maxv - 1, l, r);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        sum[i] = (i > 0 ? sum[i - 1] : 0) + cur;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
    }
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 0; i < n; ++i) {
        rmq[i + maxv].l = rmq[i + maxv].r = i;
        rmq[i + maxv].max_left = rmq[i + maxv].max_right = 2 * h[i];
        rmq[i + maxv].ans = -inf;
    }
    for (int i = n; i < maxv; ++i) {
        rmq[i + maxv].l = -1;
    }
    for (int i = maxv - 1; i > 0; --i) {
        rmq[i] = merge(rmq[i * 2], rmq[i * 2 + 1]);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        ans res;
        if (a <= b) {
            res = merge(get(b + 1, n - 1), get(0, a - 1));
        } else {
            res = get(b + 1, a - 1);
        }
        printf(LLD "\n", res.ans);
    }
    return 0;
}