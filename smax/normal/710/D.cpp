#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1, d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

bool solve(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = gcd(a, b, x0, y0);
    if (c % g)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    return true;
}

inline long long normalize(long long x, long long mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

long long a[2], m[2];

pair<long long, long long> crt() {
    long long ret = a[0], lcm = m[0], x, y, d;
    if (!solve(lcm, m[1], a[1] - ret, x, y, d))
        return {-1, -1};    // no solution
    ret = normalize(ret + x % (m[1] / d) * lcm, lcm / d * m[1]);
    lcm = lcm / d * m[1];
    return {ret, lcm};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a1, b1, a2, b2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;

    a[0] = normalize(b1, a1);
    m[0] = a1;
    a[1] = normalize(b2, a2);
    m[1] = a2;
    auto p = crt();
    if (p.second == -1) {
        cout << "0\n";
        return 0;
    }

    l = max({l, b1, b2});
    r -= p.first;
    l -= p.first;
    if (l > r) {
        cout << "0\n";
        return 0;
    }
    if (l <= 0) {
        long long add = p.second * (abs(l / p.second) + 1);
        l += add;
        r += add;
    }
    assert(l > 0 && r > 0);
    cout << r / p.second - (l - 1) / p.second << "\n";

    return 0;
}