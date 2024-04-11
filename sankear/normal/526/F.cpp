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
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
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

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(3e5) + 100;

struct tr {
    
    int min_val, cnt, add, l, r;
    
    tr() {}
    
    tr(int min_val, int cnt) : min_val(min_val), cnt(cnt) {}
    
};

int maxv;
int a[N];
pii st_min[N], st_max[N];
tr rmq[4 * N];

inline void merge(const tr& a, const tr& b, tr& c) {
    if (a.min_val == b.min_val) {
        c.min_val = a.min_val;
        c.cnt = a.cnt + b.cnt;
        return;
    }
    if (a.min_val < b.min_val) {
        c.min_val = a.min_val;
        c.cnt = a.cnt;
        return;
    }
    c.min_val = b.min_val;
    c.cnt = b.cnt;
}

inline void push(int v) {
    if (rmq[v].add == 0) {
        return;
    }
    rmq[v].min_val += rmq[v].add;
    if (v < maxv) {
        rmq[v * 2].add += rmq[v].add;
        rmq[v * 2 + 1].add += rmq[v].add;
    }
    rmq[v].add = 0;
}

inline void calc(int v) {
    merge(rmq[v * 2], rmq[v * 2 + 1], rmq[v]);
}

void set_val(int v, int pos, int val) {
    push(v);
    if (rmq[v].l > pos || rmq[v].r < pos) {
        return;
    }
    if (v >= maxv) {
        rmq[v].min_val = val;
        rmq[v].cnt = 1;
        return;
    }
    set_val(v * 2, pos, val);
    set_val(v * 2 + 1, pos, val);
    calc(v);
}

void update(int v, int l, int r, int add) {
    push(v);
    if (rmq[v].l > r || rmq[v].r < l) {
        return;
    }
    if (rmq[v].l >= l && rmq[v].r <= r) {
        rmq[v].add += add;
        push(v);
        return;
    }
    update(v * 2, l, r, add);
    update(v * 2 + 1, l, r, add);
    calc(v);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int r, c;
        scanf("%d %d", &r, &c);
        --r;
        --c;
        a[r] = c;
    }
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 0; i < maxv; ++i) {
        rmq[i + maxv].min_val = inf;
        rmq[i + maxv].cnt = 1;
        rmq[i + maxv].l = rmq[i + maxv].r = i;
    }
    for (int i = maxv - 1; i > 0; --i) {
        merge(rmq[i * 2], rmq[i * 2 + 1], rmq[i]);
        rmq[i].l = rmq[i * 2].l;
        rmq[i].r = rmq[i * 2 + 1].r;
    }
    int sz_min = 1;
    st_min[0] = mp(-inf, -1);
    int sz_max = 1;
    st_max[0] = mp(inf, -1);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        set_val(1, i, i);
        int pos = i;
        while (sz_min > 0 && st_min[sz_min - 1].fs >= a[i]) {
            int npos = st_min[--sz_min].sc;
            update(1, npos, pos - 1, st_min[sz_min].fs - a[i]);
            pos = npos;
        }
        st_min[sz_min++] = mp(a[i], pos);
        pos = i;
        while (sz_max > 0 && st_max[sz_max - 1].fs <= a[i]) {
            int npos = st_max[--sz_max].sc;
            update(1, npos, pos - 1, a[i] - st_max[sz_max].fs);
            pos = npos;
        }
        st_max[sz_max++] = mp(a[i], pos);
        if (rmq[1].min_val == i) {
            ans += rmq[1].cnt;
        }
    }
    cout << ans << endl;
    return 0;
}