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

const double EPS = 1e-9;

template<typename T>
struct Point {
    T x, y;
    Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    Point operator + (const Point &other) const {return Point(x + other.x, y + other.y);}
    Point operator - (const Point &other) const {return Point(x - other.x, y - other.y);}
    Point operator * (T c) const {return Point(x * c, y * c);}
    Point operator / (T c) const {return Point(x / c, y / c);}
    Point& operator += (const Point &other) {return *this = *this + other;}
    Point& operator -= (const Point &other) {return *this = *this - other;}
    Point& operator *= (T c) {return *this = *this * c;}
    Point& operator /= (T c) {return *this = *this / c;}
    bool operator < (const Point &other) const {return tie(x, y) < tie(other.x, other.y);}
    bool operator <= (const Point &other) const {return tie(x, y) <= tie(other.x, other.y);}
    bool operator > (const Point &other) const {return tie(x, y) > tie(other.x, other.y);}
    bool operator >= (const Point &other) const {return tie(x, y) >= tie(other.x, other.y);}
    bool operator == (const Point &other) const {return tie(x, y) == tie(other.x, other.y);}
    bool operator != (const Point &other) const {return tie(x, y) != tie(other.x, other.y);}
    T mag2() const {return x * x + y * y;}
    double mag() const {return sqrt(mag2());}
    Point unit() const {return *this / mag();}
    Point perp() const {return Point(-y, x);}
    Point normal() const {return perp().unit();}
    double angle() const {return atan2(y, x);}
    Point rot(double ang) const {return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));}
    friend T dot(const Point &a, const Point &b) {return a.x * b.x + a.y * b.y;}
    friend T cross(const Point<T> &a, const Point<T> &b) {return a.x * b.y - a.y * b.x;}
    friend T dist2(const Point<T> &a, const Point<T> &b) {return (a - b).mag2();}
    friend double dist(const Point<T> &a, const Point<T> &b) {return (a - b).mag();}
    friend T ccw(const Point<T> &a, const Point<T> &b, const Point<T> &o) {return cross(a - o, b - o);}
    friend double angle(const Point<T> &a, const Point<T> &b) {return atan2(cross(a, b), dot(a, b));}
    friend Point<T> rot(const Point<T> &p, const Point<T> &o, double ang) {return o + (p - o).rot(ang);}
    friend ostream& operator << (ostream &os, const Point &p) {return os << "(" << p.x << ", " << p.y << ")";}
};
typedef Point<long long> P;

template<typename T>
vector<Point<T>> convexHull(vector<Point<T>> &p) {
    sort(p.begin(), p.end());
    vector<Point<T>> h;
    for (int rep=0; rep<2; rep++) {
        auto start = h.size();
        for (auto &pt : p) {
            while (h.size() >= start + 2 && ccw(h[h.size()-2], h.back(), pt) <= 0)
                h.pop_back();
            h.push_back(pt);
        }
        h.pop_back();
        reverse(p.begin(), p.end());
    }
    return h;
}

vector<pair<long long, double>> toString(const vector<P> &p) {
    int n = p.size();
    vector<pair<long long, double>> ret;
    for (int i=0; i<n; i++) {
        int a = i % n, b = (i + 1) % n, c = (i + 2) % n;
        ret.emplace_back((p[c] - p[b]).mag2(), abs(angle(p[a] - p[b], p[c] - p[b])));
    }
    return ret;
}

int lps[200005];

bool operator == (const pair<long long, double> &a, const pair<long long, double> &b) {
    return a.first == b.first && abs(a.second - b.second) < EPS;
}

void preprocess(const vector<pair<long long, double>> &p) {
    lps[0] = 0;
    int j = 0, m = p.size();
    for (int i=1; i<m; i++) {
        while (j != 0 && p[i] != p[j])
            j = lps[j-1];
        lps[i] = (j += (p[i] == p[j]));
    }
}

bool kmp(const vector<pair<long long, double>> &t, const vector<pair<long long, double>> &p) {
    preprocess(p);
    vector<int> ret;
    int j = 0, n = t.size(), m = p.size();
    for (int i=0; i<n; i++) {
        while (j != 0 && t[i] != p[j])
            j = lps[j-1];
        if ((j += (t[i] == p[j])) == m) {
            return true;
            j = lps[j-1];
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<P> a(n), b(m);
    for (int i=0; i<n; i++)
        cin >> a[i].x >> a[i].y;
    for (int i=0; i<m; i++)
        cin >> b[i].x >> b[i].y;

    vector<P> ha = convexHull(a), hb = convexHull(b);
    if (ha.size() != hb.size()) {
        cout << "NO\n";
        return 0;
    }

    vector<pair<long long, double>> sa = toString(ha), sb = toString(hb);
    sa.insert(sa.end(), sa.begin(), sa.end());
    cout << (kmp(sa, sb) ? "YES" : "NO") << "\n";

    return 0;
}