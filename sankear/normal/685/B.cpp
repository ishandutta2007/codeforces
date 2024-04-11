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
const int N = int(3e5) + 100;

int ptr = 0, maxv;
int el[N], er[N], sz[N], max_sz[N], ord[N], ans[N];
vi g[N];
pii rmq[4 * N];
pii qs[N];

void dfs(int v) {
    el[v] = ptr++;
    sz[v] = 1;
    max_sz[v] = 0;
    for (int u : g[v]) {
        dfs(u);
        sz[v] += sz[u];
        max_sz[v] = max(max_sz[v], sz[u]);
    }
    er[v] = ptr - 1;
}

inline bool cmp(int a, int b) {
    return max_sz[a] < max_sz[b];
}

inline bool cmp2(pii a, pii b) {
    return sz[a.fs] / 2 < sz[b.fs] / 2;
}

inline void update(int pos, pii val) {
    pos += maxv;
    rmq[pos] = val;
    while (pos > 1) {
        pos /= 2;
        rmq[pos] = max(rmq[pos * 2], rmq[pos * 2 + 1]);
    }
}

inline pii get(int l, int r) {
    pii res(-inf, -1);
    l += maxv;
    r += maxv;
    while (l <= r) {
        res = max(res, rmq[l]);
        l = (l + 1) / 2;
        res = max(res, rmq[r]);
        r = (r - 1) / 2;
    }
    return res;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        g[p].pb(i);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d", &qs[i].fs);
        --qs[i].fs;
        qs[i].sc = i;
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        ord[i] = i;
    }
    sort(ord, ord + n, cmp);
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 1; i < 2 * maxv; ++i) {
        rmq[i] = mp(-inf, -1);
    }
    sort(qs, qs + q, cmp2);
    int ptr = 0;
    for (int i = 0; i < q; ++i) {
        while (ptr < n && max_sz[ord[ptr]] <= sz[qs[i].fs] / 2) {
            update(el[ord[ptr]], mp(sz[ord[ptr]], ord[ptr]));
            ++ptr;
        }
        ans[qs[i].sc] = get(el[qs[i].fs], er[qs[i].fs]).sc;
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i] + 1);
    }
    return 0;
}