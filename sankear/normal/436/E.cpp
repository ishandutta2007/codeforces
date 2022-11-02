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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define hash _hash
#define y0 yy0
#define y1 yy1
#define link _link

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll inf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(3e5) + 100;

struct td {
    
    int val, num, h, sz, p, l, r;
    ll sum;
    
};

int sz = 0;
pair<pii, int> a[N];
int ver[N], anss[N];
td d[2 * N];

inline void calc(int v) {
    d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
    d[v].sum = d[d[v].l].sum + d[d[v].r].sum + d[v].val;
    d[v].p = 0;
    if (d[v].l > 0) {
        d[d[v].l].p = v;
    }
    if (d[v].r > 0) {
        d[d[v].r].p = v;
    }
}

void split(int v, int val, int &l, int &r) {
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
    calc(v);
}

void splitSize(int v, int sz, int &l, int &r) {
    if (v == 0) {
        l = r = 0;
        return;
    }
    if (d[d[v].l].sz + 1 <= sz) {
        splitSize(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
        l = v;
    } else {
        splitSize(d[v].l, sz, l, d[v].l);
        r = v;
    }
    calc(v);
}

int merge(int l, int r) {
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

inline int get(int v, int num) {
    if (d[d[v].l].sz + 1 == num) {
        return d[v].val;
    }
    if (d[d[v].l].sz + 1 < num) {
        return get(d[v].r, num - d[d[v].l].sz - 1);
    }
    return get(d[v].l, num);
}

inline ll calcSum(int v, int sz) {
    if (v == 0) {
        return 0;
    }
    if (d[d[v].l].sz + 1 <= sz) {
        return d[d[v].l].sum + d[v].val + calcSum(d[v].r, sz - d[d[v].l].sz - 1);
    } else {
        return calcSum(d[v].l, sz);
    }
}

inline int add(int root, int val, int num) {
    d[++sz].val = val;
    d[sz].num = num;
    d[sz].sum = val;
    d[sz].sz = 1;
    d[sz].h = (rand() << 16) | rand();
    d[sz].p = d[sz].l = d[sz].r = 0;
    ver[num] = sz;
    int l, r;
    split(root, val, l, r);
    return merge(l, merge(sz, r));
}

inline int calcNum(int v) {
    int res = d[d[v].l].sz + 1;
    while (d[v].p > 0) {
        int pv = d[v].p;
        if (d[pv].r == v) {
            res += d[d[pv].l].sz + 1;
        }
        v = pv;
    }
    return res;
}

inline int del(int root, int ver) {
    int num = calcNum(ver);
    int p1, p2, p3;
    splitSize(root, num - 1, p1, p2);
    splitSize(p2, 1, p2, p3);
    return merge(p1, p3);
}

void dfs(int v, int col) {
    if (v == 0) {
        return;
    }
    dfs(d[v].l, col);
    dfs(d[v].r, col);
    anss[d[v].num] = col;
}

int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].fs.sc, &a[i].fs.fs);
        a[i].sc = i;
    }
    sort(a, a + n);
    int rootLeft = 0, rootRight = 0;
    for (int i = 0; i < n; ++i) {
        rootRight = add(rootRight, a[i].fs.sc, a[i].sc);
    }
    ll ans = inf, sum = 0;
    int pos = -1;
    for (int p = 0; p <= n; ++p) {
        if (p > 0) {
            sum += a[p - 1].fs.fs;
            rootRight = del(rootRight, ver[a[p - 1].sc]);
            rootLeft = add(rootLeft, -a[p - 1].fs.fs + a[p - 1].fs.sc, a[p - 1].sc);
        }
        
        int needRight = max(w - 2 * p, 0), tmpRight;
        if (needRight > d[rootRight].sz) {
            continue;
        }
        splitSize(rootRight, needRight, tmpRight, rootRight);
        ll res = sum + d[tmpRight].sum;

        int canLeft = min(max(2 * p - w, 0), d[rootLeft].sz), tmpLeft;
        splitSize(rootLeft, canLeft, tmpLeft, rootLeft);
        res += d[tmpLeft].sum;
        
        int can = 0, l = 1, r = min(d[rootLeft].sz, d[rootRight].sz);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (get(rootLeft, mid) + get(rootRight, mid) < 0) {
                can = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        res += calcSum(rootLeft, can) + calcSum(rootRight, can);
        
        if (res < ans) {
            ans = res;
            pos = p;
        }
        
        rootRight = merge(tmpRight, rootRight);
        rootLeft = merge(tmpLeft, rootLeft);
    }
    
    sz = rootLeft = rootRight = 0;
    
    for (int i = 0; i < n; ++i) {
        rootRight = add(rootRight, a[i].fs.sc, a[i].sc);
    }
    
    sum = 0;
    
    for (int p = 0; p <= pos; ++p) {
        if (p > 0) {
            sum += a[p - 1].fs.fs;
            anss[a[p - 1].sc] = 2;
            rootRight = del(rootRight, ver[a[p - 1].sc]);
            rootLeft = add(rootLeft, -a[p - 1].fs.fs + a[p - 1].fs.sc, a[p - 1].sc);
        }
        if (p == pos) {
            int needRight = max(w - 2 * p, 0), tmpRight;
            splitSize(rootRight, needRight, tmpRight, rootRight);

            int canLeft = min(max(2 * p - w, 0), d[rootLeft].sz), tmpLeft;
            splitSize(rootLeft, canLeft, tmpLeft, rootLeft);
            
            dfs(tmpRight, 1);
            dfs(tmpLeft, 1);
            
            int can = 0, l = 1, r = min(d[rootLeft].sz, d[rootRight].sz);
            while (l <= r) {
                int mid = (l + r) / 2;
                if (get(rootLeft, mid) + get(rootRight, mid) < 0) {
                    can = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            splitSize(rootLeft, can, rootLeft, tmpRight);
            splitSize(rootRight, can, rootRight, tmpRight);
            
            dfs(rootLeft, 1);
            dfs(rootRight, 1);
            
        }
    }
    
    printf(LLD"\n", ans);
    for (int i = 0; i < n; ++i) {
        printf("%d", anss[i]);
    }
    puts("");
    
    return 0;
}