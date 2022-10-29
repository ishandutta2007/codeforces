#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <utility>
#include <tuple>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int, int > pii;
typedef vector< pii > vpii;

int n, m, q;
vvi g;
vvi bicon_g;
vpii stack;
vi used, tin, tout, tup;
vi w;
vector< set< int > > col;
vector< multiset< int > > vals;
int timer;
int cnt;

vector< pii > inv_ref;

struct Path
{
    int p_id;
    int par;
    vector< int > ids;
    vector< int > tree;
    int n, curk;
    int get_min(int l, int r = -1)
    {
        if (r == -1) {
            r = n - 1;
        }
        l += curk, r += curk;
        int res = tree[l];
        while (l < r) {
            res = min(res, min(tree[l], tree[r]));
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        if (l == r) {
            res = min(res, tree[l]);
        }
        return res;
    }
    void
    upd_val(int pos, int val)
    {
        pos += curk;
        tree[pos] = val;
        while (pos != 1) {
            pos /= 2;
            tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }
    void
    make_inv_refs()
    {
        for (int i = 0; i < n; ++i) {
            int id = ids[i];
            inv_ref[id] = {p_id, i};
        }
    }
    Path(int id, int _par, vi &&g_ids) :
        p_id(id), par(_par), ids(g_ids.rbegin(), g_ids.rend())
    {
        n = int(ids.size());
        curk = 2;
        while (curk < n) {
            curk *= 2;
        }
        tree.assign(2 * curk, 1000000000);
        for (int i = 0; i < n; ++i) {
            tree[i + curk] = w[ids[i]];
        }
        for (int i = curk - 1; i > 0; --i) {
            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
        }
        make_inv_refs();
    }
};

vector< int > tree_sz;
vector< int > to;
vector< vi > parent;

void
flush_biconcomp(pii end)
{
    //cout << "Find new biconnected component!" << endl;
    auto edge = stack.back();
    col.emplace_back();
    do {
        edge = stack.back();
        stack.pop_back();
        { // do some stuff, make sure edge remains the same!
            col[edge.first].insert(cnt);
            col[cnt].insert(edge.first);
            col[edge.second].insert(cnt);
            col[cnt].insert(edge.second);
            // print edges
            /*edge.first++, edge.second++;
            cout << "(" << edge.first << ", " << edge.second << ")" << endl;
            edge.first--, edge.second--;*/
        }
    } while (edge != end);
    cnt++;
}

void
find_articulation_points(int x, int par = -1)
{
    tin[x] = tup[x] = ++timer;
    used[x] = true;
    for (auto son : g[x]) {
        if (!used[son]) {
            stack.emplace_back(x, son);
            find_articulation_points(son, x);
            if (tup[son] >= tin[x]) {
                // find new biconnected component
                flush_biconcomp({x, son});
            }
            tup[x] = min(tup[x], tup[son]);
        } else if (son != par && tin[son] < tin[x]) {
            stack.emplace_back(x, son);
            tup[x] = min(tup[x], tin[son]);
        }
    }
}

void
construct_bipartite()
{ // constructing bipartite graph 
    used.assign(n, 0);
    tin.resize(n);
    tup.resize(n);
    col.assign(n, set< int >());
    // run dfs for calcilating tup's used for finding articulation points 
    timer = 0;
    cnt = n;
    // find articulation points
    find_articulation_points(0);
    bicon_g.clear();
    vals.assign(cnt, multiset< int >());
    for (int i = 0; i < cnt; ++i) {
        bicon_g.emplace_back(col[i].begin(), col[i].end());
    }
    w.resize(cnt, 1000000000);
    for (int i = 0; i < n; ++i) {
        if (bicon_g[i].size() == 1u) {
            vals[bicon_g[i].front()].insert(w[i]);
        }
    }
    for (int i = n; i < cnt; ++i) {
        w[i] = *(vals[i].begin());
    }
}

void
dfs_bipartite(int x, int par)
{
    tin[x] = ++timer;
    parent[0][x] = par;
    tree_sz[x] = 1;
    for (auto son : bicon_g[x]) {
        if (son != par) {
            dfs_bipartite(son, x);
            tree_sz[x] += tree_sz[son];
            if (to[x] == -1 || tree_sz[son] > tree_sz[to[x]]) {
                to[x] = son;
            }
        }
    }
    tout[x] = ++timer;
}

vector< Path > hld;

void
create_hld(int x, int par, vi &&stack, int cur_par)
{
    stack.push_back(x);
    if (to[x] == -1) {
        int id = int(hld.size());
        hld.emplace_back(id, cur_par, std::move(stack));
    } else {
        create_hld(to[x], x, std::move(stack), cur_par);
    }
    for (auto son : bicon_g[x]) {
        if (son != par && son != to[x]) {
            create_hld(son, x, {}, x);
        }
    }
}

void
make_hld()
{
    tree_sz.assign(cnt, 0);
    to.assign(cnt, -1);
    tin.assign(cnt, 0);
    tout.assign(cnt, 0);
    parent.assign(20, vi(cnt, -1));
    timer = 0;
    dfs_bipartite(0, -1);
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < cnt; ++j) {
            if (parent[i - 1][j] != -1) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }
    inv_ref.assign(cnt, {0, 0});
    create_hld(0, -1, {}, -1);
}

int
lca(int u, int v)
{
    auto is_par = [&](int x, int y) -> bool
    {
        return (tin[x] <= tin[y] && tout[x] >= tout[y]);
    };
    if (is_par(u, v)) {
        return u;
    } else if (is_par(v, u)) {
        return v;
    }
    int res = u;
    for (int i = 19; i >= 0; --i) {
        int next_v = parent[i][res];
        if (next_v != -1 && !is_par(next_v, v)) {
            res = next_v;
        }
    }
    return parent[0][res];
}

void
upd_weight(int x, int val)
{
    int old_val = w[x];
    w[x] = val;
    int hld_id, hld_pos;
    tie(hld_id, hld_pos) = inv_ref[x];
    hld[hld_id].upd_val(hld_pos, val);
    int bcc_id = bicon_g[x].front();
    if (bicon_g[x].size() > 1u) {
        bcc_id = parent[0][x];
    }
    if (bcc_id != -1) {
        tie(hld_id, hld_pos) = inv_ref[bcc_id];
        auto it = vals[bcc_id].find(old_val);
        if (it != vals[bcc_id].end()) {
            vals[bcc_id].erase(it);
        }
        vals[bcc_id].insert(val);
        w[bcc_id] = val = *(vals[bcc_id].begin());
        hld[hld_id].upd_val(hld_pos, val);
    }
}

int
find_min_weight(int x, int y, bool has_lca=false)
{
    int ans = min(w[x], w[y]);
    if (!has_lca) {
        int mid = lca(x, y);
        if (mid != x) {
            ans = min(ans, find_min_weight(x, mid, true));
        }
        if (mid != y) {
            ans = min(ans, find_min_weight(y, mid, true));
        }
        if (mid >= n) {
            ans = min(ans, w[parent[0][mid]]);
        }
    } else {
        int cur_hld_id = inv_ref[x].first;
        int target_hld_id = inv_ref[y].first;
        while (cur_hld_id != target_hld_id) {
            int f_id = inv_ref[x].second;
            ans = min(ans, hld[cur_hld_id].get_min(f_id));
            x = hld[cur_hld_id].par;
            cur_hld_id = inv_ref[x].first;
        }
        int f_id = inv_ref[x].second, s_id = inv_ref[y].second;
        ans = min(ans, hld[cur_hld_id].get_min(f_id, s_id));
    }
    return ans;
}

int
main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> q;
    w.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    construct_bipartite();
    make_hld();
    for (int i = 0; i < n; ++i) {
        upd_weight(i, w[i]);
    }
    for (int i = 0; i < q; ++i) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'A') {
            --a, --b;
            int res = find_min_weight(a, b);
            cout << res << '\n';
        } else {
            --a;
            upd_weight(a, b);
        }
    }
    return 0;
}