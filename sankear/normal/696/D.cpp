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

const ll inf = 2 * ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 222;

int sz;
int link[N], pv[N], pc[N], a[N], ver[N], q[N];
char buf[N];
int next[N][26], go[N][26], sum[N];
ll dp[N][N], tmp[N][N], g[N][N];

inline void mult(ll a[N][N], ll b[N][N]) {
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            tmp[i][j] = -inf;
            for (int z = 0; z < sz; ++z) {
                if (a[i][z] == -inf || b[z][j] == -inf) {
                    continue;
                }
                tmp[i][j] = max(tmp[i][j], a[i][z] + b[z][j]);
            }
        }
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            a[i][j] = tmp[i][j];
        }
    }
}

inline void calc(ll n) {
    if (n == 1) {
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                dp[i][j] = g[i][j];
            }
        }
        return;
    }
    if (n % 2 == 0) {
        calc(n / 2);
        mult(dp, dp);
    } else {
        calc(n - 1);
        mult(dp, g);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    ll L;
    cin >> n >> L;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sz = 1;
    for (int i = 0; i < 26; ++i) {
        next[0][i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        int len = strlen(buf), cur = 0;
        for (int j = 0; j < len; ++j) {
            int c = buf[j] - 'a';
            if (next[cur][c] == -1) {
                for (int z = 0; z < 26; ++z) {
                    next[sz][z] = -1;
                }
                pv[sz] = cur;
                pc[sz] = c;
                next[cur][c] = sz++;
            }
            cur = next[cur][c];
        }
        ver[i] = cur;
        sum[cur] += a[i];
    }
    int l = 0, r = 1;
    q[0] = 0;
    while (l < r) {
        int v = q[l++];
        if (v == 0 || pv[v] == 0) {
            link[v] = 0;
        } else {
            link[v] = go[link[pv[v]]][pc[v]];
        }
        if (v > 0) {
            sum[v] += sum[link[v]];
        }
        for (int i = 0; i < 26; ++i) {
            if (next[v][i] != -1) {
                go[v][i] = next[v][i];
                q[r++] = next[v][i];
            } else {
                if (v == 0) {
                    go[v][i] = 0;
                } else {
                    go[v][i] = go[link[v]][i];
                }
            }
        }
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            g[i][j] = -inf;
        }
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < 26; ++j) {
            g[i][go[i][j]] = max(g[i][go[i][j]], 1LL * sum[go[i][j]]);
        }
    }
    calc(L);
    ll res = -inf;
    for (int i = 0; i < sz; ++i) {
        res = max(res, dp[0][i]);
    }
    cout << res << endl;
    return 0;
}