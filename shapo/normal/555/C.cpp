#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <utility>

using namespace std;

typedef vector< int > vi;

struct List
{
    int max_seg;
    int add;
    List() : max_seg(0), add(0) {}
};

const int MAXN = 200500;
const int MAXK = 524288;

struct Tree
{
    vector< List > arr;
    int n, curk;
    vi pos;
    Tree(const vi &p) : pos(p)
    {
        n = pos.size();
        curk = 2;
        while (curk < n) curk *= 2;
        arr.assign(curk * 2, List());
    }
    void push(int v)
    {
        arr[v * 2].add = max(arr[v].add, arr[v * 2].add);
        arr[v * 2 + 1].add = max(arr[v].add, arr[v * 2 + 1].add);
        arr[v].add = 0;
    }
    int get(int v)
    {
        return max(arr[v].max_seg, arr[v].add);
    }
    void upd(int v)
    {
        arr[v].add = 0;
        arr[v].max_seg = max(get(v * 2), get(v * 2 + 1));
    }
    void set_max(int from, int to, int val, int l = 0, int r = -1, int root = 1)
    {
        if (r == -1) {
            r = n;
        }
        if (max(from, pos[l]) > min(to, pos[r - 1])) {
            return;
        }
        if (from <= pos[l] && to >= pos[r - 1]) {
            arr[root].add = max(arr[root].add, val);
            return;
        }
        push(root);
        int mid = (l + r) / 2;
        set_max(from, to, val, l, mid, root * 2);
        set_max(from, to, val, mid, r, root * 2 + 1);
        upd(root);
    }
    int get_pos(int x, int l = 0, int r = -1, int root = 1)
    {
        if (r == -1) {
            r = n;
        }
        if (l == r - 1) {
            return get(root);
        }
        int res = 0;
        push(root);
        int mid = (l + r) / 2;
        if (pos[mid] > x) {
            res = get_pos(x, l, mid, root * 2);
        } else {
            res = get_pos(x, mid, r, root * 2 + 1);
        }
        upd(root);
        return res;
    }
};

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vi dx(q), dy(q);
    vector< char > dir(q);
    for (int i = 0; i < q; ++i) {
        cin >> dx[i] >> dy[i] >> dir[i];
    }
    vi x = dx, y = dy;
    x.push_back(0); y.push_back(0);
    x.push_back(n); y.push_back(n);
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    Tree x_tree(x), y_tree(y);
    for (int i = 0; i < q; ++i) {
        int res = 0;
        if (dir[i] == 'U') {
            res = dy[i] - x_tree.get_pos(dx[i]);
            if (res) {
                y_tree.set_max(dy[i] - res + 1, dy[i], dx[i]);
                x_tree.set_max(dx[i], dx[i], dy[i]);
            }
        } else {
            res = dx[i] - y_tree.get_pos(dy[i]);
            if (res) {
                x_tree.set_max(dx[i] - res + 1, dx[i], dy[i]);
                y_tree.set_max(dy[i], dy[i], dx[i]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}