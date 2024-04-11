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
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
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
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;
const int LOG = 30;

int maxv;
int a[N], add[4 * N];
vi rmq[4 * N];

inline int bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

inline vi go(vi c) {
    vi res;
    for (int i = 0; i < LOG; ++i) {
        bool fl = false;
        for (int j = sz(res); j < sz(c); ++j) {
            if (bit(c[j], i)) {
                swap(c[sz(res)], c[j]);
                fl = true;
                break;
            }
        }
        if (!fl) {
            continue;
        }
        res.pb(c[sz(res)]);
        for (int j = sz(res); j < sz(c); ++j) {
            if (bit(c[j], i)) {
                c[j] ^= res.back();
            }
        }
    }
    return res;
}

inline vi merge(const vi& a, const vi& b) {
    vi c;
    c.insert(c.end(), all(a));
    c.insert(c.end(), all(b));
    return go(c);
}

void update(int v, int gl, int gr, int l, int r, int val) {
    if (gl > r || gr < l || l > r) {
        return;
    }
    if (gl >= l && gr <= r) {
        add[v] ^= val;
        return;
    }
    int mid = (gl + gr) / 2;
    update(v * 2, gl, mid, l, r, val);
    update(v * 2 + 1, mid + 1, gr, l, r, val);
}

inline int get_val(int pos) {
    int res = a[pos];
    pos += maxv;
    while (pos) {
        res ^= add[pos];
        pos /= 2;
    }
    return res;
}

inline void update_rmq(int pos, int val) {
    pos += maxv;
    rmq[pos].clear();
    if (val != 0) {
        rmq[pos].pb(val);
    }
    while (pos > 1) {
        pos /= 2;
        rmq[pos] = merge(rmq[pos * 2], rmq[pos * 2 + 1]);
    }
}

vi get(int v, int gl, int gr, int l, int r) {
    if (gl > r || gr < l || l > r) {
        return vi();
    }
    if (gl >= l && gr <= r) {
        return rmq[v];
    }
    int mid = (gl + gr) / 2;
    return merge(get(v * 2, gl, mid, l, r), get(v * 2 + 1, mid + 1, gr, l, r));
}

inline vi add_one(vi a, int b) {
    vi c;
    c.insert(c.end(), all(a));
    c.pb(b);
    return go(c);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 0; i + 1 < n; ++i) {
        if ((a[i] ^ a[i + 1]) != 0) {
            rmq[i + maxv].pb(a[i] ^ a[i + 1]);
        }
    }
    for (int i = maxv - 1; i > 0; --i) {
        rmq[i] = merge(rmq[i * 2], rmq[i * 2 + 1]);
    }
    for (int i = 0; i < m; ++i) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        --l;
        --r;
        if (t == 1) {
            int k;
            scanf("%d", &k);
            update(1, 0, maxv - 1, l, r, k);
            if (l > 0) {
                update_rmq(l - 1, get_val(l - 1) ^ get_val(l));
            }
            if (r + 1 < n) {
                update_rmq(r, get_val(r) ^ get_val(r + 1));
            }
            continue;
        }
        assert(t == 2);
        vi res = get(1, 0, maxv - 1, l, r - 1);
        res = add_one(res, get_val(l));
        printf(LLD "\n", (1LL << sz(res)));
    }
    return 0;
}