#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "climits"
#include "queue"
#include "array"
#include "numeric"
#include "random"
using namespace std;
#define all(x) x.begin(), x.end()
struct segtree {
    vector<int> tree;
    int sz;
    segtree(int n) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, {});
    }
    void ch(int v, int x) {
        v += sz;
        tree[v] = x;
        while (v != 1) {
            v /= 2;
            tree[v] = max(tree[v], x);
        }
    }
    int get(int l, int r) {
        l += sz;
        r += sz;
        int mx = 0;
        while (l <= r) {
            if (l % 2) {
                mx = max(mx, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                mx = max(mx, tree[r]);
                r--;
            }
            l /= 2;r /= 2;
        }
        return mx;
    }
};
vector<int> needheig(vector<int> a) {
    int n = a.size();
    vector<int> heig(n,2e9);
    heig[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] < a[i]) {
            heig[i] = heig[i - 1];
        }
        if (heig[i - 1] <= a[i])
            heig[i] = min(heig[i], a[i - 1]);
    }
    return heig;
}
int solve(vector<int> a) {
    int n = a.size();
    /*vector<int> leftmore(n), rightmore(n);
    for (int i = 0; i < n; ++i) {
        leftmore[i] = i - 1;
        while (leftmore[i] != -1 and a[i] > a[leftmore[i]])
            leftmore[i] = leftmore[leftmore[i]];
    }
    for (int i = n - 1; i >= 0; --i) {
        rightmore[i] = i + 1;
        while (rightmore[i] != n and a[i] > a[rightmore[i]])
            rightmore[i] = rightmore[rightmore[i]];
    }*/
    vector<int> heiglft = needheig(a), heigright;
    reverse(all(a));
    heigright = needheig(a);
    reverse(all(heigright));
    reverse(all(a));
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[mx])
            mx = i;
    }
    if (mx == n - 1)
        return 0;
    vector<int> res(n, -1);
    res[mx] = a[mx];
    a[mx] = heiglft[mx];
    //cerr << heiglft[mx] << endl;
    vector<int> nextdown(n);
    for (int i = 1; i < n; ++i) {
        nextdown[i] = nextdown[i - 1];
        if (a[i - 1] < a[i])
            nextdown[i] = i;
        if (i - 1 == mx)
            nextdown[i] = i;
    }
    for (int i = mx + 1; i < n; ++i) {
        if (a[i - 1] <= a[i]) {
            res[i] = res[i - 1];
        }
        if (i != mx + 1 and a[nextdown[i - 1] - 1] <= a[i]) {
            //cerr << i << endl;
            if (res[nextdown[i - 1] - 1] >= a[nextdown[i - 1]]) {
                res[i] = max(res[i], a[i - 1]);
            }
        }
        if (i != mx + 1 and a[nextdown[i - 1]] <= a[i] and nextdown[i - 1] != i - 1) {
            if (res[nextdown[i - 1]] >= a[nextdown[i - 1] + 1]) {
                res[i] = max(res[i], a[i - 1]);
            }
        }
    }
    int vl = 0;
    for (int i = mx + 1; i < n; ++i) {
        //cerr << res[i] << ' ' << heigright[i] << endl;
        if (res[i] >= heigright[i])
            vl++;
    }
    return vl;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = solve(a);
    reverse(all(a));
    ans += solve(a);
    cout << ans << endl;
}