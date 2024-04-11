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

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;

int n;
int a[N], b[N], sz[N], dp[N], dp2[N];
vi g[N];

void dfs(int v, int pv) {
    if (pv != -1) {
        g[v].erase(find(all(g[v]), pv));
    }
    sz[v] = 1;
    for (int u : g[v]) {
        dfs(u, v);
        sz[v] += sz[u];
    }
}

void dfs2(int v) {
    for (int u : g[v]) {
        dfs2(u);
    }
    if (b[v] == 0) {
        dp[v] = 0;
    } else {
        dp[v] = 1;
        int max_add = 0;
        for (int u : g[v]) {
            if (dp[u] == sz[u]) {
                dp[v] += dp[u];
            } else {
                max_add = max(max_add, dp[u]);
            }
        }
        dp[v] += max_add;
    }
}

void dfs3(int v) {
    if (b[v] == 0) {
        for (int u : g[v]) {
            dp2[u] = 0;
            dfs3(u);
        }
        return;
    }
    pii max1(0, -1), max2(0, -1);
    int sum = 0;
    for (int u : g[v]) {
        if (dp[u] == sz[u]) {
            sum += dp[u];
        } else if (dp[u] > max1.fs) {
            max2 = max1;
            max1 = mp(dp[u], u);
        } else {
            max2 = max(max2, mp(dp[u], u));
        }
    }
    if (dp2[v] == n - sz[v]) {
        sum += dp2[v];
    } else if (dp2[v] > max1.fs) {
        max2 = max1;
        max1 = mp(dp2[v], v);
    } else {
        max2 = max(max2, mp(dp2[v], v));
    }
    for (int u : g[v]) {
        if (dp[u] == sz[u]) {
            dp2[u] = 1 + (sum - dp[u]) + max1.fs;
        } else if (u == max1.sc) {
            dp2[u] = 1 + sum + max2.fs;
        } else {
            dp2[u] = 1 + sum + max1.fs;
        }
        dfs3(u);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    int ans = -1, l = 1, r = int(1e6);
    while (l <= r) {
        int mid = (l + r) / 2;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= mid) {
                b[i] = 1;
            } else {
                b[i] = 0;
            }
        }
        dfs2(0);
        dp2[0] = 0;
        dfs3(0);
        bool fl = false;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0) {
                continue;
            }
            int sum = 1, max_add = 0;
            for (int j : g[i]) {
                if (dp[j] == sz[j]) {
                    sum += dp[j];
                } else {
                    max_add = max(max_add, dp[j]);
                }
            }
            if (dp2[i] == n - sz[i]) {
                sum += dp2[i];
            } else {
                max_add = max(max_add, dp2[i]);
            }
            if (sum + max_add >= k) {
                fl = true;
                break;
            }
        }
        if (fl) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}