#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using D = double;
const D PI = acos(D(-1)), EPS = 1e-10;

int sgn(D a) { return (a < -EPS) ? -1 : (a > EPS); }
int sgn(D a, D b) { return sgn(a - b); }
struct P {
    D x, y;
    P(D _x = D(), D _y = D()) : x(_x), y(_y) {}
    P operator+(const P& r) const { return {x + r.x, y + r.y}; }
    P operator-(const P& r) const { return {x - r.x, y - r.y}; }
    P operator*(const P& r) const {
        return {x * r.x - y * r.y, x * r.y + y * r.x};
    }

    P operator*(const D& r) const { return {x * r, y * r}; }
    P operator/(const D& r) const { return {x / r, y / r}; }

    P& operator+=(const P& r) { return *this = *this + r; }
    P& operator-=(const P& r) { return *this = *this - r; }
    P& operator*=(const P& r) { return *this = *this * r; }
    P& operator*=(const D& r) { return *this = *this * r; }
    P& operator/=(const D& r) { return *this = *this / r; }

    P operator-() const { return {-x, -y}; }

    bool operator<(const P& r) const {
        return 2 * sgn(x, r.x) + sgn(y, r.y) < 0;
    }
    bool operator==(const P& r) const { return sgn((*this - r).rabs()) == 0; }
    bool operator!=(const P& r) const { return !(*this == r); }

    D norm() const { return x * x + y * y; }
    D abs() const { return sqrt(norm()); }
    D rabs() const { return max(std::abs(x), std::abs(y)); }  // robust abs
    D arg() const { return atan2(y, x); }

    pair<D, D> to_pair() const { return {x, y}; }
    static P polar(D le, D th) { return {le * cos(th), le * sin(th)}; }
};
ostream& operator<<(ostream& os, const P& p) {
    return os << "P(" << p.x << ", " << p.y << ")";
}

struct L {
    P s, t;
    L(P _s = P(), P _t = P()) : s(_s), t(_t) {}
    P vec() const { return t - s; }
    D abs() const { return vec().abs(); }
    D arg() const { return vec().arg(); }
};
ostream& operator<<(ostream& os, const L& l) {
    return os << "L(" << l.s << ", " << l.t << ")";
}

D crs(P a, P b) { return a.x * b.y - a.y * b.x; }
D dot(P a, P b) { return a.x * b.x + a.y * b.y; }
// cross(a, b) is too small?
int sgncrs(P a, P b) {
    D cr = crs(a, b);
    if (abs(cr) <= (a.rabs() + b.rabs()) * EPS) return 0;
    return (cr < 0) ? -1 : 1;
}

// -2, -1, 0, 1, 2 : front, clock, on, cclock, back
int ccw(P b, P c) {
    int s = sgncrs(b, c);
    if (s) return s;
    if (!sgn(c.rabs()) || !sgn((c - b).rabs())) return 0;
    if (dot(b, c) < 0) return 2;
    if (dot(-b, c - b) < 0) return -2;
    return 0;
}
int ccw(P a, P b, P c) { return ccw(b - a, c - a); }
int ccw(L l, P p) { return ccw(l.s, l.t, p); }


/**
 * ()
 */

P project(const L& l, const P& p) {
    P v = l.vec();
    return l.s + v * dot(v, p - l.s) / v.norm();
}

bool insSL(const L& s, const L& l) {
    int a = ccw(l, s.s), b = ccw(l, s.t);
    return (a % 2 == 0 || b % 2 == 0 || a != b);
}

bool insSS(const L& s, const L& t) {
    int a = ccw(s, t.s), b = ccw(s, t.t);
    int c = ccw(t, s.s), d = ccw(t, s.t);
    if (a * b <= 0 && c * d <= 0) return true;
    return false;
}

D distLP(const L& l, const P& p) {
    return abs(crs(l.vec(), p - l.s)) / l.abs();
}

