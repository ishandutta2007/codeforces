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
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
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

const ll inf = ll(1e17);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;
const int SIZE = int(6e6);

int used[N];
int p[N], cnt[N];
ll max_len[N], can[N];
vector<pii> g[N];
vi st;

void dfs1(int v) {
    used[v] = true;
    max_len[v] = 0;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!used[g[v][i].fs]) {
            p[g[v][i].fs] = v;
            dfs1(g[v][i].fs);
            max_len[v] = max(max_len[v], max_len[g[v][i].fs] + g[v][i].sc);
        }
    }
}

void dfs2(int v, ll cur_len) {
    ll max1 = -inf, max2 = -inf;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (p[g[v][i].fs] == v) {
            ll cur = max_len[g[v][i].fs] + g[v][i].sc;
            if (cur > max1) {
                max2 = max1;
                max1 = cur;
            } else {
                max2 = max(max2, cur);
            }
        }
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        if (p[g[v][i].fs] == v) {
            ll cur = max_len[g[v][i].fs] + g[v][i].sc;
            dfs2(g[v][i].fs, max(cur_len, (cur == max1 ? max2 : max1)) + g[v][i].sc);
        }
    }
    can[v] = max(cur_len, max_len[v]);
}

inline bool cmp(const pii& a, const pii& b) {
    return can[a.fs] < can[b.fs];
}

int ptr;
ll len;

void dfs3(int v) {
    st.pb(v);
    ++cnt[v];
    if (ptr != -1) {
        --cnt[st[ptr]];
    }
    int old_ptr = ptr;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (p[g[v][i].fs] == v) {
            while (ptr + 1 < sz(st) && can[st[ptr + 1]] + len < can[g[v][i].fs]) {
                ++ptr;
            }
            dfs3(g[v][i].fs);
            cnt[v] += cnt[g[v][i].fs];
        }
    }
    st.pbk();
    ptr = old_ptr;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a;
        --b;
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
    }
    if (n == 2) {
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            puts("2");
        }
        return 0;
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (sz(g[i]) > 1) {
            root = i;
        }
    }
    assert(root != -1);
    p[root] = -1;
    dfs1(root);
    dfs2(root, -inf);
    for (int i = 0; i < n; ++i) {
        used[i] = false;
        if (can[i] < can[root]) {
            root = i;
        }
    }
    assert(sz(g[root]) > 1);
    p[root] = -1;
    dfs1(root);
    dfs2(root, -inf);
    for (int i = 0; i < n; ++i) {
        sort(all(g[i]), cmp);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        scanf(LLD, &len);
        ptr = -1;
        for (int j = 0; j < n; ++j) {
            cnt[j] = 0;
        }
        dfs3(root);
        int max_cnt = 0;
        for (int j = 0; j < n; ++j) {
            max_cnt = max(max_cnt, cnt[j]);
        }
        printf("%d\n", max_cnt);
    }
    return 0;
}