#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Point{
    int x, y;
};

const int INF = 1e9 + 228;
const int N = 14;
const int M = 110;
int n, m;
Point a[N];
Point b[M];
int t[M];

void reorder() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (t[j] > t[j + 1]) {
                swap(b[j], b[j + 1]);
                swap(t[j], t[j + 1]);
            }
        }
    }
    for (int i = 1; i < m; ++i) {
        assert(t[i - 1] <= t[i]);
    }
}

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].x >> b[i].y >> t[i];
    }
}

int dist(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

const int MASK = (1 << N) + 228;

int dp1[MASK][M], dp2[MASK][M];

int minDistA[MASK][N];
int minDistB[MASK][M];

void init() {
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            minDistA[mask][i] = INF;
            for (int last = 0; last < n; ++last) {
                if ((mask >> last) & 1) { 
                    chkmin(minDistA[mask][i], dist(a[i], a[last]));
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            minDistB[mask][i] = INF;
            for (int last = 0; last < n; ++last) {
                if ((mask >> last) & 1) {
                    chkmin(minDistB[mask][i], dist(b[i], a[last]));
                }
            }
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int cnt = 0; cnt <= m; ++cnt) {
            dp1[mask][cnt] = INF;
        }
    }
    for (int bit = 0; bit < n; ++bit) {
        dp1[1 << bit][0] = 0;
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int bit = 0; bit < n; ++bit) {
            if ((mask >> bit) & 1) continue;
            chkmin(dp1[mask ^ (1 << bit)][0], dp1[mask][0] + minDistA[mask][bit]);
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int pos = 0; pos < m; ++pos) {
            dp2[mask][pos] = -1;
        }
    }
}

void relax(int pos) {
    dp2[0][pos] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int prev = 0; prev < pos; ++prev) {
            if (dp2[mask][prev] == -1) continue;
            if (dist(b[pos], b[prev]) + t[prev] <= t[pos]) {
                chkmax(dp2[mask][pos], dp2[mask][prev] + 1);
            }
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int cnt = 0; cnt <= pos; ++cnt) {
            int haveT = dp1[mask][cnt] + minDistB[mask][pos];
            if (haveT > t[pos]) continue;
            chkmax(dp2[mask][pos], cnt + 1);
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp2[mask][pos] == -1) continue;
        chkmin(dp1[mask][dp2[mask][pos]], t[pos]);
        for (int bit = 0; bit < n; ++bit) {
            if ((mask >> bit) & 1) continue;
            chkmin(dp1[mask ^ (1 << bit)][dp2[mask][pos]], t[pos] + dist(a[bit], b[pos]));
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int bit = 0; bit < n; ++bit) {
            if ((mask >> bit) & 1) continue;
            for (int cnt = 0; cnt <= pos + 1; ++cnt) {
                chkmin(dp1[mask ^ (1 << bit)][cnt], dp1[mask][cnt] + minDistA[mask][bit]);
            }
        }
    }
}

int ans;

void makeAns() {
    ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int pos = 0; pos < m; ++pos){
            chkmax(ans, dp2[mask][pos]);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    read();
    reorder();
    init();
    for (int pos = 0; pos < m; ++pos) {
        relax(pos);
    }
    makeAns();
    cout << ans << endl;
    return 0;
}