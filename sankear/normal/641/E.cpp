#pragma comment(linker, "/STACK:256000000")

#include <iostream>
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
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
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
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e6) + 100;

struct query {
    
    int a, t, x;
    
    query() {}
    
    query(int a, int t, int x) : a(a), t(t), x(x) {}
    
};

int k;
query q[N];
vector<query> qs[N];
int fen[N], xs[N], ts[N], ans[N];

inline void add(int pos, int val) {
    while (pos < k) {
        fen[pos] += val;
        pos |= (pos + 1);
    }
}

inline int get(int pos) {
    int res = 0;
    while (pos >= 0) {
        res += fen[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &q[i].a, &q[i].t, &q[i].x);
        xs[i] = q[i].x;
    }
    sort(xs, xs + n);
    int m = unique(xs, xs + n) - xs;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(xs, xs + m, q[i].x) - xs;
        qs[pos].pb(query(q[i].a, q[i].t, i));
    }
    for (int i = 0; i < m; ++i) {
        k = 0;
        for (query q : qs[i]) {
            ts[k++] = q.t;
        }
        sort(ts, ts + k);
        for (int j = 0; j < k; ++j) {
            fen[j] = 0;
        }
        for (query q : qs[i]) {
            int pos = lower_bound(ts, ts + k, q.t) - ts;
            if (q.a == 1) {
                add(pos, 1);
            } else if (q.a == 2) {
                add(pos, -1);
            } else {
                ans[q.x] = get(pos);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (q[i].a == 3) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}