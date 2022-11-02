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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32 || _WIN64
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(2e5) + 100;
const int LOG = 20;

int maxv;
int pos[N], p[N], l[N];
int rmq[4 * N];
int go[LOG][N], sum[LOG][N];

inline int get_max(int l, int r) {
    int res = -inf;
    l += maxv;
    r += maxv;
    while (l <= r) {
        res = max(res, rmq[l]);
        l = (l + 1) / 2;
        res = max(res, rmq[r]);
        r = (r - 1) / 2;
    }
    return res;
}

inline void update(int v, int val) {
    v += maxv;
    rmq[v] = val;
    while (v > 1) {
        v /= 2;
        rmq[v] = max(rmq[v * 2], rmq[v * 2 + 1]);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p[i], &l[i]);
    }
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 1; i < 2 * maxv; ++i) {
        rmq[i] = -inf;
    }
    for (int i = n - 1; i >= 0; --i) {
        pos[i] = max(p[i] + l[i], get_max(i + 1, (int) (upper_bound(p, p + n, p[i] + l[i]) - p - 1)));
        update(i, pos[i]);
    }
    for (int i = 0; i < n; ++i) {
        int ni = (int) (upper_bound(p, p + n, pos[i]) - p);
        if (ni < n) {
            go[0][i] = ni;
            sum[0][i] = p[ni] - pos[i];
        } else {
            go[0][i] = -1;
        }
    }
    for (int i = 1; i < LOG; ++i) {
        for (int j = 0; j < n; ++j) {
            if (go[i - 1][j] == -1) {
                go[i][j] = -1;
                continue;
            }
            go[i][j] = go[i - 1][go[i - 1][j]];
            sum[i][j] = sum[i - 1][j] + sum[i - 1][go[i - 1][j]];
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        int ans = 0;
        for (int j = LOG - 1; j >= 0 && pos[x] < p[y]; --j) {
            int nx = go[j][x];
            if (nx == -1 || nx > y) {
                continue;
            }
            ans += sum[j][x];
            x = go[j][x];
        }
        printf("%d\n", ans);
    }
    return 0;
}