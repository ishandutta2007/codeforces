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
#define LLD "%lld"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define LLD "%I64d"
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
const int N = int(3e5) + 100;
const int LEN = int(6e5) + 100;
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

bool operator < (const hash& a, const hash& b) {
    if (a.a != b.a) {
        return a.a < b.a;
    }
    return a.b < b.b;
}

bool operator == (const hash& a, const hash& b) {
    return a.a == b.a && a.b == b.b;
}

hash operator * (const hash& a, const hash& b) {
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

const hash X(X1, X2);

hash dict[N];
hash pw[LEN], pref[LEN], suff[LEN];
char buf[LEN];

inline void init() {
    pw[0] = hash(1);
    for (int i = 1; i < LEN; ++i) {
        pw[i] = pw[i - 1] * X;
    }
}

int main() {
    //cerr << (sizeof(dict) + sizeof(pw) + sizeof(pref) + sizeof(suff)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        int len = (int) strlen(buf);
        hash cur(0);
        for (int j = 0; j < len; ++j) {
            cur = cur + pw[j] * buf[j];
        }
        dict[i] = cur;
    }
    sort(dict, dict + n);
    n = (int) (unique(dict, dict + n) - dict);
    for (int i = 0; i < m; ++i) {
        scanf("%s", buf);
        int len = (int) strlen(buf);
        for (int j = 0; j < len; ++j) {
            pref[j] = (j > 0 ? pref[j - 1] : hash(0)) + pw[j] * buf[j];
        }
        for (int j = len - 1; j >= 0; --j) {
            suff[j] = (j + 1 < len ? suff[j + 1] : hash(0)) + pw[j] * buf[j];
        }
        bool found = false;
        for (int j = 0; j < len && !found; ++j) {
            for (int z = 0; z < 3; ++z) {
                if (buf[j] - 'a' == z) {
                    continue;
                }
                hash cur = (j > 0 ? pref[j - 1] : hash(0)) + (j + 1 < len ? suff[j + 1] : hash(0)) + pw[j] * ('a' + z);
                int pos = (int) (lower_bound(dict, dict + n, cur) - dict);
                if (pos < n && dict[pos] == cur) {
                    found = true;
                    break;
                }
            }
        }
        puts((found ? "YES" : "NO"));
    }
    return 0;
}