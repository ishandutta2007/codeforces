#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define next _next

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

struct tans {
    
    bool full;
    int ans, pref, suff;
    
    tans() {}
    
    tans(bool full, int ans, int pref, int suff) {
        this->full = full;
        this->ans = ans;
        this->pref = pref;
        this->suff = suff;
    }
    
};

struct tr {
    
    tans ans;
    int l, r;
    
};

struct tq {
    
    int l, r, w;
    
};

int maxv;
pii a[N];
tq q[N];
bool fl[N];
int l[N], r[N], mid[N], ans[N];
int first[N], next[N];
tr rmq[4 * N];

inline tans merge(const tans &a, const tans &b) {
    tans c;
    c.ans = max(max(a.ans, b.ans), a.suff + b.pref);
    c.pref = (a.full ? a.pref + b.pref : a.pref);
    c.suff = (b.full ? b.suff + a.suff : b.suff);
    c.full = (a.full & b.full);
    return c;
}

inline void update(int a) {
    a += maxv;
    rmq[a].ans.full = true;
    rmq[a].ans.ans = rmq[a].ans.pref = rmq[a].ans.suff = 1;
    while (a > 1) {
        a /= 2;
        rmq[a].ans = merge(rmq[a * 2].ans, rmq[a * 2 + 1].ans);
    }
}

inline tans get(int v, int l, int r) {
    if (rmq[v].l > r || rmq[v].r < l) {
        return tans(true, 0, 0, 0);
    }
    if (rmq[v].l >= l && rmq[v].r <= r) {
        return rmq[v].ans;
    }
    return merge(get(v * 2, l, r), get(v * 2 + 1, l, r));
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].fs);
        a[i].sc = i;
    }
    sort(a, a + n);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].w);
        --q[i].l;
        --q[i].r;
        l[i] = 0;
        r[i] = n - 1;
    }
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 0; i < maxv; ++i) {
        rmq[i + maxv].l = rmq[i + maxv].r = i;
    }
    for (int i = maxv - 1; i > 0; --i) {
        rmq[i].l = rmq[i * 2].l;
        rmq[i].r = rmq[i * 2 + 1].r;
    }
    for (;;) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            first[i] = -1;
        }
        for (int i = 0; i < m; ++i) {
            if (l[i] > r[i]) {
                continue;
            }
            mid[i] = (l[i] + r[i]) / 2;
            fl[i] = false;
            next[i] = first[mid[i]];
            first[mid[i]] = i;
            found = true;
        }
        if (!found) {
            break;
        }
        for (int i = 1; i < 2 * maxv; ++i) {
            rmq[i].ans.full = false;
            rmq[i].ans.ans = rmq[i].ans.pref = rmq[i].ans.suff = 0;
        }
        for (int i = n - 1; i >= 0; --i) {
            update(a[i].sc);
            for (int j = first[i]; j != -1; j = next[j]) {
                if (get(1, q[j].l, q[j].r).ans >= q[j].w) {
                    fl[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            if (l[i] <= r[i]) {
                if (fl[i]) {
                    ans[i] = a[mid[i]].fs;
                    l[i] = mid[i] + 1;
                } else {
                    r[i] = mid[i] - 1;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}