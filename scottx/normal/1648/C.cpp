#include <bits/stdc++.h>

constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

constexpr int N = 2E5;

template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> s(n), t(m);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        s[i]--;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> t[i];
        t[i]--;
    }
    
    std::vector<int> cnt(N);
    
    Fenwick<Z> fen(N);
    
    std::vector<Z> fac(n + 1), invfac(n + 1), inv(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
    invfac[n] = fac[n].inv();
    for (int i = n; i; i--) {
        invfac[i - 1] = invfac[i] * i;
        inv[i] = invfac[i] * fac[i - 1];
    }
    
    for (auto x : s) {
        cnt[x]++;
        fen.add(x, 1);
    }
    Z cur = 1;
    for (int i = 0; i < N; i++) {
        cur *= invfac[cnt[i]];
    }
    
    Z ans = 0;
    for (int i = 0; i < std::min(n, m); i++) {
        ans += cur * fen.sum(t[i]) * fac[n - i - 1];
        if (cnt[t[i]] == 0) {
            break;
        }
        cur *= cnt[t[i]];
        cnt[t[i]]--;
        fen.add(t[i], -1);
    }
    
    if (n < m && cnt == std::vector(N, 0)) {
        ans += 1;
    }
    
    std::cout << ans.val() << "\n";
    
    return 0;
}