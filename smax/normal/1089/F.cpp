#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++) 
#define f0r(i, a) f1r(i, 0, a)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;


namespace FactorBasic {

template <class T> std::vector<std::pair<T, int>> factor(T x) {
    std::vector<std::pair<T, int>> pri;
    for (T i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t++;
            pri.push_back({i, t});
        }
    }
    if (x > 1) pri.push_back({x, 1});
    return pri;
}

template <class T> T phi(T x) {
    for (auto& a : factor(x)) x -= x / a.first;
    return x;
}

template <class T> void tour(std::vector<std::pair<T, int>>& v, std::vector<T>& res, int ind, T cur) {
    if (ind == int(v.size())) res.push_back(cur);
    else {
        T mul = 1;
        for (int i = 0; i < v[ind].second + 1; i++) {
            tour(v, res, ind + 1, cur * mul);
            mul *= v[ind].first;
        }
    }
}

template <class T> std::vector<T> get_divisor(T x) {
    auto v = factor(x);
    std::vector<T> res; 
    tour(v, res, 0, (T) 1);
    sort(res.begin(), res.end());
    return res;
}

}

namespace BasicNumberTheory { 

// find solution to a * x + b * y = gcd(a, b)
// |a * x|, |b * y) <= lcm(a, b)
std::pair<long long, long long> euclid(long long a, long long b) {
    if (!b) 
        return {1, 0};
    std::pair<long long, long long> p = euclid(b, a % b);
    return {p.second, p.first - a / b * p.second};
}
long long mod_inverse(long long a, long long b) {
    auto p = euclid(a, b);
    assert(p.first * a + p.second * b == 1); // gcd is 1
    return p.first + (p.first < 0) * b;
}
std::pair<long long, long long> CRT(std::pair<long long, long long> a, 
    std::pair<long long, long long> b) {
    if (a.second < b.second)
        std::swap(a, b);
    long long x, y;
    std::tie(x, y) = euclid(a.second, b.second);
    long long g = a.second * x + b.second * y;
    long long l = a.second / g * b.second;
    if ((b.first - a.first) % g)
        return {-1, -1}; // no solution
    x = (b.first - a.first) % b.second * x % b.second / g * a.second + a.first;
    return {x + (x < 0) * l, l};
}
long long cdiv(long long a, long long b) { // a / b rounded up
    return a / b + ((a ^ b) > 0 && a % b);
}
long long fdiv(long long a, long long b) { // a / b rounded down
    return a / b - ((a ^ b) < 0 && a % b);
}
// minimum x such that there is a y such that l <= a * x + b * y <= r
long long between(long long a, long long b, long long l, long long r) {
    a %= b;
    if (a == 0)
        return l == 0 ? 0 : -1;
    long long k = cdiv(l, a);
    if (a * k <= r)
        return k;
    long long x = between(b, a, a - r % a, a - l % a);
    return x == -1 ? x : cdiv(b * x + l, a);
}

} // BasicNumberTheory

int main() {
    using namespace FactorBasic;
    using namespace BasicNumberTheory;
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    auto f = factor(n);
    if (sz(f) == 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    ll p = f[0].f;
    ll q = f[1].f;
    auto res = euclid(p, q);
    ll x = res.f;
    ll y = res.s;
    x *= (n-1);
    y *= (n-1);
    // p*x + q*y = 1
    if (y<0) {
        swap(x, y);
        swap(p, q);
    }
    if (x<0) {
        ll go = (x%q+q)%q;
        ll t = (go - x)/q;
        x += t*q;
        y -= t*p;
    }
    cout << 2 << '\n';
    cout << x << " " << n/p << '\n';
    cout << y << " " << n/q << '\n';

    return 0;
}