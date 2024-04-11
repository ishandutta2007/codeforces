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
const int N = 30;
const int M = 19;

#define count _count

int a[N];
ll f[M + 1];
unordered_map<ll, int> count[N];

inline void init() {
    f[0] = 1;
    for (int i = 1; i <= M; ++i) {
        f[i] = f[i - 1] * i;
    }
    cerr << "f[M] = " << f[M] << endl;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    int n, k;
    ll s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n < 2) {
        int ans = 0;
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = i; ; j = ((j - 1) & i)) {
                int cnt = 0;
                ll sum = 0;
                for (int z = 0; z < n && cnt <= k && sum <= s; ++z) {
                    if ((i & (1 << z)) == 0) {
                        continue;
                    }
                    if ((j & (1 << z)) != 0) {
                        ++cnt;
                        if (a[z] > M) {
                            sum = s + 1;
                        } else {
                            sum = min(sum + f[a[z]], s + 1);
                        }
                    } else {
                        sum = min(sum + a[z], s + 1);
                    }
                }
                if (cnt <= k && sum == s) {
                    ++ans;
                }
                if (j == 0) {
                    break;
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    int m = n / 2;
    for (int i = 0; i < (1 << (n - m)); ++i) {
        for (int j = i; ; j = ((j - 1) & i)) {
            int cnt = 0;
            ll sum = 0;
            for (int z = m; z < n && cnt <= k && sum <= s; ++z) {
                int num = z - m;
                if ((i & (1 << num)) == 0) {
                    continue;
                }
                if ((j & (1 << num)) != 0) {
                    ++cnt;
                    if (a[z] > M) {
                        sum = s + 1;
                    } else {
                        sum = min(sum + f[a[z]], s + 1);
                    }
                } else {
                    sum = min(sum + a[z], s + 1);
                }
            }
            if (cnt <= k && sum <= s) {
                ++count[cnt][sum];
            }
            if (j == 0) {
                break;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << m); ++i) {
        for (int j = i; ; j = ((j - 1) & i)) {
            int cnt = 0;
            ll sum = 0;
            for (int z = 0; z < m && cnt <= k && sum <= s; ++z) {
                if ((i & (1 << z)) == 0) {
                    continue;
                }
                if ((j & (1 << z)) != 0) {
                    ++cnt;
                    if (a[z] > M) {
                        sum = s + 1;
                    } else {
                        sum = min(sum + f[a[z]], s + 1);
                    }
                } else {
                    sum = min(sum + a[z], s + 1);
                }
            }
            if (cnt <= k && sum <= s) {
                for (int z = 0; z + cnt <= k; ++z) {
                    if (count[z].find(s - sum) != count[z].end()) {
                        ans += count[z][s - sum];
                    }
                }
            }
            if (j == 0) {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}