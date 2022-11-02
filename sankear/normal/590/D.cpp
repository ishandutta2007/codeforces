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
const int N = 155;

int a[N];
int dp[N][N * N], ndp[N][N * N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k, s;
    cin >> n >> k >> s;
    s = min(s, n * (n - 1) / 2);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= min(i + 1, k); ++j) {
            for (int z = 0; z <= min(s, j * (n - 1)); ++z) {
                ndp[j][z] = inf;
            }
        }
        for (int j = 0; j <= min(i, k); ++j) {
            for (int z = 0; z <= min(s, j * (n - 1)); ++z) {
                ndp[j][z] = min(ndp[j][z], dp[j][z]);
                if (j + 1 <= k) {
                    ndp[j + 1][z + i - j] = min(ndp[j + 1][z + i - j], dp[j][z] + a[i]);
                }
            }
        }
        for (int j = 0; j <= min(i + 1, k); ++j) {
            for (int z = 0; z <= min(s, j * (n - 1)); ++z) {
                dp[j][z] = ndp[j][z];
            }
        }
    }
    int ans = inf;
    for (int i = 0; i <= min(s, k * (n - 1)); ++i) {
        ans = min(ans, dp[k][i]);
    }
    cout << ans << endl;
    return 0;
}