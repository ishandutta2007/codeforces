#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct point {
    ll x, y; 
    point() : x(0), y(0) {}
    point(ll x, ll y) : x(x), y(y) {}
    point operator + (const point &ot) const {
        return point(x + ot.x, y + ot.y); 
    }
    point operator * (const ll &c) const {
        return point(c * x, c * y);
    }
    point operator - (const point &ot) const {
        return *this + ot * -1;
    }
    ll dot(const point &ot) const {
        return x * ot.x + y * ot.y;
    }
    ll cross(const point &ot) const {
        return x * ot.y - y * ot.x;
    }
    bool operator < (const point &ot) const {
        return make_pair(x, y) < make_pair(ot.x, ot.y);
    }
};

// negative if widdershins / 0 if collinear / positive if clockwise
ll handedness(const point &a, const point &b, const point &c) {
    return (c - b).cross(b - a);
}

vector<point> chull(vector<point> pts) { // monotone chain algo
    if (pts.empty()) return pts;
    sort(begin(pts), end(pts));
    vector<point> lower, upper;
    for (point p : pts) {
        while (upper.size() >= 2 && handedness(upper[upper.size() - 2], upper[upper.size() - 1], p) <= 0) upper.pop_back();
        upper.push_back(p);
    }
    reverse(begin(pts), end(pts));
    for (point p : pts) {
        while (lower.size() >= 2 && handedness(lower[lower.size() - 2], lower[lower.size() - 1], p) <= 0) lower.pop_back();
        lower.push_back(p);
    }
    lower.pop_back(); upper.pop_back();
    lower.insert(end(lower), begin(upper), end(upper));
    return lower;
}

ll twiceSignedArea(point a, point b, point c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
}

using si = short int;
constexpr int NMAX = 5000;
pair<si, si> farthest[NMAX][NMAX];

bool isFarthestTriplet(int a, int b, int c) {
    return a != -1 && b != -1 && c != -1 && (farthest[a][b].first == c || farthest[a][b].second == c);
}

point completePar(point a, point b, point c) {
    return a + c - b;
}

int main() {
    int n; ll s; scanf("%d %lld", &n, &s);
    vector<point> pts(n);
    for (int i = 0; i < n; ++i) scanf("%lld %lld", &pts[i].x, &pts[i].y);
    vector<point> ch = chull(pts);
    n = ch.size();
    auto getpt = [&] (int i) {
        return ch[i + (i >= n ? -n : 0)];
    };
    /*
    for (auto [a, b] : ch) {
        printf("ch %lld %lld\n", a, b);
    }
    */
    for (int si = 0; si < n; ++si) {
        for (int i = 0; i < n; ++i) farthest[si][i].first = farthest[si][i].second = -1;
        int cfo = 2;
        for (int offset = 1; offset < n - 1; ++offset) {
            cfo = max(cfo, offset + 1);
            auto atwiceawt = [&] (int other) { // twice area (with third)
                return abs(twiceSignedArea(getpt(si), getpt(si + offset), getpt(si + other)));
            };
            while (cfo < n - 1 && atwiceawt(cfo) < atwiceawt(cfo + 1)) ++cfo;
            farthest[si][(si + offset)%n].first = (si + cfo) % n;
            if (cfo < n - 1 && atwiceawt(cfo) == atwiceawt(cfo + 1)) farthest[si][(si + offset) % n].second = (si + cfo + 1) % n;
        }
    }
    auto getViableTriplet = [&] () -> tuple<int, int, int> {
        for (int i = 0; i < n; ++i) {
            for (int off = 1; off < n - 1; ++off) {
                int a = i, b = (i + off) % n, c1 = farthest[a][b].first, c2 = farthest[a][b].second;
                if (isFarthestTriplet(a, b, c1) && isFarthestTriplet(b, c1, a) && isFarthestTriplet(c1, a, b)) {
                    return {a, b, c1};
                }
                if (isFarthestTriplet(a, b, c2) && isFarthestTriplet(b, c2, a) && isFarthestTriplet(c2, a, b)) {
                    return {a, b, c2};
                }
            }
        }
        return {-1, -1, -1};
    };
    auto [pxi, pyi, pzi] = getViableTriplet();
    assert(pzi != -1);
    point px = getpt(pxi), py = getpt(pyi), pz = getpt(pzi);
    point ans1 = completePar(px, py, pz), ans2 = completePar(py, pz, px), ans3 = completePar(pz, px, py);
    printf("%lld %lld\n", ans1.x, ans1.y);
    printf("%lld %lld\n", ans2.x, ans2.y);
    printf("%lld %lld\n", ans3.x, ans3.y);
}