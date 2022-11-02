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
#include <complex>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(5e5) + 100;

struct rows {
    
    int maxv;
    vector<pii> lst[4 * N];
    
    inline void build(int n, int m, vi ys[N]) {
        maxv = 1;
        while (maxv < n) {
            maxv *= 2;
        }
        for (int i = 0; i < n; ++i) {
            int last = -1;
            sort(all(ys[i]));
            for (int j = 0; j < sz(ys[i]); ++j) {
                if (last + 1 <= ys[i][j] - 1) {
                    lst[i + maxv].pb(mp(last + 1, ys[i][j] - 1));
                }
                last = ys[i][j];
            }
            if (last + 1 <= m - 1) {
                lst[i + maxv].pb(mp(last + 1, m - 1));
            }
        }
        for (int i = maxv - 1; i > 0; --i) {
            lst[i].resize(sz(lst[i * 2]) + sz(lst[i * 2 + 1]));
            merge(all(lst[i * 2]), all(lst[i * 2 + 1]), lst[i].begin());
        }
        for (int i = 1; i < 2 * maxv; ++i) {
            for (int j = 1; j < sz(lst[i]); ++j) {
                lst[i][j].sc = max(lst[i][j].sc, lst[i][j - 1].sc);
            }
        }
    }
    
    bool find(int l, int r, int x, int y) {
        l += maxv;
        r += maxv;
        while (l <= r) {
            if (l % 2 != 0) {
                int pos = (int) (lower_bound(all(lst[l]), mp(x + 1, -1)) - lst[l].begin() - 1);
                if (pos >= 0 && lst[l][pos].sc >= y) {
                    return true;
                }
            }
            l = (l + 1) / 2;
            if (r % 2 == 0) {
                int pos = (int) (lower_bound(all(lst[r]), mp(x + 1, -1)) - lst[r].begin() - 1);
                if (pos >= 0 && lst[r][pos].sc >= y) {
                    return true;
                }
            }
            r = (r - 1) / 2;
        }
        return false;
    }
    
};

rows rows, cols;
vi xs[N], ys[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        ys[x].pb(y);
        xs[y].pb(x);
    }
    rows.build(n, m, ys);
    cols.build(m, n, xs);
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        --x1;
        --y1;
        --x2;
        --y2;
        if (rows.find(x1, x2, y1, y2) && cols.find(y1, y2, x1, x2)) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    return 0;
}