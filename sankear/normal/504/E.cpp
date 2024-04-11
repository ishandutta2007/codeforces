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
#define all(s) (s).begin(), (s).end()
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
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
const double eps = 1e-4;
const double pi = 4 * atan(double(1));
const int LOG = 19;
const int N = int(3e5) + 100;
const int M = int(1e6) + 100;
const int X = 4243;
const int MOD = int(1e9) + 7;

struct hash {
    
    int a;
    
    hash() {}
    
    hash(int a) : a(a) {}
    
};

hash operator + (const hash &a, const hash &b) {
    hash c(a.a + b.a);
    if (c.a >= MOD) {
        c.a -= MOD;
    }
    return c;
}

hash operator - (const hash &a, const hash &b) {
    hash c(a.a - b.a);
    if (c.a < 0) {
        c.a += MOD;
    }
    return c;
}

hash operator * (const hash &a, const hash &b) {
    return hash((1LL * a.a * b.a) % MOD);
}

bool operator == (const hash &a, const hash &b) {
    return a.a == b.a;
}

struct tq {
    
    int a, b, ab, c, d, cd;
    
};

int n, shift, sz;
bool used[N];
char s[N];
int prev[N], rank[N], val[N], h[N], p[N];
hash pw[2 * N], sum[N], rev_sum[N];
int last_bit[10 * N];
vector<pair<int, int*> > lca[N];
tq q[M];
int* ptr[N][LOG];
vi g[N];

int get(int a) {
    if (prev[a] != a) {
        prev[a] = get(prev[a]);
    }
    return prev[a];
}

inline void merge(int a, int b, int c) {
    a = get(a);
    b = get(b);
    if (rank[a] < rank[b]) {
        swap(a, b);
    }
    prev[b] = a;
    if (rank[a] == rank[b]) {
        ++rank[a];
    }
    val[a] = c;
}

void dfs(int v, int pv) {
    // add
    if (pv != -1) {
        for (int i = 0; i < LOG; ++i) {
            ptr[v][i] = ptr[pv][i];
        }
    } else {
        for (int i = 0; i < LOG; ++i) {
            ptr[v][i] = NULL;
        }
    }
    if ((sz & 1) == 0) {
        ptr[v][0] = new int[1];
        ptr[v][0][0] = v;
    } else {
        int _ptr = 0;
        while (_ptr + 1 < LOG && (sz & (1 << (_ptr + 1))) != 0) {
            ++_ptr;
        }
        ptr[v][_ptr + 1] = new int[(1 << (_ptr + 1))];
        int p = 0;
        for (int i = _ptr; i >= 0; --i) {
            for (int j = 0; j < (1 << i); ++j) {
                ptr[v][_ptr + 1][p++] = ptr[v][i][j];
            }
            ptr[v][i] = NULL;
        }
        ptr[v][_ptr + 1][p++] = v;
    }
    ++sz;
    // process
    used[v] = true;
    p[v] = pv;
    if (pv == -1) {
        h[v] = 0;
        sum[v] = pw[0] * hash(s[v]);
        rev_sum[v] = pw[n] * hash(s[v]);
    } else {
        g[v].erase(find(all(g[v]), pv));
        h[v] = h[pv] + 1;
        sum[v] = sum[pv] + pw[h[v]] * hash(s[v]);
        rev_sum[v] = rev_sum[pv] + pw[n - h[v]] * hash(s[v]);
    }
    for (int i = 0; i < sz(lca[v]); ++i) {
        if (used[lca[v][i].fs]) {
            *(lca[v][i].sc) = val[get(lca[v][i].fs)];
        }
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        dfs(g[v][i], v);
        merge(v, g[v][i], v);
    }
    // del
    --sz;
}

inline int len(int a, int b, int ab) {
    return h[a] + h[b] - 2 * h[ab] + 1;
}

inline int get_ver(int v, int len) {
    int sz = h[v] + 1 + shift;
    int bit = last_bit[sz ^ (sz - len)];
    len -= (sz & ((1 << bit) - 1));
    return ptr[v][bit][(1 << bit) - len];
}

inline hash get_rev_sum(int v, int pv) {
    return (rev_sum[v] - (p[pv] == -1 ? hash(0) : rev_sum[p[pv]])) * pw[h[v]];
}

inline hash get_hash(int a, int b, int ab, int len) {
    if (len <= h[a] - h[ab] + 1) {
        return get_rev_sum(a, get_ver(a, len));
    }
    len -= h[a] - h[ab] + 1;
    int pb = get_ver(b, h[b] - h[ab]);
    return get_rev_sum(a, ab) + (sum[get_ver(b, h[b] - h[ab] - len + 1)] - sum[ab]) * pw[n + (h[a] - h[ab] + 1) - h[pb]];
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    scanf("%d", &n);
    gets(s);
    gets(s);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    pw[0] = hash(1);
    for (int i = 1; i <= 2 * n; ++i) {
        pw[i] = pw[i - 1] * X;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &q[i].a, &q[i].b, &q[i].c, &q[i].d);
        --q[i].a;
        --q[i].b;
        --q[i].c;
        --q[i].d;
        lca[q[i].a].pb(mp(q[i].b, &q[i].ab));
        lca[q[i].b].pb(mp(q[i].a, &q[i].ab));
        lca[q[i].c].pb(mp(q[i].d, &q[i].cd));
        lca[q[i].d].pb(mp(q[i].c, &q[i].cd));
    }
    for (int i = 0; i < n; ++i) {
        prev[i] = i;
        rank[i] = 1;
        val[i] = i;
    }
    sz = 0;
    shift = 0;
    dfs(0, -1);
    for (int i = 1; i <= 2 * (n + shift) + 100; ++i) {
        for (int j = LOG - 1; j >= 0; --j) {
            if ((i & (1 << j)) != 0) {
                last_bit[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int ans = 0, l = 1, r = min(len(q[i].a, q[i].b, q[i].ab), len(q[i].c, q[i].d, q[i].cd));
        while (l <= r) {
            int mid = (l + r) / 2;
            hash h1 = get_hash(q[i].a, q[i].b, q[i].ab, mid);
            hash h2 = get_hash(q[i].c, q[i].d, q[i].cd, mid);
            if (h1 == h2) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}