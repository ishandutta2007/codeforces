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
const int X1 = 4243;
const int MOD1 = int(1e9) + 7;
const int X2 = 10007;
const int MOD2 = 42424243;

struct hash {
    
    int a, b;
    
    hash() {}
    
    hash(int a) : a(a), b(a) {}
    
    hash(int a, int b) : a(a), b(b) {}
    
};

hash operator + (const hash& a, const hash& b) {
    hash c(a.a + b.a, a.b + b.b);
    if (c.a >= MOD1) {
        c.a -= MOD1;
    }
    if (c.b >= MOD2) {
        c.b -= MOD2;
    }
    return c;
}

hash operator - (const hash& a, const hash& b) {
    hash c(a.a - b.a, a.b - b.b);
    if (c.a < 0) {
        c.a += MOD1;
    }
    if (c.b < 0) {
        c.b += MOD2;
    }
    return c;
}

hash operator * (const hash& a, const hash& b) {
    return hash((1LL * a.a * b.a) % MOD1, (1LL * a.b * b.b) % MOD2);
}

bool operator == (const hash& a, const hash& b) {
    return a.a == b.a && a.b == b.b;
}

const hash X(X1, X2);

char s[N];
hash h[N], p[N];
int len[N];

inline hash get_hash(int l, int r, int n) {
    if (l > r) {
        return 0;
    }
    return (h[r] - (l > 0 ? h[l - 1] : 0)) * p[n - l];
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    scanf("%s", s);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * X;
    }
    for (int i = 0; i < n; ++i) {
        h[i] = (i > 0 ? h[i - 1] : 0) + p[i] * s[i];
    }
    for (int i = 0; i < n; ++i) {
        len[i] = -inf;
    }
    for (int i = 1; i * k <= n; ++i) {
        if (get_hash(0, i * (k - 1) - 1, n) == get_hash(i, i * k - 1, n)) {
            int j = (k - 1) * i;
                    int res = 0, l = 1, r = min(n - (j + i), i);
                    while (l <= r) {
                        int mid = (l + r) / 2;
                        if (get_hash(0, mid - 1, n) == get_hash(j + i, j + i + mid - 1, n)) {
                            res = mid;
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                    len[j + i - 1] = max(len[j + i - 1], j + i - 1 + res);
        }
    }
    int max_len = -inf;
    for (int i = 0; i < n; ++i) {
        max_len = max(max_len, len[i]);
        if (max_len >= i) {
            printf("1");
        } else {
            printf("0");
        }
    }
    puts("");
    return 0;
}