#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

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
    int n;
    cin >> n;
    vector<P> vx[10002], vy[10002];
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 5000; y1 += 5000; x2 += 5000; y2 += 5000;
        if(x2 < x1) swap(x1, x2);
        if(y2 < y1) swap(y1, y2);
        if(x1 == x2) vx[x1].push_back(P(y1, y2));
        else vy[y1].push_back(P(x1, x2));
    }
    ll ans = 0;
    for(int y = 0; y <= 10000; y++) for(P px : vy[y]){
        SegmentTree<ll> seg(10001, [](ll a, ll b){return a + b;}, 0ll);
        vector<int> d[10002];
        for(int x = px.first; x <= px.second; x++) for(P py : vx[x]){
            if(py.first <= y && py.second > y){
                seg.update(x, 1);
                d[py.second].push_back(x);
            }
        }
        for(int y2 = y + 1; y2 <= 10000; y2++){
            for(P px2 : vy[y2]){
                ll s = seg.query(px2.first, px2.second + 1);
                ans += s * (s - 1) / 2;
            }
            for(int x : d[y2]) seg.update(x, 0);
        }
    }
    cout << ans << endl;
}