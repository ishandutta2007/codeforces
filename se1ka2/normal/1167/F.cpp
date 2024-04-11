#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1000000007;

P p[500004];

template<typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build() {
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
};

int main()
{
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        p[i] = P(a, i);
    }
    sort(p, p + n);
    SegmentTree<ll> l(n, [](ll a, ll b){return a + b;}, 0ll);
    SegmentTree<ll> r(n, [](ll a, ll b){return a + b;}, 0ll);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans = (ans + p[i].first *
               (l.query(0, p[i].second + 1) % MOD * (n - p[i].second) % MOD +
                r.query(p[i].second, n) % MOD * (p[i].second + 1) % MOD +
                (n - p[i].second) * (p[i].second + 1) % MOD) % MOD) % MOD;
        l.update(p[i].second, p[i].second + 1);
        r.update(p[i].second, n - p[i].second);
    }
    cout << ans << endl;
}