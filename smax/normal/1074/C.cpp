#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const long long INF = 1e18;

template<typename T>
struct SegmentTreeMax {
    int n;
    vector<T> st;

    SegmentTreeMax(int _n) : n(_n), st(2 * n, -INF) {}

    SegmentTreeMax(const vector<T> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = max(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ret = -INF;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret, st[l++]);
            if (r&1) ret = max(ret, st[--r]);
        }
        return ret;
    }

    void update(int p, T val) {
        p += n;
        for (st[p]=max(st[p], val); p>1; p>>=1)
            st[p>>1] = max(st[p], st[p^1]);
    }
};

template<typename T>
struct SegmentTreeMin {
    int n;
    vector<T> st;

    SegmentTreeMin(int _n) : n(_n), st(2 * n, INF) {}

    SegmentTreeMin(const vector<T> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = min(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ret = INF;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret = min(ret, st[l++]);
            if (r&1) ret = min(ret, st[--r]);
        }
        return ret;
    }

    void update(int p, T val) {
        p += n;
        for (st[p]=min(st[p], val); p>1; p>>=1)
            st[p>>1] = min(st[p], st[p^1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long mnX = INF, mxX = -INF, mnY = INF, mxY = -INF;
    vector<pair<long long, long long>> pts(n);
    map<long long, int> compress;
    for (int i=0; i<n; i++) {
        cin >> pts[i].first >> pts[i].second;
        mnX = min(mnX, pts[i].first);
        mxX = max(mxX, pts[i].first);
        mnY = min(mnY, pts[i].second);
        mxY = max(mxY, pts[i].second);
        compress[pts[i].second];
    }

    int sz = 0;
    for (auto &p : compress)
        p.second = sz++;

    long long ret = 0;
    sort(pts.begin(), pts.end());
    SegmentTreeMax<long long> maxY(sz), maxYminusX(sz);
    SegmentTreeMin<long long> minX(sz), minY(sz), minXplusY(sz);
    for (auto [x, y] : pts) {
        int idx = compress[y];
        // case 1: both with less y
        ret = max(ret, x - minX.query(0, idx) + y - minY.query(0, idx));
        // case 2: both with greater y
        long long part1 = minX.query(idx, sz), part2 = maxY.query(idx, sz);
        if (part1 < INF && part2 > -INF) ret = max(ret, x - part1 + part2 - y);
        // case 3: one on each side
        // case 3a: less y is responsible for min X
        part1 = maxY.query(idx, sz), part2 = minXplusY.query(0, sz);
        if (part1 > -INF && part2 < INF) ret = max(ret, x + part1 - part2);
        // case 3b: greater y is responsible for min X
        part1 = minY.query(0, sz), part2 = maxYminusX.query(idx, sz);
        if (part1 < INF && part2 > -INF) ret = max(ret, x - part1 + part2);
        // updates
        maxY.update(idx, y);
        maxYminusX.update(idx, y - x);
        minX.update(idx, x);
        minY.update(idx, y);
        minXplusY.update(idx, x + y);
    }

    cout << 2 * ret;
    for (int i=4; i<=n; i++)
        cout << " " << 2 * (mxX - mnX) + 2 * (mxY - mnY);
    cout << "\n";

    return 0;
}