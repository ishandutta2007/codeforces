#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
struct segtree{
    int sz;
    vector<int> tree;
    void make(int n) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, {});
    }
    void add(int l, int r, int x) {
        l += sz;r += sz;
        while (l < r) {
            if (l % 2 == 1) {
                tree[l] += x;
                l++;
            }
            if (r % 2 == 0) {
                tree[r] += x;
                r--;
            }
            l /= 2;
            r /= 2;
        }
        if (l == r)
            tree[l] += x;
    }
    int get(int v) {
        v += sz;
        int res = 0;
        while (v) {
            res += tree[v];
            v /= 2;
        }
        return res;
    }
};
set<array<int32_t, 3>> st;
auto getiter(int32_t x) {
    auto it = st.lower_bound({x+1, -1, -1});
    if (it == st.begin())
        return st.end();
    return --it;
}
segtree sg;
vector<int> clrs;

void sters(array<int32_t, 3> ite) {
    sg.add(ite[0], ite[1], -clrs[ite[2]]);
    st.erase(ite);
}
void stadd(array<int32_t, 3> ele) {
    sg.add(ele[0], ele[1], clrs[ele[2]]);
    st.insert(ele);
}
auto addseg(int32_t l, int32_t r, int32_t vl) {
    int32_t l1 = l;
    while (l <= r) {
        auto it = getiter(l);
        if (it == st.end()) {
            exit(1);
        }
        auto itsav = *it;
        sters(itsav);
        if (itsav[1] > r) {
            array<int32_t, 3> abb = itsav;
            abb[0] = r + 1;
            stadd(abb);
        }
        if (itsav[0] < l) {
            array<int32_t, 3> abb = itsav;
            abb[1] = l - 1;
            stadd(abb);
        }
        l = itsav[1] + 1;
    }
    stadd(array<int32_t, 3>{l1, r, vl});
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    sg.make(n);
    clrs.assign(n + 1, {});
    vector<array<int, 4>> zpr(q);
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        if (s == "Color") {
            zpr[i][0] = 0;
            cin >> zpr[i][1] >> zpr[i][2] >> zpr[i][3];
            zpr[i][1]--;
            zpr[i][2]--;
        }
        if (s == "Add") {
            zpr[i][0] = 1;
            cin >> zpr[i][1] >> zpr[i][2];
            clrs[zpr[i][1]] += zpr[i][2];
        }
        if (s == "Query") {
            zpr[i][0] = 2;
            cin >> zpr[i][1];
            zpr[i][1]--;
        }
    }
    stadd({0, (int32_t)n - 1, 1});
    for (int i = 0; i < q; ++i) {
        if (zpr[i][0] == 0) {
            addseg(zpr[i][1], zpr[i][2], zpr[i][3]);
        }
        if (zpr[i][0] == 1) {
            clrs[zpr[i][1]] -= zpr[i][2];
        }
        if (zpr[i][0] == 2) {
            cout << sg.get(zpr[i][1]) - clrs[(*getiter(zpr[i][1]))[2]] << '\n';
        }
    }
}