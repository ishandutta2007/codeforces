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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
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

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 5050;

unordered_map<int, int> dp;
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
        for (int j = 1; j <= k; ++j) {
            int val = a[i] * j;
            if (dp.find(val) == dp.end()) {
                dp[val] = j;
            } else {
                dp[val] = min(dp[val], j);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        int res = inf;
        for (int j = 0; j < n; ++j) {
            for (int z = 1; z <= k && a[j] * z <= x; ++z) {
                if (a[j] * z == x) {
                    res = min(res, z);
                } else {
                    int need = x - a[j] * z;
                    if (dp.find(need) != dp.end()) {
                        res = min(res, z + dp[need]);
                    }
                }
            }
        }
        if (res > k) {
            puts("-1");
        } else {
            printf("%d\n", res);
        }
    }
    return 0;
}