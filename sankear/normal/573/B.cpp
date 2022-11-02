#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <cstring>
#include <complex>
#undef NDEBUG
#include <cassert>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) sz(s)
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;

const int inf = int(1e9);
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = int(1e5) + 100;

int a[N], res[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        res[i] = min(i, n - i - 1);
    }
    int val = inf;
    for (int i = 0; i < n; ++i) {
        val = min(val, a[i] - 1 - i);
        res[i] = min(res[i], i + val);
    }
    val = inf;
    for (int i = n - 1; i >= 0; --i) {
        val = min(val, i + a[i] - 1);
        res[i] = min(res[i], val - i);
    }
    for (int i = 0; i < n; ++i) {
        ans = max(ans, res[i]);
    }
    cout << ans + 1 << endl;
    return 0;
}