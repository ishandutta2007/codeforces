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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int K = 31;
const int MOD = int(1e9) + 7;

int k = 0;

struct matr {
    
    int a[K][K];
    
    matr() {
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                a[i][j] = 0;
            }
            a[i][i] = 1;
        }
    }
    
};

matr operator * (const matr &a, const matr &b) {
    matr c;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            c.a[i][j] = 0;
            for (int z = 0; z <= k; ++z) {
                c.a[i][j] = (c.a[i][j] + 1LL * a.a[i][z] * b.a[z][j]) % MOD;
            }
        }
    }
    return c;
}

matr M[K], NM[K], suff[K], pref[K];

inline matr get(int num) {
    matr res;
    for (int i = 0; i <= k; ++i) {
        res.a[num][i] = 1;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    ll n;
    cin >> n >> k;
    vi v;
    while (n > 0) {
        v.pb(n % k);
        n /= k;
    }
    matr res;
    int shift = 0;
    for (int i = 0; i < sz(v); ++i) {
        shift += v[i];
    }
    for (int i = 0; i < k; ++i) {
        M[i] = matr();
        pref[i] = matr();
        suff[i] = matr();
    }
    for (int i = 0; i < sz(v); ++i) {
        shift -= v[i];
        for (int j = v[i] - 1; j >= 0; --j) {
            if (i == 0) {
                res = get((shift + j) % k) * res;
                continue;
            }
            res = M[(shift + j) % k] * res;
        }
        if (i == 0) {
            for (int i = 0; i < k; ++i) {
                M[i] = matr();
                for (int j = k - 1; j >= 0; --j) {
                    M[i] = get((i + j) % k) * M[i];
                }
            }
        } else {
            for (int i = 0; i < k; ++i) {
                M[i] = matr();
                if (i > 0) {
                    M[i] = pref[i - 1] * M[i];
                }
                M[i] = suff[i] * M[i];
            }
        }
        for (int i = 0; i < k; ++i) {
            pref[i] = (i > 0 ? pref[i - 1] : matr()) * M[i];
        }
        for (int i = k - 1; i >= 0; --i) {
            suff[i] = M[i] * (i + 1 < k ? suff[i + 1] : matr());
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = (ans + res.a[i][k]) % MOD;
    }
    cout << ans << endl;
    return 0;
}