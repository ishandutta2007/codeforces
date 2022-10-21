#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
const int N = (int)2e5 + 50;
//const ld INF = 1/.0;

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
//        return a / b;
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
} lc;

int n, a[N];
ll psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }
    ll res = 0, sum = 0;
    for(int i = 1; i <= n; i++) sum += 1LL * i * a[i];
    res = sum;
    lc.clear();
    lc.add(n, -psum[n]);
    for(int i = n - 1; i >= 1; i--) {
        res = max(res, sum + lc.query(a[i]) + psum[i] - 1LL * i * a[i]);
        lc.add(i, -psum[i]);
    }
    lc.clear();
    lc.add(1, 0);
    for(int i = 2; i <= n; i++) {
        res = max(res, sum + lc.query(a[i]) + psum[i-1] - 1LL * i * a[i]);
        lc.add(i, -psum[i-1]);
    }
    cout << res << endl;
}