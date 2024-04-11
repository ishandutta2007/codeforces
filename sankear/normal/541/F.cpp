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
const int T = 111;
const int N = 1111;

vi lst[T];
vector<vi> dp[T];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        int h, q;
        scanf("%d %d", &h, &q);
        h = t - h;
        lst[h].pb(q);
    }
    for (int i = 0; i <= t; ++i) {
        dp[i].resize(sz(lst[i]) + 1);
        for (int j = 0; j <= sz(lst[i]); ++j) {
            dp[i][j].resize(2 * n + 1);
            for (int z = 0; z <= 2 * n; ++z) {
                dp[i][j][z] = -inf;
            }
        }
    }
    dp[0][0][1] = 0;
    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j < sz(lst[i]); ++j) {
            for (int z = 0; z <= 2 * n; ++z) {
                dp[i][j + 1][z] = max(dp[i][j + 1][z], dp[i][j][z]);
                if (z > 0) {
                    dp[i][j + 1][z - 1] = max(dp[i][j + 1][z - 1], dp[i][j][z] + lst[i][j]);
                }
            }
        }
        if (i + 1 <= t) {
            for (int j = 0; j <= 2 * n; ++j) {
                dp[i + 1][0][min(j * 2, 2 * n)] = max(dp[i + 1][0][min(j * 2, 2 * n)], dp[i][sz(lst[i])][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n; ++i) {
        ans = max(ans, dp[t][sz(lst[t])][i]);
    }
    cout << ans << endl;
    return 0;
}