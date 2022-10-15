#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

const int maxN = 100005;

int n, m, seed, lim, a[maxN];

inline int power(int x, int y, int p) { int res = 1; for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } } return res; }
inline int bigRand() { int tmp = seed; seed = (seed * 7ll + 13) % 1000000007; return tmp; }
inline int randInt(int l, int r) { return l + bigRand() % (r - l + 1); }

struct Element { int l, r; mutable long long x; };

bool operator <(const Element &u, const Element &v) { return u.l == v.l ? u.r < v.r : u.l < v.l; }

struct OldDriverTree {
    std::set<Element> f;

    inline void init() { f.insert((Element) {0, 0, 0}); f.insert((Element) {n + 1, n + 1, 0}); }
    inline std::set<Element>::iterator split(int l) {
        std::set<Element>::iterator it = f.lower_bound((Element) {l, maxN, 0}); it--;
        if (it->l == l) { return it; } Element s, t; s = t = *it; f.erase(it);
        s.r = l - 1; t.l = l; f.insert(s); return f.insert(t).first;
    }
    void modify(int l, int r, int x) {
        std::set<Element>::iterator ir = split(r + 1), il = split(l);
        for (; il != ir; il++) { il->x += x; }
    }
    void assign(int l, int r, int x) {
        std::set<Element>::iterator ir = split(r + 1), il = split(l);
        f.erase(il, ir); f.insert((Element) {l, r, x});
    }
    long long query(int l, int r, int x) {
        std::set<Element>::iterator ir = split(r + 1), il = split(l); std::map<long long, int> g;
        for (; il != ir; il++) { g[il->x] += il->r - il->l + 1; }
        for (std::map<long long, int>::iterator it = g.begin(); it != g.end(); it++) {
            if (x <= it->second) { return it->first; } x -= it->second;
        }
    }
    int querySum(int l, int r, int x, int p) {
        std::set<Element>::iterator ir = split(r + 1), il = split(l); int res = 0;
        for (; il != ir; il++) { res = (res + 1ll * power(il->x % p, x, p) * (il->r - il->l + 1)) % p; }
        return res;
    }
} tr;


int main() {
    scanf("%d%d%d%d", &n, &m, &seed, &lim); tr.init();
    for (int i = 1; i <= n; i++) { a[i] = randInt(1, lim); tr.f.insert((Element) {i, i, a[i]}); }
    for (int opt, l, r, x; m; m--) {
        opt = randInt(1, 4); l = randInt(1, n); r = randInt(1, n);
        if (l > r) { std::swap(l, r); }
        x = randInt(1, opt == 3 ? r - l + 1 : lim);
        if (opt == 1) { tr.modify(l, r, x); }
        else if (opt == 2) { tr.assign(l, r, x); }
        else if (opt == 3) { printf("%I64d\n", tr.query(l, r, x)); }
        else if (opt == 4) { printf("%d\n", tr.querySum(l, r, x, randInt(1, lim))); }
    }
    return 0;
}