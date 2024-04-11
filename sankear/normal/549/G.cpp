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
#include <stack>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || _WIN64 || __WIN32__ || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define end _end

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef complex<double> tc;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(2e5) + 100;

struct td {
    
    int val, add, h, sz, l, r;
    
};

int a[N];
td d[N];

inline void push(int v) {
    if (v == 0 || d[v].add == 0) {
        return;
    }
    d[v].val += d[v].add;
    if (d[v].l > 0) {
        d[d[v].l].add += d[v].add;
    }
    if (d[v].r > 0) {
        d[d[v].r].add += d[v].add;
    }
    d[v].add = 0;
}

inline void calc(int v) {
    d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
}

void split(int v, int sz, int &l, int &r) {
    push(v);
    if (v == 0) {
        l = r = 0;
        return;
    }
    if (d[d[v].l].sz + 1 <= sz) {
        split(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
        l = v;
    } else {
        split(d[v].l, sz, l, d[v].l);
        r = v;
    }
    calc(v);
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
    calc(res);
    return res;
}

inline int get_rand() {
    return (rand() << 15) | rand();
}

int find_sz(int v, int val) {
    push(v);
    if (v == 0) {
        return 0;
    }
    if (val - d[d[v].l].sz <= d[v].val) {
        return find_sz(d[v].l, val);
    }
    return d[d[v].l].sz + 1 + find_sz(d[v].r, val - d[d[v].l].sz - 1);
}

inline void fail() {
    puts(":(");
    exit(0);
}

inline void check(int l, int r, int val) {
    if (l > 0) {
        push(l);
        while (d[l].r > 0) {
            l = d[l].r;
            push(l);
        }
        if (d[l].val > val) {
            fail();
        }
    }
    if (r > 0) {
        push(r);
        while (d[r].l > 0) {
            r = d[r].l;
            push(r);
        }
        if (val > d[r].val) {
            fail();
        }
    }
}

void write(int v) {
    push(v);
    if (v == 0) {
        return;
    }
    write(d[v].l);
    printf("%d ", d[v].val);
    write(d[v].r);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int root = 0;
    d[0].val = -inf;
    int ptr = 1;
    for (int i = n - 1; i >= 0; --i) {
        int sz = find_sz(root, a[i]), l, r;
        split(root, sz, l, r);
        if (l > 0) {
            ++d[l].add;
        }
        check(l, r, a[i] - sz);
        
        d[ptr].val = a[i] - sz;
        d[ptr].sz = 1;
        d[ptr].h = get_rand();
        root = merge(l, merge(ptr, r));
        ++ptr;
    }
    write(root);
    puts("");
    return 0;
}