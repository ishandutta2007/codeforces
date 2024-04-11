#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || _WIN64 || __WIN32__ || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef complex<double> tc;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(2e5) + 100;

struct seg {
    
    int l, r, pl, num;
    
};

bool operator < (const seg& a, const seg& b) {
    return a.r - a.l > b.r - b.l;
}

int k;
seg s[N];
int a[N], pa[N], b[N], c[N], l[N], r[N], ans[N], mid[N], x[N], fen_sum[N], fen_max[N];
bool good[N];
pii q[N];

inline void add(int num) {
    for (int pos = s[num].pl; pos < k; pos = (pos | (pos + 1))) {
        ++fen_sum[pos];
        fen_max[pos] = max(fen_max[pos], s[num].r);
    }
}

inline int get_max(int pos) {
    int res = -inf;
    while (pos >= 0) {
        res = max(res, fen_max[pos]);
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

inline int get_cnt(int pos) {
    int res = 0;
    while (pos >= 0) {
        res += fen_sum[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

inline int get_cnt(int l, int r) {
    if (l > r) {
        return 0;
    }
    return get_cnt(r) - (l > 0 ? get_cnt(l - 1) : 0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &s[i].l, &s[i].r);
        x[i] = s[i].l;
        s[i].num = i;
    }
    sort(s, s + n);
    sort(x, x + n);
    k = (int) (unique(x, x + n) - x);
    for (int i = 0; i < n; ++i) {
        s[i].pl = (int) (lower_bound(x, x + k, s[i].l) - x);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", a + i, b + i, c + i);
        pa[i] = (int) (upper_bound(x, x + k, a[i]) - x);
        l[i] = 1;
        r[i] = inf;
        ans[i] = 0;
    }
    for (;;) {
        bool fl = false;
        int sz = 0;
        for (int i = 0; i < m; ++i) {
            if (l[i] <= r[i]) {
                mid[i] = (l[i] + r[i]) / 2;
                good[i] = false;
                fl = true;
                q[sz++] = mp(mid[i], i);
            }
        }
        if (!fl) {
            break;
        }
        sort(q, q + sz);
        reverse(q, q + sz);
        for (int i = 0; i < k; ++i) {
            fen_sum[i] = 0;
            fen_max[i] = -inf;
        }
        int ptr = 0;
        for (int i = 0; i < sz; ++i) {
            while (ptr < n && s[ptr].r - s[ptr].l >= q[i].fs) {
                add(ptr++);
            }
            int num = q[i].sc;
            if (min(get_max(pa[num] - 1), b[num]) >= a[num] + mid[num]) {
                good[num] = true;
                continue;
            }
            int pos = (int) (upper_bound(x, x + k, b[num] - mid[num]) - x);
            if (get_cnt(pa[num], pos - 1) > 0) {
                good[num] = true;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (l[i] <= r[i]) {
                if (good[i]) {
                    ans[i] = mid[i];
                    l[i] = mid[i] + 1;
                } else {
                    r[i] = mid[i] - 1;
                }
            }
        }
    }
    ll best = 0;
    int x = -1, y = -1;
    for (int i = 0; i < m; ++i) {
        ll cur = 1LL * c[i] * ans[i];
        if (cur > best) {
            best = cur;
            y = i;
        }
    }
    if (best > 0) {
        for (int i = 0; i < n; ++i) {
            int l = max(s[i].l, a[y]);
            int r = min(s[i].r, b[y]);
            if (l > r) {
                continue;
            }
            if (1LL * (r - l) * c[y] == best) {
                x = s[i].num;
            }
        }
        assert(x != -1);
    }
    cout << best << endl;
    if (best > 0) {
        cout << x + 1 << " " << y + 1 << endl;
    }
    return 0;
}