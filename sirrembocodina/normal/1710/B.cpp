#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

vector<int> t1, t2, t3;

void build_tree(int v, int l, int r, vector<pair<int, int>>& a) {
    if (r - l == 1) {
        t1[v] = a[l].second - a[l].first;
        t2[v] = a[l].second + a[l].first;
        t3[v] = a[l].second;
        return;
    }
    int mid = (l + r) / 2;
    build_tree(2 * v + 1, l, mid, a);
    build_tree(2 * v + 2, mid, r, a);
    t1[v] = max(t1[2 * v + 1], t1[2 * v + 2]);
    t2[v] = max(t2[2 * v + 1], t2[2 * v + 2]);
    t3[v] = max(t3[2 * v + 1], t3[2 * v + 2]);
}

int get_max1(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return -2e18;
    }
    if (L <= l && r <= R) {
        return t1[v];
    }
    int mid = (l + r) / 2;
    return max(get_max1(2 * v + 1, l, mid, L, R),
               get_max1(2 * v + 2, mid, r, L, R));
}

int get_max2(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return -2e18;
    }
    if (L <= l && r <= R) {
        return t2[v];
    }
    int mid = (l + r) / 2;
    return max(get_max2(2 * v + 1, l, mid, L, R),
               get_max2(2 * v + 2, mid, r, L, R));
}

int get_max3(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return -2e18;
    }
    if (L <= l && r <= R) {
        return t3[v];
    }
    int mid = (l + r) / 2;
    return max(get_max3(2 * v + 1, l, mid, L, R),
               get_max3(2 * v + 2, mid, r, L, R));
}

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), p(n);
        map<int, int> d;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> p[i];
            d[x[i] - p[i]]++;
            d[x[i]] -= 2;
            d[x[i] + p[i]]++;
        }

        vector<pair<int, int>> a;
        int add = 0;
        int last_x = -2e18;
        int last_d = 0;
        for (auto e: d) {
            add += last_d * (e.first - last_x);
            last_x = e.first;
            last_d += e.second;
            a.push_back({e.first, add});
            //cerr << e.first << ' ' << add << endl;
        }

        int tree_sz = 1;
        while (tree_sz < 2 * a.size()) {
            tree_sz *= 2;
        }
        t1.resize(tree_sz);
        t2.resize(tree_sz);
        t3.resize(tree_sz);
        build_tree(0, 0, a.size(), a);

        string ans;
        for (int i = 0; i < n; i++) {
            int ind1 = lower_bound(a.begin(), a.end(), make_pair(x[i] - p[i], int(-2e18))) - a.begin();
            int ind2 = lower_bound(a.begin(), a.end(), make_pair(x[i], int(-2e18))) - a.begin();
            int ind3 = lower_bound(a.begin(), a.end(), make_pair(x[i] + p[i], int(-2e18))) - a.begin();
            /*cerr << ind1 << ' ' << ind2 << ' ' << ind3 << ' ' << endl;
            cerr << get_max3(0, 0, a.size(), 0, ind1) << endl;
            cerr << get_max2(0, 0, a.size(), ind1, ind2) << endl;
            cerr << get_max1(0, 0, a.size(), ind2, ind3) << endl;
            cerr << get_max3(0, 0, a.size(), ind3, a.size()) << endl;*/
            if (get_max3(0, 0, a.size(), 0, ind1) > m ||
                get_max1(0, 0, a.size(), ind1, ind2) > m + p[i] - x[i] ||
                get_max2(0, 0, a.size(), ind2, ind3) > m + p[i] + x[i] ||
                get_max3(0, 0, a.size(), ind3, a.size()) > m) {
                ans.push_back('0');
            } else {
                ans.push_back('1');
            }
        }
        cout << ans << '\n';
    }
}