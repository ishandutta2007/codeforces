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
const int N = int(2e5) + 100;

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

const hash X(X1, X2);

int m;
char s[N], t[N];
hash ss[30][N], st[30];
bool used[30];
hash p[N];
vi ans;

inline hash get_sum(hash* h, int l, int r) {
    return h[r] - (l > 0 ? h[l - 1] : 0);
}

inline bool check(int pos, int a, int b) {
    return get_sum(ss[a], pos, pos + m - 1) == st[b] * p[pos] && get_sum(ss[b], pos, pos + m - 1) == st[a] * p[pos];
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d %d %s %s", &n, &m, s, t);
    p[0] = 1;
    for (int i = 1; i < n; ++i) {
        p[i] = p[i - 1] * X;
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < n; ++j) {
            ss[i][j] = (j > 0 ? ss[i][j - 1] : 0) + (s[j] == 'a' + i ? p[j] : 0);
        }
    }
    for (int i = 0; i < 26; ++i) {
        st[i] = 0;
        for (int j = 0; j < m; ++j) {
            if (t[j] == 'a' + i) {
                st[i] = st[i] + p[j];
            }
        }
    }
    for (int i = 0; i + m - 1 < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            used[j] = false;
        }
        int cnt = 26;
        for (int j = 0; j < 26; ++j) {
            if (check(i, j, j)) {
                used[j] = true;
                --cnt;
            }
        }
        if (cnt % 2 != 0) {
            continue;
        }
        bool good = true;
        for (int j = 0; j < 26; ++j) {
            if (used[j]) {
                continue;
            }
            for (int z = j + 1; z < 26; ++z) {
                if (!used[z] && check(i, j, z)) {
                    used[j] = used[z] = true;
                    break;
                }
            }
            if (!used[j]) {
                good = false;
                break;
            }
        }
        if (good) {
            ans.pb(i);
        }
    }
    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); ++i) {
        printf("%d ", ans[i] + 1);
    }
    puts("");
    return 0;
}