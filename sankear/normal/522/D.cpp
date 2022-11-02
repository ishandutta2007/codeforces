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
const int N = int(5e5) + 100;

struct td {
    
    pii val;
    int push_ans, ans, h, l, r;
    
};

int a[N], b[N], l[N], r[N], next[N], last[N];
vi add[N], del[N];
td d[N];

inline int get_rand() {
    return (rand() << 15) | rand();
}

inline void push(int v) {
    if (v == 0 || d[v].push_ans == inf) {
        return;
    }
    d[v].ans = min(d[v].ans, d[v].push_ans);
    if (d[v].l > 0) {
        d[d[v].l].push_ans = min(d[d[v].l].push_ans, d[v].push_ans);
    }
    if (d[v].r > 0) {
        d[d[v].r].push_ans = min(d[d[v].r].push_ans, d[v].push_ans);
    }
    d[v].push_ans = inf;
}

void split(int v, pii val, int& l, int& r) {
    push(v);
    if (v == 0) {
        l = r = 0;
        return;
    }
    if (d[v].val < val) {
        split(d[v].r, val, d[v].r, r);
        l = v;
    } else {
        split(d[v].l, val, l, d[v].l);
        r = v;
    }
}

int merge(int l, int r) {
    push(l);
    push(r);
    if (l == 0) {
        return r;
    }
    if (r == 0) {
        return l;
    }
    int res;
    if (d[l].h > d[r].h) {
        d[l].r = merge(d[l].r, r);
        res = l;
    } else {
        d[r].l = merge(l, d[r].l);
        res = r;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    int k = (int) (unique(b, b + n) - b);
    for (int i = 0; i < k; ++i) {
        last[i] = -1;
    }
    for (int i = n - 1; i >= 0; --i) {
        int pos = (int) (lower_bound(b, b + k, a[i]) - b);
        next[i] = last[pos];
        last[pos] = i;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        --l[i];
        --r[i];
        add[l[i]].pb(i);
        del[r[i]].pb(i);
    }
    int root = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(add[i]); ++j) {
            int v = add[i][j];
            d[v].h = get_rand();
            d[v].push_ans = d[v].ans = inf;
            d[v].l = d[v].r = 0;
            d[v].val = mp(r[v], v);
            int l, r;
            split(root, d[v].val, l, r);
            root = merge(l, merge(v, r));
        }
        if (next[i] != -1) {
            int l, r;
            split(root, mp(next[i], -1), l, r);
            if (r != 0) {
                d[r].push_ans = min(d[r].push_ans, next[i] - i);
            }
            root = merge(l, r);
        }
        for (int j = 0; j < sz(del[i]); ++j) {
            int v = del[i][j];
            int p1, p2, p3;
            split(root, mp(r[v], v), p1, p2);
            split(p2, mp(r[v], v + 1), p2, p3);
            root = merge(p1, p3);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int ans = d[i].ans;
        if (ans == inf) {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}