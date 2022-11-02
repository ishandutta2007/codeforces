#include <iostream>
#include <unistd.h>
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
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) sz(s)
#define fs first
#define sc second
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
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

inline vi get(ll n) {
    if (n == 0) {
        return vi(1, 0);
    }
    vi res;
    while (n > 0) {
        res.pb(n % 2);
        n /= 2;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll s, x;
    cin >> s >> x;
    vi a = get(s), b = get(x);
    if (sz(b) > sz(a)) {
        puts("0");
        return 0;
    }
    while (sz(b) < sz(a)) {
        b.pb(0);
    }
    vector<vector<ll>> dp(sz(a) + 1, vector<ll>(2, 0));
    dp[0][0] = 1;
    for (int i = 0; i < sz(a); ++i) {
        for (int j = 0; j < 2; ++j) {
            if (dp[i][j] == 0) {
                continue;
            }
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    if ((x ^ y) != b[i]) {
                        continue;
                    }
                    int sum = j + x + y;
                    if (sum % 2 == a[i]) {
                        dp[i + 1][sum / 2] += dp[i][j];
                    }
                }
            }
        }
    }
    ll ans = dp[sz(a)][0];
    if (s == x) {
        assert(ans >= 2);
        ans -= 2;
    }
    cout << ans << endl;
    return 0;
}