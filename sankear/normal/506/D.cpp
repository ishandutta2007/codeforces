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
#define all(s) (s).begin(), (s).end()
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
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
const int N = int(1e5) + 100;
const int K = 400;
const int MOD = (1 << 22);
const int X = int(2e5) + 3;

int step = 0, cur, sz = 0;
int used[N], big_num[N], col[N];
int ans[(2 * N) / K + 2][N];
vector<pii> edges[N];
set<int> cols[N];
vi g[N], lst[N];
pii from[2 * N];
int val[2 * N], next[2 * N];
int first[MOD];
vi big;

void dfs(int v) {
    used[v] = step;
    col[v] = cur;
    lst[cur].pb(v);
    for (int i = 0; i < sz(g[v]); ++i) {
        if (used[g[v][i]] != step) {
            dfs(g[v][i]);
        }
    }
}

inline void add(int a, int c, int b) {
    int need = (a * X + c) & (MOD - 1);
    pii cur(a, c);
    for (int i = first[need]; i > 0; i = next[i]) {
        if (from[i] == cur) {
            assert(val[i] == b);
            return;
        }
    }
    from[++sz] = cur;
    val[sz] = b;
    next[sz] = first[need];
    first[need] = sz;
}

inline int get(int a, int c) {
    int need = (a * X + c) & (MOD - 1);
    pii cur(a, c);
    for (int i = first[need]; i > 0; i = next[i]) {
        if (from[i] == cur) {
            return val[i];
        }
    }
    return -1;
}

int main() {
    cerr << (sizeof(ans) + sizeof(first)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    //cerr << (2 * N) / K << endl;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a;
        --b;
        --c;
        edges[c].pb(mp(a, b));
        cols[a].insert(c);
        cols[b].insert(c);
    }
    for (int i = 0; i < n; ++i) {
        if (sz(cols[i]) > K) {
            big_num[i] = sz(big);
            big.pb(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (sz(edges[i]) > 0) {
            ++step;
            for (int j = 0; j < sz(edges[i]); ++j) {
                g[edges[i][j].fs].clear();
                g[edges[i][j].sc].clear();
            }
            for (int j = 0; j < sz(edges[i]); ++j) {
                g[edges[i][j].fs].pb(edges[i][j].sc);
                g[edges[i][j].sc].pb(edges[i][j].fs);
            }
            cur = 0;
            for (int j = 0; j < sz(edges[i]); ++j) {
                if (used[edges[i][j].fs] != step) {
                    ++cur;
                    lst[cur].clear();
                    dfs(edges[i][j].fs);
                }
            }
            for (int j = 0; j < sz(big); ++j) {
                if (used[big[j]] == step) {
                    int cur = col[big[j]];
                    for (int z = 0; z < sz(lst[cur]); ++z) {
                        ++ans[j][lst[cur][z]];
                    }
                }
            }
            for (int j = 0; j < sz(edges[i]); ++j) {
                add(edges[i][j].fs, i, col[edges[i][j].fs]);
                add(edges[i][j].sc, i, col[edges[i][j].sc]);
            }
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int v, u;
        scanf("%d %d", &v, &u);
        --v;
        --u;
        if (sz(cols[v]) > sz(cols[u])) {
            swap(v, u);
        }
        if (sz(cols[v]) > K) {
            printf("%d\n", ans[big_num[v]][u]);
            continue;
        }
        int ans = 0;
        for (set<int>::iterator it = cols[v].begin(); it != cols[v].end(); ++it) {
            int pv = get(v, *it);
            if (pv == -1) {
                continue;
            }
            int pu = get(u, *it);
            if (pv == pu) {
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}