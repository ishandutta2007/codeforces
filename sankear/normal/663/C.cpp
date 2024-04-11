#pragma comment(linker, "/STACK:256000000")

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
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
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
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;

const char chars[2] = { 'B', 'R' };

bool fl;
int a[N], b[N], prev[N], sz[N], col[N];
char c[N];
bool used[N];
vi g[N];
vi lst, comp[2];
int sum[2];

int get(int a) {
    if (prev[a] != a) {
        prev[a] = get(prev[a]);
    }
    return prev[a];
}

inline void merge(int a, int b) {
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    sz[a] += sz[b];
    prev[b] = a;
}

void dfs(int v, int c) {
    comp[c].pb(v);
    sum[c] += sz[v];
    col[v] = c;
    for (int u : g[v]) {
        if (col[u] == -1) {
            dfs(u, 1 - c);
        } else if (col[u] != 1 - c) {
            fl = false;
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", a + i, b + i, c + i);
        --a[i];
        --b[i];
    }
    int ans = inf;
    for (int it = 0; it < 2; ++it) {
        char need = chars[it];
        for (int i = 0; i < n; ++i) {
            prev[i] = i;
            sz[i] = 1;
            g[i].clear();
            col[i] = -1;
            used[i] = false;
        }
        for (int i = 0; i < m; ++i) {
            if (c[i] == need) {
                int x = get(a[i]), y = get(b[i]);
                if (x != y) {
                    merge(x, y);
                }
            }
        }
        fl = true;
        for (int i = 0; i < m; ++i) {
            if (c[i] != need) {
                int x = get(a[i]), y = get(b[i]);
                if (x == y) {
                    fl = false;
                }
                g[x].pb(y);
                g[y].pb(x);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (get(i) == i && col[i] == -1) {
                comp[0].clear();
                comp[1].clear();
                sum[0] = sum[1] = 0;
                dfs(i, 0);
                if (sum[0] < sum[1]) {
                    for (int cmp : comp[0]) {
                        used[cmp] = true;
                    }
                } else {
                    for (int cmp : comp[1]) {
                        used[cmp] = true;
                    }
                }
            }
        }
        if (!fl) {
            continue;
        }
        vi res;
        for (int i = 0; i < n; ++i) {
            if (used[get(i)]) {
                res.pb(i);
            }
        }
        if (sz(res) < ans) {
            ans = sz(res);
            lst = res;
        }
    }
    if (ans == inf) {
        puts("-1");
        return 0;
    }
    printf("%d\n", ans);
    for (int v : lst) {
        printf("%d ", v + 1);
    }
    puts("");
    return 0;
}