#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <utility>
#include <tuple>

using namespace std;

typedef long long ll;

struct DSU
{
    int sz;
    vector< int > par;
    vector< int > rnk;
    vector< ll > len;
    vector< ll > split;
    DSU(const vector< ll > &coords) {
        sz = int(coords.size()) - 1;
        par.resize(sz);
        for (int i = 0; i < sz; ++i) {
            par[i] = i;
        }
        rnk.assign(sz, 0);
        split = coords;
        len.resize(sz, 0);
        for (int i = 0; i < sz; ++i) {
            len[i] = split[i + 1] - split[i];
        }
    }
    int get_par(int x)
    {
        if (par[x] != x) par[x] = get_par(par[x]);
        return par[x];
    }
    void merge_tree(int x, int y)
    {
        if (rnk[x] >= rnk[y]) {
            par[y] = x;
        } else {
            par[x] = y;
        }
        len[par[x]] = len[x] + len[y];
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
    void link(int x, int y) {
        merge_tree(get_par(x), get_par(y));
    }
    ll union_coord(ll x)
    {
        int pos = lower_bound(split.begin(), split.end(), x) - split.begin();
        link(pos - 1, pos);
        return len[get_par(pos)];
    }
};

int
main()
{
    ios_base::sync_with_stdio(false);
    ll w, h;
    int n;
    cin >> w >> h;
    cin >> n;
    ll max_w = 0ll, max_h = 0ll;
    vector< ll > split_w = {0, w}, split_h = {0, h};
    vector< pair< char, ll > > q;
    for (int i = 0; i < n; ++i) {
        char c;
        ll pos;
        cin >> c >> pos;
        q.push_back(make_pair(c, pos));
        if (c == 'V') {
            split_w.push_back(pos);
        } else {
            split_h.push_back(pos);
        }
    }
    sort(split_w.begin(), split_w.end());
    sort(split_h.begin(), split_h.end());
    DSU wdsu(split_w), hdsu(split_h);
    for (int i = 1; i < int(split_w.size()); ++i) {
        max_w = max(max_w, split_w[i] - split_w[i - 1]);
    }
    for (int i = 1; i < int(split_h.size()); ++i) {
        max_h = max(max_h, split_h[i] - split_h[i - 1]);
    }
    vector< ll > res(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        res[i] = max_h * max_w;
        char c;
        ll pos;
        tie(c, pos) = q[i];
        if (c == 'V') {
            max_w = max(max_w, wdsu.union_coord(pos));
        } else {
            max_h = max(max_h, hdsu.union_coord(pos));
        }
    }
    for (auto x : res) {
        cout << x << '\n';
    }
    return 0;
}