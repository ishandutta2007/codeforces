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
#include <complex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long double ldouble;

const int inf = 1e9 + 100;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 1010;

bool used[N];
double dp[N], sum[N], prob[N];
double p[N][N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &p[j][i]);
            p[j][i] /= 100.0;
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[i] = 1e100;
        prob[i] = 1.0;
    }
    dp[n - 1] = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        if (i == 0) {
            v = n - 1;
        } else {
            for (int j = 0; j < n; ++j) {
                if (!used[j]) {
                    if (fabs(prob[j] - 1.0) < eps) {
                        dp[j] = 1e100;
                    } else {
                        dp[j] = (sum[j] + prob[j]) / (1.0 - prob[j]);
                    }
                    if (v == -1 || dp[j] < dp[v]) {
                        v = j;
                    }
                }
            }
        }
        used[v] = true;
        if (dp[v] > 1e50) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (used[j]) {
                continue;
            }
            sum[j] += prob[j] * p[v][j] * (dp[v] + 1.0);
            prob[j] *= (1 - p[v][j]);
        }
    }
    printf("%.18lf\n", dp[0]);
    return 0;
}