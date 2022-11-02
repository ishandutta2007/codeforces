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
const int N = int(1e6) + 100;

int a[N], next[N], cnt[N];
ll s[N];

inline ll get_sum(int l, int r) {
    return s[r] - (l > 0 ? s[l - 1] : 0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        s[i] = (i > 0 ? s[i - 1] : 0) + a[i];
    }
    for (int i = 0; i < q; ++i) {
        ll b;
        scanf(LLD, &b);
        int ptr = n;
        ll sum = 0;
        for (int j = n - 1; j >= 0; --j) {
            sum += a[j];
            while (sum > b) {
                sum -= a[--ptr];
            }
            if (ptr >= n) {
                next[j] = j;
                cnt[j] = 0;
            } else {
                next[j] = next[ptr];
                cnt[j] = cnt[ptr] + 1;
            }
        }
        int ans = inf;
        sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += a[j];
            if (sum > b) {
                break;
            }
            if (j == n - 1) {
                ans = min(ans, 1);
            } else {
                int pos = next[j + 1];
                if (get_sum(pos, n - 1) + sum <= b) {
                    ans = min(ans, cnt[j + 1] + 1);
                } else {
                    ans = min(ans, cnt[j + 1] + 2);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}