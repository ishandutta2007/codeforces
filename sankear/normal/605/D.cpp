#include <iostream>
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
#include <complex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
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
typedef long double ldouble;

const int inf = 1e9 + 100;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;

int maxv;
int a[N], b[N], c[N], d[N], link[N];
int dp[N], prev[N], q[N];
pair<int, pii> e[N];
pii rmq[4 * N];
vi lst;

inline void calc(int v) {
    rmq[v] = min(rmq[v * 2], rmq[v * 2 + 1]);
}

inline void del(int pos) {
    pos += maxv;
    rmq[pos] = mp(inf, -1);
    while (pos > 1) {
        pos /= 2;
        calc(pos);
    }
}

inline pii get(int l, int r) {
    pii res(inf, -1);
    l += maxv;
    r += maxv;
    while (l <= r) {
        res = min(res, rmq[l]);
        l = (l + 1) / 2;
        res = min(res, rmq[r]);
        r = (r - 1) / 2;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    a[0] = b[0] = c[0] = d[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
    }
    for (int i = 0; i <= n; ++i) {
        e[i] = mp(a[i], mp(b[i], i));
    }
    sort(e, e + n + 1);
    for (int i = 0; i <= n; ++i) {
        link[e[i].sc.sc] = i;
    }
    maxv = 1;
    while (maxv < n + 1) {
        maxv *= 2;
    }
    for (int i = 0; i <= n; ++i) {
        rmq[i + maxv] = e[i].sc;
    }
    for (int i = n + 1; i < maxv; ++i) {
        rmq[i + maxv] = mp(inf, -1);
    }
    for (int i = maxv - 1; i > 0; --i) {
        calc(i);
    }
    for (int i = 0; i <= n; ++i) {
        dp[i] = inf;
    }
    dp[0] = 0;
    int l = 0, r = 1;
    q[0] = 0;
    while (l < r) {
        int v = q[l++];
        int pos = lower_bound(e, e + n + 1, mp(c[v] + 1, mp(-inf, -1))) - e;
        for (;;) {
            pii cur = get(0, pos - 1);
            if (cur.fs > d[v]) {
                break;
            }
            del(link[cur.sc]);
            if (dp[cur.sc] > dp[v] + 1) {
                dp[cur.sc] = dp[v] + 1;
                prev[cur.sc] = v;
                q[r++] = cur.sc;
            }
        }
    }
    if (dp[n] == inf) {
        puts("-1");
        return 0;
    }
    int cur = n;
    while (cur > 0) {
        lst.pb(cur);
        cur = prev[cur];
    }
    reverse(all(lst));
    cout << sz(lst) << endl;
    for (int i = 0; i < sz(lst); ++i) {
        printf("%d ", lst[i]);
    }
    puts("");
    return 0;
}