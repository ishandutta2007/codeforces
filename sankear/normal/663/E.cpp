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
const int N = 20;
const int M = int(1e5) + 100;

int dp[(1 << N)][2 * N + 1];
char a[N][M];

inline int set_pos(int msk, int pos, int val) {
    if (val == 1) {
        return msk | (1 << pos);
    } else if ((msk & (1 << pos)) != 0) {
        return msk ^ (1 << pos);
    } else {
        return msk;
    }
}

int main() {
    cerr << sizeof(dp) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    /*int tmp[(1 << n)];
    for (int i = 0; i < (1 << n); ++i) {
        tmp[i] = 0;
        for (int j = 0; j < m; ++j) {
            int c0 = 0, c1 = 0;
            for (int z = 0; z < n; ++z) {
                int val = a[z][j] - '0';
                if ((i & (1 << z)) != 0) {
                    val ^= 1;
                }
                if (val == 0) {
                    ++c0;
                } else {
                    ++c1;
                }
            }
            tmp[i] += min(c0, c1);
        }
    }*/
    for (int i = 0; i < m; ++i) {
        int msk = 0, c0 = 0, c1 = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] == '0') {
                ++c0;
            } else {
                ++c1;
                msk |= (1 << j);
            }
        }
        for (int diff = -n; diff <= n; ++diff) {
            if (2 * diff <= c1 - c0) {
                dp[msk][diff + n] += c0 + diff;
            } else {
                dp[msk][diff + n] += c1 - diff;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int msk = 0; msk < (1 << n); ++msk) {
            if ((msk & (1 << i)) != 0) {
                continue;
            }
            static int tmp[2][2 * N + 1];
            memset(tmp, 0, sizeof(tmp));
            for (int diff = -n; diff <= n; ++diff) {
                    for (int val = 0; val < 2; ++val) {
                        int ndiff = diff + val;
                        if (ndiff <= n) {
                            tmp[val][ndiff + n] += dp[msk][diff + n];
                        }
                        ndiff = diff - val;
                        if (ndiff >= -n) {
                            tmp[val][ndiff + n] += dp[msk | (1 << i)][diff + n];
                        }
                    }
            }
            for (int val = 0; val < 2; ++val) {
                for (int diff = -n; diff <= n; ++diff) {
                    dp[msk | (val << i)][diff + n] = tmp[val][diff + n];
                }
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < (1 << n); ++i) {
        //eprintf("%d %d %d\n", i, tmp[i], dp[cur][i][0 + n]);
        ans = min(ans, dp[i][0 + n]);
    }
    cout << ans << endl;
    return 0;
}