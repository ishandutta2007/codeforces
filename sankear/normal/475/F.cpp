#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = int(1e5) + 100;

int x[3 * N], y[3 * N];

int get(int *f, int pos) {
    int res = 0;
    while (pos >= 0) {
        res += f[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

int get(int *f, int l, int r) {
    return get(f, r) - get(f, l - 1);
}

struct myset {
    
    bool *del;
    vector<pii> sp;
    int kx, ky, lx, ly, rx, ry, all = 0;
    int *fx, *fy;
    queue<int> qx, qy;
    vector<int> *vx, *vy;
    
    ~myset() {
        delete[] del;
        delete[] fx;
        delete[] fy;
        delete[] vx;
        delete[] vy;
    }
    
    myset(vector<pii> p) {
        int n = sz(p);
        kx = ky = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = -1; j <= 1; ++j) {
                x[kx++] = p[i].fs + j;
                y[ky++] = p[i].sc + j;
            }
        }
        
        sort(x, x + kx);
        kx = (int) (unique(x, x + kx) - x);
        lx = 0;
        rx = kx - 1;
        fx = new int[kx];
        for (int i = 0; i < kx; ++i) {
            fx[i] = 0;
        }
        
        sort(y, y + ky);
        ky = (int) (unique(y, y + ky) - y);
        ly = 0;
        ry = ky - 1;
        fy = new int[ky];
        for (int i = 0; i < ky; ++i) {
            fy[i] = 0;
        }
        
        vx = new vector<int>[kx];
        vy = new vector<int>[ky];
        all = n;
        
        sp.resize(n);
        del = new bool[n];
        for (int i = 0; i < n; ++i) {
            int cx = (int) (lower_bound(x, x + kx, p[i].fs) - x);
            int cy = (int) (lower_bound(y, y + ky, p[i].sc) - y);
            sp[i] = mp(cx, cy);
            del[i] = false;
            ++fx[cx];
            ++fy[cy];
            vx[cx].pb(i);
            vy[cy].pb(i);
        }
        
        for (int i = 0; i < kx; ++i) {
            if ((i | (i + 1)) < kx) {
                fx[(i | (i + 1))] += fx[i];
            }
        }
        for (int i = 0; i < ky; ++i) {
            if ((i | (i + 1)) < ky) {
                fy[(i | (i + 1))] += fy[i];
            }
        }
        
        for (int i = 0; i < kx; ++i) {
            if (get(fx, i, i) == 0) {
                qx.push(i);
            }
        }
        for (int i = 0; i < ky; ++i) {
            if (get(fy, i, i) == 0) {
                qy.push(i);
            }
        }
    }
    
};

inline void add(int *f, int size, int pos, int add) {
    while (pos < size) {
        f[pos] += add;
        pos = (pos | (pos + 1));
    }
}

inline vector<pii> separate_and_delete(myset &s, int p, bool by_x) {
    vector<pii> res;
    vector<int> *v = (by_x ? s.vx : s.vy);
    int *f = (by_x ? s.fx : s.fy);
    int &l = (by_x ? s.lx : s.ly);
    int &r = (by_x ? s.rx : s.ry);
    queue<int> &q = (by_x ? s.qx : s.qy);
    if (p < l || p > r || l > r) {
        return res;
    }
    if (get(f, l, p) * 2 < s.all) {
        for (int i = p; i >= l; --i) {
            for (int j = 0; j < sz(v[i]); ++j) {
                if (s.del[v[i][j]]) {
                    continue;
                }
                s.del[v[i][j]] = true;
                int x = s.sp[v[i][j]].fs, y = s.sp[v[i][j]].sc;
                add(s.fx, s.kx, x, -1);
                add(s.fy, s.ky, y, -1);
                --s.all;
                if (get(s.fx, x, x) == 0) {
                    s.qx.push(x);
                }
                if (get(s.fy, y, y) == 0) {
                    s.qy.push(y);
                }
                res.pb(mp(x, y));
            }
        }
        l = p + 1;
    } else {
        for (int i = p; i <= r; ++i) {
            for (int j = 0; j < sz(v[i]); ++j) {
                if (s.del[v[i][j]]) {
                    continue;
                }
                s.del[v[i][j]] = true;
                int x = s.sp[v[i][j]].fs, y = s.sp[v[i][j]].sc;
                add(s.fx, s.kx, x, -1);
                add(s.fy, s.ky, y, -1);
                --s.all;
                if (get(s.fx, x, x) == 0) {
                    s.qx.push(x);
                }
                if (get(s.fy, y, y) == 0) {
                    s.qy.push(y);
                }
                res.pb(mp(x, y));
            }
        }
        r = p - 1;
    }
    return res;
}

int solve(myset &s) {
    int ans = 0;
    while (!s.qx.empty() || !s.qy.empty()) {
        vector<pii> res;
        if (!s.qx.empty()) {
            int x = s.qx.front();
            s.qx.pop();
            res = separate_and_delete(s, x, true);
        } else {
            int y = s.qy.front();
            s.qy.pop();
            res = separate_and_delete(s, y, false);
        }
        myset ns(res);
        ans += solve(ns);
    }
    if (s.all > 0) {
        ++ans;
    }
    return ans;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector<pii> p(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i].fs, &p[i].sc);
    }
    myset s(p);
    int ans = solve(s);
    cout << ans << endl;
    return 0;
}