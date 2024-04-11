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
#define rank _rank
#ifdef LOCAL42
#define LLD "%lld"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define LLD "%I64d"
#define eprintf(...)
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
const int N = int(1e6) + 100;

struct rmq {
    
    int maxv;
    int rmq[4 * N];
    
    inline void init(int n) {
        maxv = 1;
        while (maxv < n + 1) {
            maxv *= 2;
        }
        for (int i = 1; i < 2 * maxv; ++i) {
            rmq[i] = -inf;
        }
    }
    
    inline void update(int pos, int val) {
        pos += maxv;
        rmq[pos] = val;
        while (pos > 1) {
            pos /= 2;
            rmq[pos] = max(rmq[pos * 2], rmq[pos * 2 + 1]);
        }
    }
    
    inline int get(int l, int r) {
        l += maxv;
        r += maxv;
        int res = -inf;
        while (l <= r) {
            res = max(res, rmq[l]);
            l = (l + 1) / 2;
            res = max(res, rmq[r]);
            r = (r - 1) / 2;
        }
        return res;
    }
    
};

rmq rmq_max;
vector<pii> g[N];
int ls[N], rs[N], max_num[N], max_left[N];
char buf[111];

inline void fail() {
    puts("IMPOSSIBLE");
    exit(0);
}

int solve(int l, int r) {
    if (l > r) {
        return -1;
    }
    int max_left = ::max_left[l];
    int min_right = r + 1;
    for (int i = 0; i < sz(g[l]); ++i) {
        if (g[l][i].sc == 1) {
            min_right = min(min_right, g[l][i].fs);
        }
    }
    if (min_right <= max_left) {
        fail();
    }
    ls[l] = solve(l + 1, max_left);
    rs[l] = solve(max_left + 1, r);
    return l;
}

void dfs(int v) {
    if (v == -1) {
        return;
    }
    dfs(ls[v]);
    printf("%d ", v);
    dfs(rs[v]);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d %s", &a, &b, buf);
        if (a >= b) {
            fail();
        }
        g[a].pb(mp(b, (buf[0] == 'L' ? -1 : 1)));
    }
    rmq_max.init(n);
    for (int i = n; i > 0; --i) {
        max_num[i] = i;
        max_left[i] = i;
        for (int j = 0; j < sz(g[i]); ++j) {
            if (g[i][j].sc == -1) {
                max_left[i] = max(max_left[i], rmq_max.get(i + 1, g[i][j].fs));
            }
            max_num[i] = max(max_num[i], rmq_max.get(i + 1, g[i][j].fs));
        }
        rmq_max.update(i, max_num[i]);
    }
    solve(1, n);
    dfs(1);
    puts("");
    return 0;
}