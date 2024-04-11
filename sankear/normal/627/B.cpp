#include <iostream>
#include <unistd.h>
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
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;

int n;
ll cnt[N], fen_a[N], fen_b[N];

inline void add(ll* fen, int pos, ll val) {
    while (pos < n) {
        fen[pos] += val;
        pos = (pos | (pos + 1));
    }
}

inline ll get(ll* fen, int pos) {
    ll res = 0;
    while (pos >= 0) {
        res += fen[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

inline ll get(ll* fen, int l, int r) {
    if (l > r) {
        return 0;
    }
    return get(fen, r) - (l > 0 ? get(fen, l - 1) : 0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int d, add;
            scanf("%d %d", &d, &add);
            --d;
            if (cnt[d] <= a) {
                ::add(fen_a, d, min(a - cnt[d], 1LL * add));
            }
            if (cnt[d] <= b) {
                ::add(fen_b, d, min(b - cnt[d], 1LL * add));
            }
            cnt[d] += add;
            continue;
        }
        assert(t == 2);
        int p;
        scanf("%d", &p);
        --p;
        ll ans = get(fen_b, 0, p - 1) + get(fen_a, p + k, n - 1);
        printf(LLD "\n", ans);
    }
    return 0;
}