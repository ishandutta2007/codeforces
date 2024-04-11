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

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;

int pos[N], dp[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        --cur;
        pos[cur] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = 1;
        if (i + 1 < n && pos[i] < pos[i + 1]) {
            dp[i] = dp[i + 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i]);
    }
    ans = n - ans;
    cout << ans << endl;
    return 0;
}