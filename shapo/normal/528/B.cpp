#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int n;
vector< pair< ll, ll > > val;
vector< ll > ids;
vector< int > tree;
int curk;

void
update(int x, int val)
{
    x += curk;
    tree[x] = max(tree[x], val);
    while (x != 1) {
        x /= 2;
        tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
    }
}

int
seg_max(int l, int r)
{
    int res = 0;
    l += curk;
    r += curk;
    while (l < r) {
        res = max(res, max(tree[l], tree[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = max(res, tree[l]);
    }
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    val.resize(n);
    ids.clear();
    for (int i = 0; i < n; ++i) {
        cin >> val[i].first >> val[i].second;
        ids.push_back(val[i].first + val[i].second);
    }
    sort(ids.begin(), ids.end());
    ids.resize(unique(ids.begin(), ids.end()) - ids.begin());
    sort(val.begin(), val.end());
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    tree.assign(curk * 2, 0);
    for (auto x : val) {
        ll find_w = x.first - x.second;
        int get_pos = upper_bound(ids.begin(), ids.end(), find_w) - ids.begin();
        int cur_val = seg_max(0, get_pos - 1);
        int new_pos = lower_bound(ids.begin(), ids.end(), x.first + x.second) - ids.begin();
        update(new_pos, cur_val + 1);
    }
    cout << tree[1] << '\n';
    return 0;
}