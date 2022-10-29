#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

typedef uint32_t uint;
typedef int64_t ll;

typedef ve<int> vi;
typedef ve<vi> v2i;
typedef pa<int, int> pii;

const vi fib_sizes = {
    1, 1, 2, 3, 5, 8, 13, 21, 34, 55,
    89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
    10946, 17711, 28657, 46368, 75025, 121393, 196418
};

void
dfs(const v2i& g, int x, vi& par, vi& cnt)
{
    cnt[x] = 1;
    for (int to : g[x]) {
        if (to != par[x]) {
            par[to] = x;
            dfs(g, to, par, cnt);
            cnt[x] += cnt[to];
        }
    }
}

void
split_graph(const v2i& g, int x, int par, int sub_par, v2i& sub_g)
{
    int sub_x = sub_g.size();
    {
        vi sub_g_x;
        sub_g_x.reserve(g[x].size());
        sub_g.push_back(move(sub_g_x));
    }
    if (sub_par != -1) {
        sub_g[sub_x].push_back(sub_par);
        sub_g[sub_par].push_back(sub_x);
    }
    for (int to : g[x]) {
        if (to != par) {
            split_graph(g, to, x, sub_x, sub_g);
        }
    }
}

bool
check(const v2i& g)
{
    int n = g.size();
    auto fib_it = lower_bound(fib_sizes.begin(), fib_sizes.end(), n);
    if (fib_it == fib_sizes.end() || *fib_it != n) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    vi cands = {*(fib_it - 2), *(fib_it - 1)};
    vi cnt(n, 0), par(n, -1);
    dfs(g, 0, par, cnt);
    int split_v = 0;
    while (split_v < n && find(cands.begin(), cands.end(), cnt[split_v]) == cands.end()) {
        ++split_v;
    }
    if (split_v == n) {
        return false;
    }
    // Split on edge v - par
    v2i sub_g;
    sub_g.reserve(cands.back());
    split_graph(g, split_v, par[split_v], -1, sub_g);
    auto is_g1 = check(sub_g);
    sub_g.clear();
    split_graph(g, par[split_v], split_v, -1, sub_g);
    auto is_g2 = check(sub_g);
    return is_g1 && is_g2;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    v2i g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (check(g)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}