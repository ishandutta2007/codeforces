#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
struct segtree {
    int sz;
    vector<pair<int, int>> tree;
    void make(int n) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, {-1, -1});
        for (int i = 0; i < n; ++i) {
            tree[i + sz] = {0, i};
        }
        for (int i = sz - 1; i > 0; --i) {
            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    pair<int, int> getmin(int l, int r) {
        l += sz;
        r += sz;
        pair<int, int> res = {0, 179};
        while (l <= r) {
            if (l % 2 == 1) {
                res = min(res, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                res = min(res, tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
    void upd0(int v) {
        v += sz;
        tree[v] = {0, 179};
        while (v != 1) {
            v /= 2;
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void upd1(int v) {
        v += sz;
        tree[v] = {-1, v-sz};
        while (v != 1) {
            v /= 2;
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector<int> tgo(n);
    for (auto &i : tgo)
        cin >> i;
    vector<pair<int, int>> t2(n);
    for (int i = 0; i < n; ++i) {
        t2[i] = {tgo[i], i};
    }
    sort(all(t2));
    reverse(all(t2));
    vector<int> time(n, -1);
    segtree sg;
    sg.make(n);
    queue<pair<int, int>> que;
    int c = n;
    vector<int> heap;
    int t = 0;
    while (c) {
        while (!t2.empty() and t2.back().first <= t) {
            sg.upd1(t2.back().second);
            t2.pop_back();
        }
        int r;
        while (!heap.empty() and time[abs(heap[0])] != -1) {
            pop_heap(all(heap));
            heap.pop_back();
        }
        if (heap.empty())
            r = n - 1;
        else
            r = abs(heap[0]) - 1;
        pair<int, int> a = sg.getmin(0, r);
        if (a.first == -1) {
            sg.upd0(a.second);
            //cerr << " PUSH " << p << ' ' << a.second << endl;
            heap.push_back(-a.second);
            push_heap(all(heap));
            que.push({p, a.second});
        } else if (que.empty()) {
            t = t2.back().first;
        }
        int tsht;
        if (!t2.empty())
            tsht = t2.back().first - t;
        else
            tsht = 1e18;
        //cerr << "TSHT " << tsht << endl;
        if (que.front().first <= tsht) {
            t = t + que.front().first;
            time[que.front().second] = t;
            //cerr << "POP " << que.front().second << ' ' << t << endl;
            que.pop();
            c--;
        } else {
            t += tsht;
            que.front().first -= tsht;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << time[i] << ' ';
    }
}