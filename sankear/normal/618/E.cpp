#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash
#define link hulink
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(3e5) + 100;
const int ALPHA = 360;

struct base {
    
    double a, b;
    
    base() : a(0), b(0) {}
    
    base(double a) : a(a), b(0) {}
    
    base(double a, double b) : a(a), b(b) {}
    
};

base operator + (const base& a, const base& b) {
    return base(a.a + b.a, a.b + b.b);
}

base operator * (const base& a, const base& b) {
    return base(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
}

base e[ALPHA];

struct tr {
    
    int add;
    base sum, sum_l, sum_e;
    
};

int maxv;
int len[N], alpha[N];
tr rmq[4 * N];

inline void calc(int v) {
    rmq[v].sum = rmq[v * 2].sum + rmq[v * 2 + 1].sum;
    rmq[v].sum_l = rmq[v * 2].sum_l + rmq[v * 2 + 1].sum_l;
    rmq[v].sum_e = rmq[v * 2].sum_e + rmq[v * 2 + 1].sum_e;
}

inline void add(int& a, int b) {
    if ((a += b) >= ALPHA) {
        a -= ALPHA;
    }
}

inline void push(int v) {
    if (rmq[v].add == 0) {
        return;
    }
    rmq[v].sum = rmq[v].sum * e[rmq[v].add];
    rmq[v].sum_e = rmq[v].sum_e * e[rmq[v].add];
    if (v < maxv) {
        add(rmq[v * 2].add, rmq[v].add);
        add(rmq[v * 2 + 1].add, rmq[v].add);
    }
    rmq[v].add = 0;
}

void update_one(int v, int gl, int gr, int pos, int add) {
    push(v);
    if (gl > pos || gr < pos) {
        return;
    }
    if (v >= maxv) {
        rmq[v].sum_l = rmq[v].sum_l + add;
        rmq[v].sum = rmq[v].sum + rmq[v].sum_e * add;
        return;
    }
    int mid = (gl + gr) / 2;
    update_one(v * 2, gl, mid, pos, add);
    update_one(v * 2 + 1, mid + 1, gr, pos, add);
    calc(v);
}

void update(int v, int gl, int gr, int l, int r, int add) {
    push(v);
    if (gl > r || gr < l) {
        return;
    }
    if (gl >= l && gr <= r) {
        ::add(rmq[v].add, add);
        push(v);
        return;
    }
    int mid = (gl + gr) / 2;
    update(v * 2, gl, mid, l, r, add);
    update(v * 2 + 1, mid + 1, gr, l, r, add);
    calc(v);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < ALPHA; ++i) {
        e[i] = base(cos(0 - i * 2 * pi / ALPHA), sin(0 - i * 2 * pi / ALPHA));
    }
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 0; i < n; ++i) {
        rmq[i + maxv].sum = rmq[i + maxv].sum_l = rmq[i + maxv].sum_e = base(1, 0);
    }
    for (int i = maxv - 1; i > 0; --i) {
        calc(i);
    }
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        --y;
        if (x == 1) {
            update_one(1, 0, maxv - 1, y, z);
        } else {
            assert(x == 2);
            update(1, 0, maxv - 1, y, n - 1, z);
        }
        printf("%.18lf %.18lf\n", rmq[1].sum.a, rmq[1].sum.b);
    }
    return 0;
}