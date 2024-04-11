#include <functional>
#include <iostream>
#include <vector>
using namespace std;

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
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int p[200005];
        int b[200005];
        SegmentTree<int> seg(n, [](int a, int b){return max(a, b);}, 0);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            seg.set(i, p[i]);
            b[p[i]] = i;
        }
        seg.build();
        int l = n, r = -1;
        for(int i = 1; i <= n; i++){
            l = min(l, b[i]);
            r = max(r, b[i]);
            if(i == seg.query(l, r + 1)) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}