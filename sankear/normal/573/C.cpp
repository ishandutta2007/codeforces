#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <cstring>
#include <complex>
#undef NDEBUG
#include <cassert>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) sz(s)
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;

const int inf = int(1e9);
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = int(1e5) + 100;

int p[N];
vi g[N];
bool single[N], up[N];
bool can[N][3], can2[N][3];

inline bool check(int v) {
    if (single[v]) {
        return true;
    }
    if (sz(g[v]) == 2) {
        return single[g[v][0]] && single[g[v][1]];
    }
    return false;
}

void dfs(int v, int pv) {
    p[v] = pv;
    if (pv != -1) {
        g[v].erase(find(all(g[v]), pv));
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        dfs(g[v][i], v);
    }
    if (sz(g[v]) == 0) {
        can[v][1] = true;
        single[v] = true;
        return;
    }
    if (sz(g[v]) == 1) {
        single[v] = single[g[v][0]];
    }
    for (int i = 0; i <= sz(g[v]); ++i) {
        for (int j = 0; j <= 2; ++j) {
            can2[i][j] = false;
        }
    }
    can2[0][0] = true;
    for (int i = 0; i < sz(g[v]); ++i) {
        for (int j = 0; j <= 2; ++j) {
            if (!can2[i][j]) {
                continue;
            }
            // 0
            if (check(g[v][i])) {
                can2[i + 1][j] = true;
            }
            // 1
            if (j + 1 <= 2 && can[g[v][i]][1]) {
                can2[i + 1][j + 1] = true;
            }
        }
    }
    can[v][1] = can2[sz(g[v])][1];
    can[v][2] = can2[sz(g[v])][2];
}

void dfs2(int v, bool up) {
    ::up[v] = up;
    for (int i = 0; i < sz(g[v]); ++i) {
        bool nup = false;
        if (p[v] == -1) {
            if (sz(g[v]) == 2 && up) {
                if (i == 0 && single[g[v][1]]) {
                    nup = true;
                }
                if (i == 1 && single[g[v][0]]) {
                    nup = true;
                }
            }
        } else {
            if (up && sz(g[v]) == 1) {
                nup = true;
            }
        }
        dfs2(g[v][i], nup);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (sz(g[i]) > 1) {
            root = i;
            break;
        }
    }
    assert(root != -1);
    dfs(root, -1);
    dfs2(root, true);
    for (int i = 0; i < n; ++i) {
        if (can[i][1] || can[i][2]) {
            if (up[i]) {
                puts("Yes");
                return 0;
            }
            if (p[i] == root && sz(g[root]) == 3) {
                bool good = true;
                for (int j = 0; j < 3; ++j) {
                    if (g[root][j] != i && !single[g[root][j]]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    puts("Yes");
                    return 0;
                }
            }
            if (p[i] != -1 && sz(g[p[i]]) == 2 && up[p[i]]) {
                int num = 0;
                if (g[p[i]][num] == i) {
                    ++num;
                }
                if (single[g[p[i]][num]]) {
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    puts("No");
    return 0;
}