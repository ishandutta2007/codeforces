#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <cstring>
#include <cstdlib>
#include <cassert>

using namespace std;

vector< pair< int, int > > tree;
int curk;
int n, m;
vector< set< pair< int, int > > > segments;
vector< int > a;
vector< int > diff;
map< int, int > last_pos;
vector< pair< int, int > > diffs;
vector< int > ans;

pair< int, int >
getmax(pair< int, int > a, pair< int, int > b)
{
    return (a > b) ? a : b;
}

void
update_pos(int x, int val)
{
    x += curk;
    tree[x] = {val, x - curk};
    x /= 2;
    while (x) {
        tree[x] = getmax(tree[x * 2], tree[x * 2 + 1]);
        x /= 2;
    }
}

pair< int, int >
seg_max(int l, int r)
{
    pair< int, int > res = {-1, -1};
    l += curk;
    r += curk;
    while (l < r) {
        res = getmax(res, getmax(tree[l], tree[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = getmax(res, tree[l]);
    }
    return res;
}

void
update_ans_and_delete(int pos, int val)
{
    auto it = *(segments[pos].rbegin());
    int id = it.second;
    ans[id] = val;
    segments[pos].erase(it);
    int max_right = (segments[pos].empty()) ? -1 : segments[pos].rbegin()->first;
    update_pos(pos, max_right);
}    

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    last_pos.clear();
    diff.resize(n, -1);
    diffs.clear();
    for (int i = n - 1; i >= 0; --i) {
        auto it = last_pos.find(a[i]);
        if (it == last_pos.end()) {
            last_pos[a[i]] = i;
        } else {
            diff[i] = it->second - i;
            diffs.push_back({diff[i], i});
            it->second = i;
        }
    }
    sort(diffs.begin(), diffs.end());
    segments.resize(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        segments[l].insert({r, i});
    }
    curk = 2;
    while (curk < n) curk *= 2;
    tree.assign(2 * curk, {-1, -1});
    for (int i = 0; i < n; ++i) {
        if (!segments[i].empty()) {
            int max_right = segments[i].rbegin()->first;
            update_pos(i, max_right);
        }
    }
    ans.resize(m, -1);
    for (auto x : diffs) {
        int l = x.second, r = x.second + x.first;
        auto id = seg_max(0, l);
        while (id.first >= r) {
            int pos = id.second;
            update_ans_and_delete(pos, x.first);
            id = seg_max(0, l);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}