#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 100000000;

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
    int q, x;
    cin >> q >> x;
    SegmentTree<P> seg(x, [](P a, P b){return min(a, b);}, P(INF, INF));
    for(int i = 0; i < x; i++) seg.set(i, P(0, i));
    seg.build();
    for(int c = 0; c < q; c++){
        int y;
        cin >> y;
        y %= x;
        seg.update(y, P(seg[y].first + 1, y));
        P p = seg.query(0, x);
        cout << p.first * x + p.second << endl;
    }
}