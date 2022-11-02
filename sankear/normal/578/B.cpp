#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pbk pop_back
#define all(x) (x).begin(), (x).end()
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define prev _prev
#define next _next
#define rank _rank
#define hash _hash

#ifdef _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int inf = 2e4;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = int(2e5) + 100;

ll a[N], pref[N], suff[N + 1];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        scanf(LLD, a + i);
        pref[i] = (i > 0 ? pref[i - 1] : 0) | a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = (i + 1 < n ? suff[i + 1] : 0) | a[i];
    }
    ll ans = -1;
    for (int i = 0; i < n; ++i) {
        ll cur = a[i];
        for (int j = 0; j <= k; ++j) {
            ll res = cur;
            if (i > 0) {
                res |= pref[i - 1];
            }
            if (i + 1 < n) {
                res |= suff[i + 1];
            }
            ans = max(ans, res);
            cur *= x;
        }
    }
    cout << ans << endl;
    return 0;
}