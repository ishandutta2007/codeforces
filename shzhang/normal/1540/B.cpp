#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define LOG2_N 8

vector<int> graph[205];
int depth[205];
int parent[205];
int ancestor[205][LOG2_N];

void dfs(int node, int prt)
{
    depth[node] = depth[prt] + 1;
    parent[node] = prt;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);

        /* you can do other things here, such as tree DP */
    }
}

int lca(int A, int B)
{
    if (depth[A] < depth[B]) swap(A, B);
    for (int i = 0; i < LOG2_N; i++) {
        if ((depth[A] - depth[B]) & (1 << i)) A = ancestor[A][i];
    }
    if (A == B) return A;
    for (int i = LOG2_N - 1; i >= 0; i--) {
        if (ancestor[A][i] != ancestor[B][i]) {
            A = ancestor[A][i];
            B = ancestor[B][i];
        }
    }
    return parent[A];
}

void inputtree(int siz, int root = 1)
{
    for (int i = 1; i < siz; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(root, 0);
    for (int i = 1; i <= siz; i++) ancestor[i][0] = parent[i];
    for (int pwr = 1; pwr < LOG2_N; pwr++) {
        for (int i = 1; i <= siz; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
}


#define DEFMOD(mod, type) typedef ModInt<mod, int> type;     \
                          type operator "" _m(unsigned long long x) {   \
                              type res = x; return res; \
                          }

template<int mod, class itype> struct ModInt {
    int val;
    ModInt() {
        val = 0;
    }
    ModInt(int a) {
        val = a % mod;
    }
};

/* MODIFY AS NEEDED */

DEFMOD(1000000007, mi)

template<int mod, class itype> ModInt<mod, itype> fpow(ModInt<mod, itype> base, int exponent)
{
    ModInt<mod, itype> ans = 1_m;
    ModInt<mod, itype> cur = base;
    while (exponent) {
        if (exponent & 1) ans = ans * cur;
        cur = cur * cur; exponent >>= 1;
    }
    return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator+(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ll val = (ll)(a.val) + (ll)(b.val);
    if (val >= mod) val -= mod;
    ans.val = val; return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator-(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ans.val = a.val - b.val;
    if (ans.val < 0) ans.val += mod;
    return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator*(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ans.val = ((ll)(a.val) * (ll)(b.val)) % (ll)mod;
    return ans;
}

// PRIME MOD ONLY!
template<int mod, class itype> ModInt<mod, itype> operator/(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
#ifndef ONLINE_JUDGE
    if (b.val == 0) {
        fprintf(stderr, "Division by zero :(\n"); abort();
    }
#endif
    return a * fpow(b, mod - 2);
}

int dist(int x, int y)
{
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int n;

// prob of 2nd reaching 0 first
mi f[205][205];

int main()
{
    scanf("%d", &n);
    inputtree(n);
    mi half = 1_m / 2_m;
    mi one_n = 1_m / (mi)n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                f[i][j] = 1_m;
            } else {
                f[i][j] = f[i-1][j] * half + f[i][j-1] * half;
            }
        }
    }
    mi ans = 0_m;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int lca0 = lca(i, j);
            mi prob = 0;
            for (int k = 1; k <= n; k++) {
                int lca1 = lca(i, k);
                //if (lca1 == i) continue;
                int lca2 = lca(j, k);
                /*if (lca2 == j) {
                    prob = prob + 1_m; continue;
                }*/
                int point;
                if (lca1 == lca0 || lca2 == lca0) {
                    point = (lca1 == lca0 ? lca2 : lca1);
                } else {
                    point = lca0;
                }
                //printf("%d %d %d %d\n", i, j, k, point);
                int l1 = dist(point, i);
                int l2 = dist(point, j);
                prob = prob + f[l1][l2];
            }
            ans = ans + prob * one_n;
        }
    }
    printf("%d", ans.val);
    return 0;
}