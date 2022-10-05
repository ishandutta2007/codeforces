#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#pragma GCC target ("avx2")
#define all(x) x.begin(), x.end()
using namespace std;

struct segtree{
    vector<pair<int, int>> tree, tree2;
    int sz;
    pair<int, int> mrg(pair<int, int> a, pair<int, int> b, int rev = 0) {
        if (rev)
            swap(a, b);
        int a1 = a.first + b.first;
        int a2 = max(a.second, a.first + b.second);
        return {a1, a2};
    }
    void make(int n) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, {-1, 0});
        tree2.assign(sz * 2, {-1, 0});
        for (int i = sz - 1; i >= 0; --i) {
            tree[i] = mrg(tree[i * 2], tree[i * 2 + 1]);
            tree2[i] =  mrg(tree2[i * 2], tree2[i * 2 + 1], 1);
        }
    }
    void upd(int v) {
        v += sz;
        tree[v] = {1, 1};
        tree2[v] = {1, 1};
        while (v != 1) {
            v /= 2;
            tree[v] = mrg(tree[v * 2], tree[v * 2 + 1]);
            tree2[v] =  mrg(tree2[v * 2], tree2[v * 2 + 1], 1);
        }
    }
    pair<int, int> getmax2(int v, int l, int r, int ll, int rr, int rev) {
        if (ll >= r or rr <= l)
            return {0, 0};
        if (rr <= r and ll >= l and rev)
            return tree2[v];
        if (rr <= r and ll >= l)
            return tree[v];
        int mm = ll + rr >> 1;
        return mrg(getmax2(v * 2, l, r, ll, mm, rev), getmax2(v * 2 + 1, l, r, mm, rr, rev), rev);
    }
    int getmax(int l, int r, int rev = 0) {
        return getmax2(1, l, r, 0, sz, rev).second;
    }
};
vector<int> slv(int n, vector<pair<int, int>> numsandpos, int one = 0) {
    segtree sg;
    sg.make(n);
    vector<int> ans(n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (i != 0 and numsandpos[i].first != numsandpos[i-1].first) {
            int j = i - 1;
            sg.upd(numsandpos[j].second);
            k++;
            while (j != 0 and numsandpos[j].first == numsandpos[j - 1].first) {
                j--;
                k++;
                sg.upd(numsandpos[j].second);
            }
        }
        int t = sg.getmax(0, numsandpos[i].second) + sg.getmax(numsandpos[i].second + 1, n, 1);
        int p = k - t;
        //cerr << i << ' ' << p << ' ' << t << endl;
        ans[numsandpos[i].second] = (n - t - one) / 2 - p;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("circlecover.in", "r", stdin);
    //freopen("circlecover.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<pair<int, int>> numsandpos(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        numsandpos[i] = {nums[i], i};
    }
    sort(all(numsandpos));
    vector<int> ans1 = slv(n, numsandpos);
    reverse(all(numsandpos));
    vector<int> ans2 = slv(n, numsandpos, 1);
    for (int i = 0; i < n; ++i) {
        cout << max(ans1[i], ans2[i]) << ' ';
    }
}