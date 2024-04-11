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

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 33;
const int K = 222;

double dp[K][N][N][2];
int a[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dp[0][i][j][(a[i] > a[j])] = 1.0;
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            for (int z = j + 1; z < n; ++z) {
                for (int h = 0; h < 2; ++h) {
                    if (dp[i][j][z][h] < eps) {
                        continue;
                    }
                    for (int l = 0; l < n; ++l) {
                        for (int r = l; r < n; ++r) {
                            if (l <= j && j <= r && l <= z && z <= r) {
                                int nj = r - (j - l);
                                int nz = r - (z - l);
                                dp[i + 1][nz][nj][1 - h] += dp[i][j][z][h] / (n * (n + 1) / 2);
                                continue;
                            }
                            if (l <= j && j <= r) {
                                int nj = r - (j - l);
                                dp[i + 1][nj][z][h] += dp[i][j][z][h] / (n * (n + 1) / 2);
                                continue;
                            }
                            if (l <= z && z <= r) {
                                int nz = r - (z - l);
                                dp[i + 1][j][nz][h] += dp[i][j][z][h] / (n * (n + 1) / 2);
                                continue;
                            }
                            dp[i + 1][j][z][h] += dp[i][j][z][h] / (n * (n + 1) / 2);
                        }
                    }
                }
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans += dp[k][i][j][1];
        }
    }
    printf("%.18lf\n", ans);
    return 0;
}