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

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define LLD "%lld"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define LLD "%I64d"
#define eprintf(...)
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

const ll inf = ll(1e15);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 444;
const int K = 55;

int a[N];
ll s[N], max_dp0[N], max_dp1[N];
ll dp0[K][N], dp1[K][N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp0[1][i] = -inf;
        dp1[1][i] = -inf;
        for (int j = 1; j <= i; ++j) {
            dp0[1][i] = max(dp0[1][i], -(s[i] - s[j - 1]));
            dp1[1][i] = max(dp1[1][i], s[i] - s[j - 1]);
        }
    }
    for (int i = 2; i <= k; ++i) {
        max_dp0[0] = max_dp1[0] = -inf;
        for (int j = 1; j <= n; ++j) {
            max_dp0[j] = max(max_dp0[j - 1], dp0[i - 1][j]);
            max_dp1[j] = max(max_dp1[j - 1], dp1[i - 1][j]);
        }
        for (int j = 1; j <= n; ++j) {
            dp0[i][j] = dp1[i][j] = -inf;
            for (int z = 1; z <= j; ++z) {
                ll add = (i < k ? 1 : 0);
                dp0[i][j] = max(dp0[i][j], max(max_dp0[z - 1] + s[j] - s[z - 1], max_dp1[z - 1] - s[j] + s[z - 1]) + add * (- s[j] + s[z - 1]));
                dp1[i][j] = max(dp1[i][j], max(max_dp0[z - 1] + s[j] - s[z - 1], max_dp1[z - 1] - s[j] + s[z - 1]) + add * (s[j] - s[z - 1]));
            }
        }
    }
    ll ans = -inf;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp0[k][i]);
        ans = max(ans, dp1[k][i]);
    }
    cout << ans << endl;
    return 0;
}