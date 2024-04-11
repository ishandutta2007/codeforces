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
const int N = 1111;

int q[N], d[N], col[N];
vi g[N];
vi lst;

inline void fail() {
    puts("-1");
    exit(0);
}

void dfs(int v, int c) {
    col[v] = c;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (col[g[v][i]] == -1) {
            dfs(g[v][i], 1 - c);
        } else if (col[g[v][i]] != 1 - c) {
            fail();
        }
    }
}

void dfs2(int v) {
    col[v] = 1;
    lst.pb(v);
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!col[g[v][i]]) {
            dfs2(g[v][i]);
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
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; ++i) {
        col[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            dfs(i, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        col[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!col[i]) {
            lst.clear();
            dfs2(i);
            int res = 0;
            for (int j = 0; j < sz(lst); ++j) {
                for (int z = 0; z < sz(lst); ++z) {
                    d[lst[z]] = inf;
                }
                d[lst[j]] = 0;
                int l = 0, r = 1;
                q[0] = lst[j];
                while (l < r) {
                    int v = q[l++];
                    for (int z = 0; z < sz(g[v]); ++z) {
                        if (d[g[v][z]] > d[v] + 1) {
                            d[g[v][z]] = d[v] + 1;
                            q[r++] = g[v][z];
                        }
                    }
                }
                for (int z = 0; z < sz(lst); ++z) {
                    res = max(res, d[lst[z]]);
                }
            }
            ans += res;
        }
    }
    cout << ans << endl;
    return 0;
}