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

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 2e6 + 100;

struct dtree {
    int x, y;
    dtree *l, *r;
    int sz;
    dtree(int x) : x(x), y(rand()), l(0), r(0), sz(1) {}
};
void upd(dtree * t) {
    if (t == NULL)
        return;
    t->sz = 1;
    if (t->l) {
        t->sz += t->l->sz;
    }
    if (t->r) {
        t->sz += t->r->sz;
    }
}
void split(dtree * t, int x, dtree *&l, dtree *&r) {
    if (t == NULL) {
        l = r = NULL;
        return;
    }
    if (t->x <= x) {
        split(t->r, x, t->r, r);
        l = t;
    } else {
        split(t->l, x, l, t->l);
        r = t;
    }
    upd(t);
}
dtree * merge(dtree *l, dtree * r) {
    if (l == NULL)
        return r;
    if (r == NULL)
        return l;
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}
void add(dtree *& t, int x) {
    dtree *l, *r;
    split(t, x, l, r);
    dtree * v = new dtree(x);
    t = merge(merge(l, v), r);
}
int getsize(dtree * t) {
    return t == NULL ? 0 : t->sz;
}
int count(dtree *& t, int x) {
    dtree *l, *r;
    split(t, x, l, r);
    int res = getsize(l);
    t = merge(l,r);
    return res;
}
dtree * at[MAXN], *dt[MAXN];
map<int, int> tonum;
int a[MAXN], t[MAXN], x[MAXN];
int main() {
    srand(time(NULL));
#ifdef LOCAL
    freopen("e.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d%d", &a[i], &t[i], &x[i]);
        tonum[x[i]] = 0;
    }
    int M = 0;
    for (auto it = tonum.begin(); it != tonum.end(); ++it) {
        it->second = M++;
    }
    forn(i, n) {
        int nm = tonum[x[i]];
        if (a[i] == 1) {
            add(at[nm], t[i]);
        } else if (a[i] == 2) {
            add(dt[nm], t[i]);
        } else {
            printf("%d\n", count(at[nm], t[i]) - count(dt[nm], t[i]));
        }
    }

    
    
    return 0;
}