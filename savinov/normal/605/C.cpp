#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template <class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}


template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const ld PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

mt19937 generator;

bool check(int v) {
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

struct Point {
    long long x, y;
    Point(long long xx = 0, long long yy = 0) : x(xx), y(yy) {}
    Point operator-(const Point &r) const {
        return Point(x - r.x, y - r.y);
    }
    Point operator+(const Point &r) const {
        return Point(x + r.x, y + r.y);
    }
    Point operator*(const long long &r) const {
        return Point(x * r, y * r);
    }

    friend long long dot(const Point &l, const Point &r) {
        return l.x * r.x + l.y * r.y;
    }
    friend long long cross(const Point &l, const Point &r) {
        return l.x * r.y - l.y * r.x;
    }
    long long distance(const Point &r) const {
        return (x - r.x) * (x - r.x) + (y - r.y) * (y - r.y);
    }
    friend ostream & operator<<(ostream & os, const Point &r) {
        return os << "{" << r.x << ", " << r.y << "}";
    }
    bool operator<(const Point &r) const {
        return x < r.x || (x == r.x && y < r.y);
    }
    bool operator==(const Point &r) const {
        return x == r.x && y == r.y;
    }
};

void makeConvex(vector <Point> &points) {
    if (points.size() < 3) {
        return;
    }
    iter_swap(points.begin(), min_element(points.begin(), points.end()));
    auto cmp = [&](const Point &l, const Point &r) {
        long long cr = cross(l - points.front(), r - points.front());
        if (cr != 0) {
            return cr > 0;
        }
        return dot(l - points.front(), l - points.front()) < dot(r - points.front(), r - points.front());
    };
    sort(points.begin() + 1, points.end(), cmp);

    vector <Point> hull;

    for (const Point & point : points) {
        while (hull.size() > 1 && cross(hull[hull.size() - 1] - hull[hull.size() - 2], point - hull[hull.size() - 2]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(point);
    }
    points.swap(hull);
}

void makeUnique(vector <Point> &points) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "parts"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();
    int p = nxt();
    int q = nxt();

    vector <Point> points(n + 3);

    long long mx = 0, my = 0;

    for (int i = 0; i < n; ++i) {
        points[i].x = nxt();
        points[i].y = nxt();

        mx = max(mx, points[i].x);
        my = max(my, points[i].y);
    }

    points[n].x = mx, points[n].y = 0;
    points[n + 1].y = my, points[n + 1].x = 0;
    points[n + 2].y = 0, points[n + 2].x = 0;

    makeUnique(points);
    makeConvex(points);

    assert(points[0].x == 0 && points[0].y == 0);

    Point need(p, q);

//    for (int i = 0; i < points.size(); ++i) {
//        cerr << points[i].x << " " << points[i].y << endl;
//    }

    for (int i = 1; i + 1 < points.size(); ++i) {
        if (cross(points[i], need) >= 0 && cross(points[i + 1], need) <= 0) {
            double ans = 1.0 * cross(need, points[i + 1] - points[i]) / cross(points[i], points[i + 1]);
            cout << setprecision(10) << fixed;
            cout << ans << endl;
            return 0;
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}