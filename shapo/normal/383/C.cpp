#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef vector < vi > v2i;
typedef vector < bool > vb;

int n, m;
vi tin, tout;
v2i g;
int curk;
int cur_time;
vi a;
vi h;
vb used;
vi odd_tree, even_tree;

void
dfs(int x, int lvl)
{
    tin[x] = ++cur_time;
    h[x] = lvl;
    used[x] = true;
    for (vi::iterator it = g[x].begin(); it != g[x].end(); ++it) {
        int to = *it;
        if (!used[to]) {
            dfs(to, lvl + 1);
        }
    }
    tout[x] = ++cur_time;
}

void
upd(int x, int val, vi &tree)
{
    x += curk - 1;
    tree[x] += val;
    x /= 2;
    while (x) {
        tree[x] = (tree[x * 2] + tree[x * 2 + 1]);
        x /= 2;
    }
}

int
getSum(int l, int r, vi &tree)
{
    int res = 0;
    l += curk - 1;
    r += curk - 1;
    while (l < r) {
        if (l % 2 == 1) {
            res += tree[l];
        }
        if (r % 2 == 0) {
            res += tree[r];
        }
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res += tree[l];
    }
    return res;
}

void
init_tree(int sz)
{
    curk = 2;
    while (curk < sz) {
        curk *= 2;
    }
    odd_tree.assign(2 * curk, 0);
    even_tree.assign(2 * curk, 0);
}

#ifdef _DEBUG
bool
#else
void
#endif
input_data()
{
#ifdef _DEBUG
    if (!(cin >> n >> m)) {
        return false;
    }
#else
    cin >> n >> m;
#endif
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    g.resize(n + 5);
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    used.assign(n + 1, false);
    h.assign(n + 1, 0);
    cur_time = 0;
    dfs(1, 0);
    init_tree(cur_time);
    for (int i = 0; i < m; ++i) {
        int type, x, val;
        cin >> type >> x;
        if (type == 1) {
            cin >> val;
            vi &tmp_tree = (h[x] % 2 == 0) ? even_tree : odd_tree;
            upd(tin[x], val, tmp_tree);
            upd(tout[x], -val, tmp_tree);
        } else {
            int even = getSum(1, tin[x], even_tree);
            int odd = getSum(1, tin[x], odd_tree);
            int sum = 0;
            if (h[x] % 2 == 0) {
                sum = even - odd;
            } else {
                sum = odd - even;
            }
            cout << (a[x] + sum) << '\n';
        }
    }
#ifdef _DEBUG
    return true;
#endif
}

void calc()
{
}

int
main(int argc, char **argv)
{
#ifdef _DEBUG
    while (input_data()) {
#else
    ios_base::sync_with_stdio(false);
    input_data();
#endif
    calc();
#ifdef _DEBUG
    }
#endif
    return 0;
}