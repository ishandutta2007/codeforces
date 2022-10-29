#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>

using namespace std;

typedef long long ll;

vector< vector< pair< int, ll > > > g;
vector< vector< int > > gone;

vector< ll > dist;
vector< vector< ll > > vals;

vector< int > st;
ll diff;

vector< int > add;

void
back_prop(int x, int par, ll elen, const vector< ll > &vl)
{
    if (vl.front() != dist[x] + elen) {
        dist[x] = max(dist[x], vl[0] + elen);
        vals[x].push_back(vl[0] + elen);
    } else if (int(vl.size()) != 1) {
        dist[x] = max(dist[x], vl[1] + elen);
        vals[x].push_back(vl[1] + elen);
    }
    sort(vals[x].rbegin(), vals[x].rend());
    for (auto to : g[x]) {
        if (to.first != par) {
            back_prop(to.first, x, to.second, vals[x]);
        }
    }
}

void
calc_dist(int x, int par = -1)
{
    dist[x] = 0ll;
    for (auto to : g[x]) {
        if (to.first != par) {
            calc_dist(to.first, x);
            dist[x] = max(dist[x], dist[to.first] + to.second);
            vals[x].push_back(dist[to.first] + to.second);
        }
    }
    if (par == -1) {
        sort(vals[x].rbegin(), vals[x].rend());
        for (auto to : g[x]) {
            back_prop(to.first, x, to.second, vals[x]);
        }
    }
}

int
dfs_part_sums(int x, int par)
{ 
    int res = 0;
    st.push_back(x);
    add[x]++;
    int cur_pos = lower_bound(st.begin(), st.end(), dist[x] - diff, 
            [&](int a, ll b) { return dist[a] < b; } ) - st.begin();
    if (cur_pos != 0) {
        add[st[cur_pos - 1]]--;
    }
    for (const auto to : gone[x]) {
        if (to != par) {
            res = max(res, dfs_part_sums(to, x));
            add[x] += add[to];
        }
    }
    st.pop_back();
    return max(res, add[x]);
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    g.clear();
    g.resize(n);
    gone.clear();
    gone.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        gone[u].push_back(v);
        gone[v].push_back(u);
    }
    dist.assign(n, 0ll);
    vals.assign(n, vector< ll >());
    int qn;
    cin >> qn;
    if (n != 2) {
        int start = 0;
        while (int(g[start].size()) == 1) ++start;
        calc_dist(start, -1);
        start = min_element(dist.begin(), dist.end()) - dist.begin();
        st.reserve(n);
        for (int i = 0; i < qn; ++i) {
            cin >> diff;
            st.clear();
            add.assign(n, 0);
            cout << dfs_part_sums(start, -1) << '\n';
        }
    } else {
        for (int i = 0; i < qn; ++i) {
            ll cur;
            cin >> cur;
            cout << 2 << '\n';
        }
    }
    return 0;
}