D distSP(const L& s, const P& p) {
    P q = project(s, p);
    if (ccw(s, q) == 0)
        return (p - q).abs();
    else
        return min((s.s - p).abs(), (s.t - p).abs());
}

D distSS(const L& s, const L& t) {
    if (insSS(s, t)) return 0;
    return min(
        {distSP(s, t.s), distSP(s, t.t), distSP(t, s.s), distSP(t, s.t)});
}

int crossLL(const L& l, const L& m, P& r) {
    D cr1 = crs(l.vec(), m.vec()), cr2 = crs(l.vec(), l.t - m.s);
    if (sgncrs(l.vec(), m.vec()) == 0) {
        r = l.s;
        if (sgncrs(l.vec(), l.t - m.s)) return 0;
        return -1;
    }
    r = m.s + m.vec() * cr2 / cr1;
    return 1;
}

int crossSS(L l, L m, P& r) {
    int u = crossLL(l, m, r);
    if (u == 0) return 0;
    if (u == -1) {
        r = max(min(l.s, l.t), min(m.s, m.t));
        P q = min(max(l.s, l.t), max(m.s, m.t));
        return (q < r) ? 0 : (q == r ? 1 : -1);
    }
    if (ccw(l, r) == 0 && ccw(m, r) == 0) return 1;
    return 0;
}


using Pol = V<P>;

D area2(const Pol& pol) {
    D u = 0;
    if (!pol.size()) return u;
    P a = pol.back();
    for (auto b : pol) u += crs(a, b), a = b;
    return u;
}

// (1:left) | (2: right) is inside between v[i] ~ v[i + 1]
V<pair<P, int>> insPolL(Pol pol, L l) {
    using Pi = pair<P, int>;
    V<Pi> v;
    P a, b = pol.back();
    for (auto now: pol) {
        a = b; b = now;
        P p;
        if (crossLL({a, b}, l, p) != 1) continue;
        int sa = ccw(l, a) % 2, sb = ccw(l, b) % 2;
        if (sa > sb) swap(sa, sb);
        if (sa != 1 && sb == 1) v.push_back({p, 1});
        if (sa == -1 && sb != -1) v.push_back({p, 2});
    }
    sort(v.begin(), v.end(), [&](Pi x, Pi y){
        return dot(l.vec(), x.first - l.s) < dot(l.vec(), y.first - l.s);
    });
    int m = int(v.size());
    V<Pi> res;
    for (int i = 0; i < m; i++) {
        if (i) v[i].second ^= v[i - 1].second;
        if (!res.empty() && res.back().first == v[i].first) res.pop_back();
        res.push_back(v[i]);
    }
    return res;
}

// 0: outside, 1: on line, 2: inside
int contains(const Pol& pol, P p) {
    if (!pol.size()) return 0;
    int in = -1;
    P _a, _b = pol.back();
    for (auto now : pol) {
        _a = _b;
        _b = now;
        P a = _a, b = _b;
        if (ccw(a, b, p) == 0) return 1;
        if (a.y > b.y) swap(a, b);
        if (!(a.y <= p.y && p.y < b.y)) continue;
        if (sgn(a.y, p.y) ? (crs(a - p, b - p) > 0) : (a.x > p.x)) in *= -1;
    }
    return in + 1;
}

// p must be sorted and uniqued!
Pol convex_down(const V<P>& ps) {
    assert(ps.size() >= 2);
    Pol dw;
    for (P d : ps) {
        size_t n;
        while ((n = dw.size()) > 1) {
            // if (ccw(dw[n - 2], dw[n - 1], d) != -1) break; // line
            if (ccw(dw[n - 2], dw[n - 1], d) == 1) break;
            dw.pop_back();
        }
        dw.push_back(d);
    }
    return dw;
}

Pol convex(V<P> ps) {
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    if (ps.size() <= 1) return ps;
    Pol dw = convex_down(ps);
    reverse(ps.begin(), ps.end());
    Pol up = convex_down(ps);
    dw.insert(dw.begin(), up.begin() + 1, up.end() - 1);
    return dw;
}

