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
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
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
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 1010;
const int M = 25;
const int MOD = int(1e9) + 7;

int sz;
char s[N];
int pv[N * M], pc[N * M], link[N * M], q[N * M], len[N * M];
int next[N * M][10], go[N * M][10];
int dp[N * M][M + 1][2], ndp[N * M][M + 1][2];

inline void build() {
    scanf("%s", s);
    int n = strlen(s);
    sz = 1;
    for (int i = 0; i < 10; ++i) {
        next[0][i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < M && i + j < n; ++j) {
            if (next[cur][s[i + j] - '0'] == -1) {
                for (int z = 0; z < 10; ++z) {
                    next[sz][z] = -1;
                }
                pv[sz] = cur;
                pc[sz] = s[i + j] - '0';
                len[sz] = len[cur] + 1;
                next[cur][s[i + j] - '0'] = sz++;
            }
            cur = next[cur][s[i + j] - '0'];
        }
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
        for (int i = 0; i < 10; ++i) {
            if (next[v][i] != -1) {
                go[v][i] = next[v][i];
            } else {
                go[v][i] = go[link[v]][i];
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (next[v][i] != -1) {
                q[r++] = next[v][i];
            }
        }
    }
}

inline int calc() {
    scanf("%s", s);
    int n = strlen(s);
    assert(n / 2 <= M);
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j <= n / 2; ++j) {
            for (int z = 0; z < 2; ++z) {
                dp[i][j][z] = 0;
            }
        }
    }
    dp[0][0][1] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz; ++j) {
            for (int z = 0; z <= n / 2; ++z) {
                for (int h = 0; h < 2; ++h) {
                    ndp[j][z][h] = 0;
                }
            }
        }
        for (int j = 0; j < sz; ++j) {
            for (int z = 0; z <= n / 2; ++z) {
                for (int h = 0; h < 2; ++h) {
                    if (dp[j][z][h] == 0) {
                        continue;
                    }
                    for (int c = (i == 0 ? 1 : 0); c <= (h ? s[i] - '0' : 9); ++c) {
                        int nj = go[j][c];
                        int nz = max(z, len[nj]);
                        if (nz > n / 2) {
                            nz = n / 2;
                        }
                        int nh = h;
                        if (h && c < s[i] - '0') {
                            nh = 0;
                        }
                        ndp[nj][nz][nh] += dp[j][z][h];
                        if (ndp[nj][nz][nh] >= MOD) {
                            ndp[nj][nz][nh] -= MOD;
                        }
                    }
                }
            }
        }
        for (int j = 0; j < sz; ++j) {
            for (int z = 0; z <= n / 2; ++z) {
                for (int h = 0; h < 2; ++h) {
                    dp[j][z][h] = ndp[j][z][h];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < sz; ++i) {
        ans = (ans + dp[i][n / 2][0]) % MOD;
        ans = (ans + dp[i][n / 2][1]) % MOD;
    }
    return ans;
}

inline bool check() {
    int n = strlen(s), cur = 0, max_len = 0;
    for (int i = 0; i < n; ++i) {
        cur = go[cur][s[i] - '0'];
        max_len = max(max_len, len[cur]);
    }
    if (max_len >= n / 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cerr << (sizeof(dp) + sizeof(ndp)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    build();
    int ans = (MOD - calc()) % MOD;
    if (check()) {
        ans = (ans + 1) % MOD;
    }
    ans = (ans + calc()) % MOD;
    cout << ans << endl;
    return 0;
}