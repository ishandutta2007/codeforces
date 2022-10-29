#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

typedef vector< int > vi;

int n, curk;
vi a;

struct Tree
{
    int sum = 0;
    Tree *left = nullptr;
    Tree *right = nullptr;
};

Tree *
construct_empty(int len)
{
    Tree *res = new Tree();
    if (len != 1) {
        res->left = construct_empty(len / 2);
        res->right = construct_empty(len / 2);
    }
    return res;
}

Tree *
add_val(int pos, int l1, int r1, Tree *t)
{
    Tree *res = new Tree;
    res->sum = t->sum;
    res->left = t->left;
    res->right = t->right;
    res->sum++;
    if (l1 != r1 - 1) {
        int mid = (l1 + r1) / 2;
        if (pos < mid) {
            res->left = add_val(pos, l1, mid, t->left);
        } else {
            res->right = add_val(pos, mid, r1, t->right);
        }
    }
    return res;
}

int
get_sum(Tree *from, Tree *to, int pref_len)
{
    if (pref_len == 0) {
        return 0;
    }
    int width = curk;
    int res = 0;
    while (width != 1) {
        width /= 2;
        if (pref_len > width) {
            res += from->left->sum - to->left->sum;
            from = from->right;
            to = to->right;
            pref_len -= width;
        } else {
            from = from->left;
            to = to->left;
        }
    }
    res += from->sum - to->sum;
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    {
        vi b = a;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for (int i = 0; i < n; ++i) {
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        }
        curk = 2;
        while (curk < int(b.size())) curk *= 2;
    }
    vector< Tree * > dang_tree(n + 1);
    dang_tree[0] = construct_empty(curk);
    for (int i = 1; i <= n; ++i) {
        dang_tree[i] = add_val(a[i - 1], 1, curk + 1, dang_tree[i - 1]);
    }
    for (int k = 1; k < n; ++k) {
        int cnt = 0;
        for (int v = 1; k * (v - 1) + 2 <= n; ++v) {
            int l = k * (v - 1) + 2, r = min(n, k * v + 1);
            cnt += get_sum(dang_tree[r], dang_tree[l - 1], a[v - 1] - 1);
        }
        cout << cnt << ' ';
    }
    cout << '\n';
    return 0;
}