Pol convex_cut(const Pol& po, const L& l) {
    if (!po.size()) return Pol{};
    Pol q;
    P a, b = po.back();
    for (auto now : po) {
        a = b;
        b = now;
        if ((ccw(l, a) % 2) * (ccw(l, b) % 2) < 0) {
            P buf;
            crossLL(l, L(a, b), buf);
            q.push_back(buf);
        }
        if (ccw(l, b) != -1) q.push_back(b);
    }
    return q;
}

// pol must be convex
D diameter(const Pol& p) {
    int n = int(p.size());
    if (n == 2) return (p[1] - p[0]).abs();
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        if (p[i] < p[x]) x = i;
        if (p[y] < p[i]) y = i;
    }
    D ans = 0;
    int sx = x, sy = y;
    /*
    do {
        ...
    } while (sx != x || sy != y);
    1
    */
    while (sx != y || sy != x) {
        ans = max(ans, (p[x] - p[y]).abs());
        int nx = (x + 1 < n) ? x + 1 : 0, ny = (y + 1 < n) ? y + 1 : 0;
        if (crs(p[nx] - p[x], p[ny] - p[y]) < 0)
            x = nx;
        else
            y = ny;
    }
    return ans;
}


struct C {
    P p;
    D r;
    C(P _p = P(), D _r = D()) : p(_p), r(_r) {}
};

// need Intersect/distLP, r.sl.s
int crossCL(const C& c, const L& l, L& r) {
    D u = distLP(l, c.p);
    int si = sgn(u, c.r);
    if (si == 1) return 0;
    P v = project(l, c.p);
    P di = (si == 0) ? P(0, 0) : l.vec() * (sqrt(c.r * c.r - u * u) / l.abs());
    r = L(v - di, v + di);
    if (si == 0) return 1;
    return 2;
}

// need Intersect/distLP, r.sl.s
int crossCS(const C& c, const L& s, L& l) {
    if (!crossCL(c, s, l)) return 0;
    bool f1 = !ccw(s, l.s), f2 = !ccw(s, l.t);
    if (f1 && f2) return 2;
    if (!f1 && !f2) return 0;
    if (f1)
        l.t = l.s;
    else
        l.s = l.t;
    return 1;
}

// return number of cross point
// l, rc[l, r]d
int crossCC(const C& c, const C& d, D& l, D& r) {
    if (c.p == d.p) {
        assert(sgn(c.r - d.r));  // prohibit same circles
        return 0;
    }
    D di = (c.p - d.p).abs(), bth = (d.p - c.p).arg();
    D costh = (c.r * c.r + di * di - d.r * d.r) / (2 * c.r * di);
    int ty = min(sgn(c.r + d.r, di), sgn(di, abs(c.r - d.r)));
    if (ty == -1) return 0;
    if (ty == 0) costh = sgn(costh);
    D th = acos(costh);
    l = bth - th;
    r = bth + th;
    return ty + 1;
}

// pcp1, p2
int tangent(const C& c, const P& p, P& p1, P& p2) {
    D di = (c.p - p).abs();
    int si = sgn(c.r, di);
    if (si == 1) return 0;
    D th = acos(min(D(1), c.r / di));
    D ar = (p - c.p).arg();
    p1 = c.p + P::polar(c.r, ar - th);
    p2 = c.p + P::polar(c.r, ar + th);
    if (si == 0) return 1;
    return 2;
}

//
int tangent(const C& c, const C& d, L& l, L& r, bool inter) {
    D di = (d.p - c.p).abs(), ar = (d.p - c.p).arg();
    if (sgn(di) == 0) {
        assert(sgn(c.r - d.r));  // prohibit same circles
        return 0;
    }
    D costh = c.r + (inter ? d.r : -d.r);
    int si = sgn(abs(costh), di);
    costh /= di;
    if (si == 1)
        return 0;
    else if (si == 0)
        costh = sgn(costh);
    D th = acos(costh);
    P base;
    base = P::polar(1, ar - th);
    l = L(c.p + base * c.r, d.p + base * d.r * (inter ? -1 : 1));
    base = P::polar(1, ar + th);
    r = L(c.p + base * c.r, d.p + base * d.r * (inter ? -1 : 1));
    if (si == 0) return 1;
    return 2;
}

