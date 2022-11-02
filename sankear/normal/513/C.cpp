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
const int N = 5;
const int MAGIC = int(1e4);

int l[N], r[N];
double sum[(1 << N)][MAGIC + 10];

inline double get_sum(double* s, int l, int r) {
    return s[r] - (l > 0 ? s[l - 1] : 0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    double ans = 0;
    // 2 or more
    for (int c = 1; c <= MAGIC; ++c) {
        for (int i = 0; i < (1 << n); ++i) {
            int cnt = 0;
            double res = 1;
            for (int j = 0; j < n; ++j) {
                if (l[j] > c) {
                    res = 0;
                    break;
                }
                if ((i & (1 << j)) != 0) {
                    ++cnt;
                    if (r[j] < c) {
                        res = 0;
                        break;
                    }
                    res *= 1.0 / (r[j] - l[j] + 1);
                } else {
                    res *= double(min(c, r[j] + 1) - l[j]) / (r[j] - l[j] + 1);
                }
            }
            if (cnt >= 2) {
                ans += res * c;
            }
        }
    }
    // 1
    for (int i = 0; i < (1 << n); ++i) {
        for (int c = 1; c <= MAGIC; ++c) {
            sum[i][c] = sum[i][c - 1];
            double p = 1.0;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    if (l[j] > c) {
                        p = 0;
                        break;
                    }
                    p *= double(min(c, r[j] + 1) - l[j]) / (r[j] - l[j] + 1);
                }
            }
            sum[i][c] += p * c;
        }
    }
    for (int c = 1; c <= MAGIC; ++c) {
        for (int i = 0; i < n; ++i) {
            if (l[i] <= c && c <= r[i]) {
                for (int j = 1; j < (1 << n); ++j) {
                    if ((j & (1 << i)) != 0) {
                        continue;
                    }
                    int max_l = -inf, min_r = inf;
                    double res = 1.0 / (r[i] - l[i] + 1);
                    for (int z = 0; z < n; ++z) {
                        if ((j & (1 << z)) != 0) {
                            max_l = max(max_l, l[z]);
                            min_r = min(min_r, r[z]);
                            res *= 1.0 / (r[z] - l[z] + 1);
                        }
                    }
                    min_r = min(min_r, c - 1);
                    if (max_l <= min_r) {
                        ans += res * get_sum(sum[((1 << n) - 1) ^ j ^ (1 << i)], max_l, min_r);
                    }
                }
            }
        }
    }
    printf("%.18lf\n", ans);
    return 0;
}