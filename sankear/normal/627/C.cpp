#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) sz(s)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9 + 100500;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;

int maxv;
int need[N];
pii a[N];
pii rmq[4 * N];

inline pii get_min(int l, int r) {
    l += maxv;
    r += maxv;
    pii res(inf, -1);
    while (l <= r) {
        res = min(res, rmq[l]);
        l = (l + 1) / 2;
        res = min(res, rmq[r]);
        r = (r - 1) / 2;
    }
    return res;
}

int find_better(int v, int gl, int gr, int l, int r, int val) {
    if (gl > r || gr < l || l > r) {
        return -1;
    }
    if (l <= gl && gr <= r) {
        if (rmq[v].fs < val) {
            while (v < maxv) {
                if (rmq[v * 2].fs < val) {
                    v *= 2;
                } else {
                    v = v * 2 + 1;
                }
            }
            return v - maxv;
        } else {
            return -1;
        }
    }
    int mid = (gl + gr) / 2;
    int res = find_better(v * 2, gl, mid, l, r, val);
    if (res != -1) {
        return res;
    }
    return find_better(v * 2 + 1, mid + 1, gr, l, r, val);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int d, n, m;
    cin >> d >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a[i].fs, &a[i].sc);
    }
    sort(a, a + m);
    maxv = 1;
    while (maxv < m) {
        maxv *= 2;
    }
    for (int i = 0; i < m; ++i) {
        rmq[i + maxv] = mp(a[i].sc, i);
    }
    for (int i = m; i < maxv; ++i) {
        rmq[i + maxv] = mp(inf, -1);
    }
    for (int i = maxv - 1; i > 0; --i) {
        rmq[i] = min(rmq[i * 2], rmq[i * 2 + 1]);
    }
    for (int i = 0; i < m; ++i) {
        need[i] = min(n, d - a[i].fs);
        int pos = find_better(1, 0, maxv - 1, i + 1, m - 1, a[i].sc);
        if (pos != -1) {
            need[i] = min(need[i], a[pos].fs - a[i].fs);
        }
    }
    int cur_x = 0, cur_f = n;
    ll ans = 0;
    for (;;) {
        if (cur_x + cur_f >= d) {
            break;
        }
        int l = upper_bound(a, a + m, mp(cur_x, inf)) - a;
        int r = upper_bound(a, a + m, mp(cur_x + cur_f, inf)) - a;
        if (l >= r) {
            puts("-1");
            return 0;
        }
        pii best = get_min(l, r - 1);
        cur_f -= a[best.sc].fs - cur_x;
        cur_x = a[best.sc].fs;
        if (cur_f < need[best.sc]) {
            ans += 1LL * (need[best.sc] - cur_f) * best.fs;
            cur_f = need[best.sc];
        }
    }
    cout << ans << endl;
    return 0;
}