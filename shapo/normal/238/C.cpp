#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define ve vector
#define pa pair

#define pb push_back
#define mp make_pair

typedef pa<int, int> Edge;
typedef ve<ve<Edge>> Graph;

int
dfs_bot(int x, int par_id, const Graph& g)
{
    int num = 0;
    for (auto [to, mark] : g[x]) {
        if (to == par_id) continue;
        num += dfs_bot(to, x, g) + (1 - mark);
    }
    return num;
}

void
dfs_top(int x, int par_id, int val, const Graph& g, int& ans)
{
    ans = min(ans, val);
    for (auto [to, mark] : g[x]) {
        if (to == par_id) continue;
        dfs_top(to, x, val + 2 * mark - 1, g, ans);
    }
}

int
main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ve<pa<int, int>> edges;
    Graph g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(mp(v, 1));
        g[v].pb(mp(u, 0));
        edges.pb(mp(u, v));
    }
    int ans = edges.size();
    for (auto [u, v] : edges) {
        int cur = 0;
        for (int i = 0; i < 2; ++i) {
            int num_root = dfs_bot(u, v, g);
            int p_cur = num_root;
            dfs_top(u, v, num_root, g, p_cur);
            cur += p_cur;
            swap(u, v);
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}