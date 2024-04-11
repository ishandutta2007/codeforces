#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 1e5 + 1;
const int BLOCK = 150;
const int CNT = (N + BLOCK - 1) / BLOCK;

namespace st{
    const ll INF = -1e18;
    struct Line{
        ll k, b;
        Line() : k(0), b(INF) {}
        Line(ll _k, ll _b) : k(_k), b(_b) {}
        ll eval(ll x) const {
            return x * k + b;
        }
    };

    ld cross(const Line& a, const Line& b) {
        return (ld)(a.b - b.b) / (b.k - a.k);
    }

    const ld EPS = 1e-9;

    int sign(ld x) {
        if (x > EPS) return 1;
        if (x < -EPS) return -1;
        return 0;
    }

    struct ConvexHull{
        vector<Line> lines;
        vector<ld> points;
        int pos = 0;
        ConvexHull() = default;
        ConvexHull(int n) {
            pos = 0;
            lines.reserve(n);
            points.reserve(n);
        }
        void addLine(const Line& line) {
            while (!points.empty() && sign(points.back() - cross(lines.back(), line)) >= 0) {
                points.pop_back();
                lines.pop_back();
            } 
            if (!lines.empty()) {
                points.push_back(cross(lines.back(), line));
            }
            lines.push_back(line);
        }
        ll get(ll x, ll& id) {
            while (pos < points.size() && points[pos] < x) ++pos;
            id = lines[pos].k;
            return lines[pos].eval(x);
        }
    };

    ConvexHull a[CNT];
    Line lines[N];
    int cntUpd[CNT];    

    void init() {
        fill(cntUpd, cntUpd + CNT, 0);
        for (int i = 0; i < N; ++i) {
            lines[i] = Line(i, 0);
            a[i / BLOCK].addLine(lines[i]);
        }
    }

    void add(int pref) {
        int R = pref / BLOCK;
        for (int i = 0; i < R; ++i) {
            cntUpd[i]++;
        }
        int l = R * BLOCK;
        int r = min(N, (R + 1) * BLOCK);
        a[R] = ConvexHull(r - l);
        for (int i = l; i < r; ++i) {
            lines[i] = Line(i, lines[i].eval(cntUpd[R]) + (pref >= i ? i : 0));
            a[R].addLine(lines[i]);
        }
        cntUpd[R] = 0;       
    }

    void get(ll& p, ll& ans) {
        p = -1, ans = 0;
        for (int i = 0; i < CNT; ++i) {
            ll fans;
            ll fp = -1;
            fans = a[i].get(cntUpd[i], fp);
            assert(fp != -1);
            if (p == -1 || ans < fans) {
                ans = fans;
                p = fp;
            }
        }
    }
};

int n, w;
int a[N], b[N];
int order[N];

ll ans[N][2];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    st::init();
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    iota(order, order + n, 0);
    sort(order, order + n, [&] (int i, int j) {
        return b[i] < b[j];
    });
    int mxB = b[order[n - 1]];
    int pos = 0;
    for (int c = 0; c <= mxB + 1; ++c) {
        while (pos < n && b[order[pos]] < c) {
            st::add(a[order[pos]]);
            ++pos;
        }
        st::get(ans[c][0], ans[c][1]);
        ans[c][1] += (ll)c * w * (n - pos);
    }
    for (int i = 0; i <= mxB + 1; ++i) {
        cout << ans[i][1] << " " << ans[i][0] << '\n';
    }
    return 0;
}