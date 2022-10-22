#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000007;

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
        int n, m, k;
        cin >> n >> m >> k;
        int a[4000];
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        if(k >= m - 1){
            for(int i = 0; i < m; i++) ans = max(ans, max(a[i], a[n - 1 - i]));
            cout << ans << endl;
            continue;
        }
        SegmentTree<int> seg(n + 1, [](int a, int b){return min(a, b);}, INF);
        for(int i = 0; i < m; i++){
            seg.update(i, max(a[i], a[n - m + i]));
        }
        for(int i = 0; i <= k; i++){
            ans = max(ans, seg.query(i, i + m - k));
        }
        cout << ans << endl;
    }
}