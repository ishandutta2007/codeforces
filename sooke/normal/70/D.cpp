#include <cstdio>
#include <algorithm>
#include <set>

inline int read() {
    char c = getchar(); int x = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return f ? -x : x;
}

namespace Geometry {
    typedef long long T;
    typedef std::pair<T, T> P;
    
    P operator >>(const P &u, const P &v) { return {v.first - u.first, v.second - u.second}; }
    T operator *(const P &u, const P &v) { return u.first * v.first + u.second * v.second; }
    T operator ^(const P &u, const P &v) { return u.first * v.second - u.second * v.first; }
    inline T getArea(const P &u, const P &v, const P &w) { return (u >> v) ^ (u >> w); }
}

using Geometry::P;
using Geometry::getArea;

std::set<P> su, sd;
std::set<P> ::iterator it, l, r, mid;

bool check(std::set<P> &s, P u, int sgn) {
    l = s.upper_bound(u); r = s.lower_bound(u);
    if (l == s.begin() || r == s.end()) { return false; } l--;
    return sgn * getArea(*l, u, *r) >= 0;
}
void insert(std::set<P> &s, P u, int sgn) {
    if (check(s, u, sgn)) { return; }
    it = s.insert(u).first;
    while (true) {
        if (it == s.begin()) { break; } mid = it; mid--;
        if (mid == s.begin()) { break; } l = mid; l--;
        if (getArea(*l, *mid, u) * sgn <= 0) { break; } s.erase(mid);
    }
    while (true) {
        if (it == --s.end()) { break; } mid = it; mid++;
        if (mid == --s.end()) { break; } r = mid; r++;
        if (getArea(u, *mid, *r) * sgn <= 0) { break; } s.erase(mid);
    }
}

int main() {
    for (int q = read(); q; q--) {
        long long opt = read(), x = read(), y = read();
        if (opt == 1) { insert(su, {x, y}, 1); insert(sd, {x, y}, -1); }
        else { printf("%s\n", check(su, {x, y}, 1) && check(sd, {x, y}, -1) ? "YES" : "NO"); }
    }
    return 0;
} //