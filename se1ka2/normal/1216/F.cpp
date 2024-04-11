#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

const ll INF = 10000000000000000;

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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll dpd[200005];
    ll dpw[200005];
    fill(dpw, dpw + n, INF);
    SegmentTree<ll> seg1(n, [](ll a, ll b){return min(a, b);}, INF);
    for(ll i = 0; i < n; i++) seg1.set(i, INF);
    for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
            if(i <= k) dpw[i] = i + 1;
            else dpw[i] = min(dpd[i - (k + 1)], seg1.query(max(0ll, i - (k * 2 + 1)), i)) + i + 1;
        }
        if(i == 0) dpd[i] = 1;
        else dpd[i] = min(dpd[i - 1] + i + 1, seg1.query(max(0ll, i - k), i));
        seg1.update(i, dpw[i]);
    }
    cout << min(dpd[n - 1], dpw[n - 1]) << endl;
}