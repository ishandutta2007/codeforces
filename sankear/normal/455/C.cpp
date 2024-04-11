#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = int(3e5) + 100;

int best;
vi lst;
bool used[N];
int d[N], p[N], prev[N], rank[N], ans[N];
vi g[N];

void dfs1(int v) {
    used[v] = true;
    d[v] = 0;
    lst.pb(v);
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!used[g[v][i]]) {
            p[g[v][i]] = v;
            dfs1(g[v][i]);
            d[v] = max(d[v], d[g[v][i]] + 1);
        }
    }
}

void dfs2(int v, int len) {
    int max1 = 0, max2 = 0;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (p[g[v][i]] == v) {
            int cur = d[g[v][i]] + 1;
            if (cur > max1) {
                max2 = max1;
                max1 = cur;
            }
            else {
                max2 = max(max2, cur);
            }
        }
    }
    best = max(best, max(max1 + max2, max1 + len));
    for (int i = 0; i < sz(g[v]); ++i) {
        if (p[g[v][i]] == v) {
            if (d[g[v][i]] + 1 == max1) {
                dfs2(g[v][i], max(len, max2) + 1);
            }
            else {
                dfs2(g[v][i], max(len, max1) + 1);
            }
        }
    }
}

int get(int a) {
    if (prev[a] != a) {
        prev[a] = get(prev[a]);
    }
    return prev[a];
}

inline void merge(int a, int b) {
    if (rank[a] < rank[b]) {
        swap(a, b);
    }
    prev[b] = a;
    if (rank[a] == rank[b]) {
        ++rank[a];
    }
    ans[a] = max(max(ans[a], ans[b]), (ans[a] + 1) / 2 + (ans[b] + 1) / 2 + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            p[i] = -1;
            lst.clear();
            dfs1(i);
            best = 0;
            dfs2(i, 0);
            for (int j = 0; j < sz(lst); ++j) {
                prev[lst[j]] = lst[0];
            }
            ans[lst[0]] = best;
        }
    }
    for (int i = 0; i < q; ++i) {
        int t, a;
        scanf("%d %d", &t, &a);
        --a;
        if (t == 1) {
            a = get(a);
            printf("%d\n", ans[a]);
            continue;
        }
        int b;
        scanf("%d", &b);
        --b;
        a = get(a);
        b = get(b);
        if (a == b) {
            continue;
        }
        merge(a, b);
    }
    return 0;
}