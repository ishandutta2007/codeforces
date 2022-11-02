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
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1e18;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e6) + 100;

set<int> primes;
int c[N];
ll pref[N], suff[N];

inline void add_primes(int n) {
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (n % i == 0) {
            primes.insert(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        primes.insert(n);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    ll a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", c + i);
    }
    for (int i = -1; i <= 1; ++i) {
        add_primes(c[1] + i);
        add_primes(c[n] + i);
    }
    ll ans = inf;
    for (int p : primes) {
        for (int i = 1; i <= n; ++i) {
            if (c[i] % p == 0) {
                pref[i] = pref[i - 1];
            } else if ((c[i] - 1) % p == 0 || (c[i] + 1) % p == 0) {
                pref[i] = min(pref[i - 1] + b, inf);
            } else {
                pref[i] = inf;
            }
        }
        for (int i = n; i > 0; --i) {
            if (c[i] % p == 0) {
                suff[i] = suff[i + 1];
            } else if ((c[i] - 1) % p == 0 || (c[i] + 1) % p == 0) {
                suff[i] = min(suff[i + 1] + b, inf);
            } else {
                suff[i] = inf;
            }
        }
        ll best = pref[0] - a;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, i * a + suff[i] + best);
            best = min(best, pref[i] - (i + 1) * a);
        }
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, pref[i] + (n - i) * a);
        }
    }
    cout << ans << endl;
    return 0;
}