C circum_circle(P a, P b, P c) {
    b -= a;
    c -= a;
    D s = 2 * crs(b, c);
    D x = (b - c).norm(), y = c.norm(), z = b.norm();
    D S = x + y + z;
    P r = (b * (S - 2 * y) * y + c * z * (S - 2 * z)) / (s * s);
    return C(r + a, r.abs());
}

C smallest_circle(const Pol& p, int i, array<P, 3> q, int j) {
    if (i == int(p.size())) {
        switch (j) {
            case 0:
                return C(P(0, 0), -1);
            case 1:
                return C(q[0], 0);
            case 2:
                return C((q[0] + q[1]) / D(2.0), (q[0] - q[1]).abs() / D(2.0));
            case 3:
                return circum_circle(q[0], q[1], q[2]);
        }
        assert(false);
    }
    C c = smallest_circle(p, i + 1, q, j);
    if (sgn((p[i] - c.p).abs(), c.r) == 1) {
        q[j] = p[i];
        return smallest_circle(p, i + 1, q, j + 1);
    }
    return c;
}
C smallest_circle(Pol p) {
    random_shuffle(begin(p), end(p));
    return smallest_circle(p, 0, array<P, 3>(), 0);
}

// C(P(0, 0), r)Tri((0, 0), a, b)
D area2CT(const C& c, const P& _a, const P& _b) {
    P a = _a - c.p, b = _b - c.p;
    D r = c.r;
    if (a == b) return 0;
    auto single = [&](P x, P y, bool tri) {
        if (tri)
            return crs(x, y);
        else
            return r * r * ((y * P(x.x, -x.y)).arg());
    };
    bool ia = sgn(a.abs(), r) != 1, ib = sgn(b.abs(), r) != 1;
    if (ia && ib) return single(a, b, true);
    L l;
    if (!crossCS(C(P(0, 0), r), L(a, b), l)) return single(a, b, false);
    return single(a, l.s, ia) + single(l.s, l.t, true) + single(l.t, b, ib);
}

// p, c
D area2CPol(const C& c, const Pol& po) {
    D sm = 0;
    P a, b = po.back();
    for (auto p : po) {
        a = b;
        b = p;
        sm += area2CT(c, a, b);
    }
    return sm;
}

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1) {}
  int root(int v) const {
    while (p[v] != -1) v = p[v];
    return v;
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  V<C> cs(n);
  V<P> ps;
  for (auto&& e : cs) {
    cin >> e.p.x >> e.p.y >> e.r;
    ps.push_back(e.p + P(e.r));
  }
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      D th[2];
      int cnt = crossCC(cs[i], cs[j], th[0], th[1]);
      for (int k = 0; k < cnt; ++k) {
        ps.push_back(cs[i].p + P::polar(cs[i].r, th[k]));
      }
    }
  }
  sort(begin(ps), end(ps));
  ps.erase(unique(begin(ps), end(ps)), end(ps));
  int res = 1 - ps.size();
  dsu d(ps.size());
  for (auto&& e : cs) {
    vector<int> vs;
    for (int v = 0; v < (int)ps.size(); ++v) {
      if (sgn((ps[v] - e.p).abs(), e.r) == 0) {
        vs.push_back(v);
        ++res;
      }
    }
    sort(begin(vs), end(vs), [&](int u, int v) {
      return sgn((ps[u] - e.p).arg() < (ps[v] - e.p).arg()) < 0;
    });
    for (int i = 0; i < (int)vs.size(); ++i) {
      d.unite(vs[i], vs[(i + 1) % vs.size()]);
    }
  }
  res += d.cc;
  cout << res << '\n';
}