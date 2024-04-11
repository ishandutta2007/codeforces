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
const int X1 = 4243;
const int MOD1 = int(1e9) + 7;
const int X2 = 10007;
const int MOD2 = 42424243;
const int N = int(1e5) + 100;

struct hash {
    
    int a, b;
    
    hash() {}
    
    hash(int a) : a(a), b(a) {}
    
    hash(int a, int b) : a(a), b(b) {}
    
};

hash operator * (const hash &a, const hash& b) {
    return hash((1LL * a.a * b.a) % MOD1, (1LL * a.b * b.b) % MOD2);
}

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

bool operator == (const hash& a, const hash& b) {
    return a.a == b.a && a.b == b.b;
}

const int MOD = (1 << 22);

struct hash_table {
    
    int sz;
    int first[MOD];
    hash val[N * 30];
    int next[N * 30];
    
    hash_table() {
        sz = 0;
    }
    
    bool add(const hash& h) {
        int need = (h.a * 200003 + h.b) & (MOD - 1);
        for (int i = first[need]; i > 0; i = next[i]) {
            if (val[i] == h) {
                return false;
            }
        }
        val[++sz] = h;
        next[sz] = first[need];
        first[need] = sz;
        return true;
    }
    
    bool contains(const hash& h) {
        int need = (h.a * 200003 + h.b) & (MOD - 1);
        for (int i = first[need]; i > 0; i = next[i]) {
            if (val[i] == h) {
                return true;
            }
        }
        return false;
    }
    
};

const hash X(X1, X2);

hash_table a, b;
char s[N], t[N];
hash p[N];

int main() {
    cerr << (sizeof(a) + sizeof(b)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d %s %s", &n, s, t);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * X;
    }
    hash left(0), right(0);
    for (int i = 0; i < n; ++i) {
        right = right + p[i] * s[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            hash cur = left + right * X + p[i] * ('a' + j);
            a.add(cur);
        }
        if (i < n) {
            left = left + p[i] * s[i];
            right = right - p[i] * s[i];
        }
    }
    left = 0;
    right = 0;
    for (int i = 0; i < n; ++i) {
        right = right + p[i] * t[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            hash cur = left + right * X + p[i] * ('a' + j);
            if (b.add(cur)) {
                if (a.contains(cur)) {
                    ++ans;
                }
            }
        }
        if (i < n) {
            left = left + p[i] * t[i];
            right = right - p[i] * t[i];
        }
    }
    cout << ans << endl;
    return 0;
}