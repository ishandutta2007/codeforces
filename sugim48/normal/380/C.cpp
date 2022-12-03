#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)

template <class M>
struct segtree {
    using T = typename M::T;
    
    int N;
    vector<T> a;
    
    segtree(int N, const T& x = M::id) :
        segtree(vector<T>(N, x)) {}
    
    segtree(const vector<T>& b) :
        N(b.size()), a(N * 2)
    {
        copy(b.begin(), b.end(), a.begin() + N);
        for (int i = N - 1; i >= 1; i--)
            a[i] = M::op(a[i<<1], a[i<<1 | 1]);
    }
    
    void set(int i, const T& x) {
        a[i += N] = x;
        while (i >>= 1) a[i] = M::op(a[i<<1], a[i<<1 | 1]);
    }
    
    T get(int l, int r) {
        T xl = M::id, xr = M::id;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) xl = M::op(xl, a[l++]);
            if (r & 1) xr = M::op(a[--r], xr);
        }
        return M::op(xl, xr);
    }
};

struct RMQ {
    using T = long long;
    static constexpr T id = 0;
    static T op(const T& xl, const T& xr) {
        return max(xl, xr);
    };
};

struct Unko { int a, b; };

struct Monoid {
    using T = Unko;
    static constexpr T id = {0, 0};
    static T op(const T& xl, const T& xr) {
        int k = min(xl.b, xr.a);
        return {xl.a + xr.a - k, xl.b + xr.b - k};
    };
};

int main() {
    string s; cin >> s;
    int N = s.length();
    vector<Unko> a(N);
    rep(i, N) a[i] = {s[i] == ')', s[i] == '('};
    segtree<Monoid> st(a);
    int Q; cin >> Q;
    while (Q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        Unko x = st.get(l, r);
        printf("%d\n", (r - l) - (x.a + x.b));
    }
}