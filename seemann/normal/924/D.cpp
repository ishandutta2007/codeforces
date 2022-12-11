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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-11;
const int MAXN = 1e5;

struct dtree {
    ld x;
    int y;
    int sz;
    dtree * l, *r;
    dtree(ld x) : x(x), y(rand()), sz(1), l(nullptr), r(nullptr) {}
};

void upd(dtree * t) {
    if (t == nullptr)
        return;
    t->sz = 1;
    if (t->l != nullptr) {
        t->sz += t->l->sz;
    }
    if (t->r != nullptr) {
        t->sz += t->r->sz;
    }
}

int getsz(dtree * t) {
    return t == nullptr ? 0 : t->sz;
}

void split(dtree * t, ld x, dtree *& left, dtree *& right) {
    if (t == nullptr) {
        left = right = nullptr;
        return;
    }

    if (t->x <= x) {
        split(t->r, x, t->r, right);
        left = t;
    } else {
        split(t->l, x, left, t->l);
        right = t;
    }
    upd(t);
}

dtree* merge(dtree * l, dtree * r) {
    if (l == nullptr) {
        return r;
    }
    if (r == nullptr) {
        return l;
    }
    if (l->y < r->y) {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    } else {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
}

dtree * root = nullptr;

struct pt {
    ld x, y;
    int ox, oy;
    bool operator < (pt o) {
        if (abs(x - o.x) > EPS)
            return x < o.x;
        return y < o.y;
    }
};

void add(pt a) {
    dtree * node = new dtree(a.y);
    dtree * l, * r;
    split(root, a.y, l, r);
    root = merge(merge(l, node), r);
}

int count(pt a) {
    dtree * l, * r;
    split(root, a.y + EPS, l, r);
    int res = getsz(l);
    root = merge(l, r);
    return res;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int n, w;
    cin >> n >> w;
    vector<pt> p(n);
    forn(i, n) {
        int X, v;
        cin >> X >> v;
        p[i].x = ((ld)(v - w)) / X;
        p[i].y = -((ld)(v + w)) / X;
        p[i].ox = X;
        p[i].oy = v;
    }
    sort(p.begin(), p.end());
    ll ans = 0;
    for (auto a : p) {
//        cerr  << a.x << ' ' << a.y << ' ' << a.ox << ' ' << a.oy  << '\n';
        ans += count(a);
//        cerr  << ans << '\n';
        add(a);
    }
    cout << ans << '\n';
    return 0;
}