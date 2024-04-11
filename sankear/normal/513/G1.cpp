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
const int K = 10;

map<vi, double> dp[K];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vi cur(n);
    for (int i = 0; i < n; ++i) {
        cin >> cur[i];
    }
    dp[0][cur] = 1.0;
    for (int i = 0; i < k; ++i) {
        for (auto st : dp[i]) {
            cur = st.fs;
            for (int l = 0; l < n; ++l) {
                for (int r = l; r < n; ++r) {
                    reverse(cur.begin() + l, cur.begin() + r + 1);
                    dp[i + 1][cur] += st.sc / (n * (n + 1) / 2);
                    reverse(cur.begin() + l, cur.begin() + r + 1);
                }
            }
        }
    }
    double ans = 0;
    for (auto st : dp[k]) {
        cur = st.fs;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (cur[i] > cur[j]) {
                    ++res;
                }
            }
        }
        ans += res * st.sc;
    }
    printf("%.18lf\n", ans);
    return 0;
}