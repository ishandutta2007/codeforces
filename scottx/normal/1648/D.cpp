#include <bits/stdc++.h>
 
using i64 = long long;
 
template<class Info,
    class Merge = std::plus<Info>>
struct SegmentTree {
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
    SegmentTree(std::vector<Info> init) : SegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = merge(info[2 * p], info[2 * p + 1]);
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};
 
struct Max {
    i64 x;
    Max(i64 x = -1E18) : x(x) {};
};
 
Max operator+(const Max &a, const Max &b) {
    return std::max(a.x, b.x);
}
 
struct Pair {
    i64 ans;
    i64 a;
    i64 b;
    Pair() : ans(-1E18), a(-1E18), b(-1E18) {}
    Pair(i64 a, i64 b) : ans(a + b), a(a), b(b) {}
};
 
Pair operator+(const Pair &a, const Pair &b) {
    Pair c;
    c.ans = std::max({a.ans, b.ans, a.a + b.b});
    c.a = std::max(a.a, b.a);
    c.b = std::max(a.b, b.b);
    return c;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector c(3, std::vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> c[i][j];
        }
    }
    
    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] += c[0][i];
        if (i > 0) {
            a[i] += a[i - 1];
            a[i] -= c[1][i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        b[i] += c[2][i];
        if (i < n - 1) {
            b[i] += b[i + 1];
            b[i] -= c[1][i + 1];
        }
    }
    
    i64 ans = -1E18;
    
    SegmentTree<Max> seg(n);
    for (int i = 0; i < n; i++) {
        seg.modify(i, a[i]);
    }
    
    std::vector<std::array<int, 3>> ranges(q);
    for (int i = 0; i < q; i++) {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--;
        ranges[i] = {l, r, k};
    }
    std::sort(ranges.begin(), ranges.end());
    
    for (auto [l, r, k] : ranges) {
        auto v = seg.rangeQuery(l, r).x;
        if (r < n) {
            a[r] = std::max(a[r], v - k);
            seg.modify(r, a[r]);
        }
    }
    
    SegmentTree<Pair> seg2(n);
    for (int i = 0; i < n; i++) {
        seg2.modify(i, Pair(a[i], b[i]));
    }
    
    for (auto [l, r, k] : ranges) {
        ans = std::max(ans, seg2.rangeQuery(l, r).ans - k);
    }
    
    ans += std::accumulate(c[1].begin(), c[1].end(), 0LL);
    
    std::cout << ans << "\n";
    
    return 0;
}