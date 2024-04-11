#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct SegmentTree{
    int n;
    vector<int> tree;
    SegmentTree() = delete;
    SegmentTree(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int l, int r, int x) {
        for (int i = l; i <= r; ++i){
            tree[i] += x;
        }
    }
    int get() {
        return *max_element(all(tree));
    }
};

int n, k;
vector<int> a;
vector<vector<int>> nxt;

void check(vector<pair<int, int>> ans) {
    assert(ans.size() == n);
    SegmentTree tree(n * k);
    for (auto i : ans) {
        assert(i.first != -1);
        tree.upd(i.first, i.second, 1);
    }
    assert(tree.get() <= ((n + (k - 1) - 1) / (k - 1)));
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> k;
    a.resize(n * k);
    vin(a);
    nxt.resize(n * k, vector<int>(n, -1));

    for (int i = n * k - 1; i >= 0; --i) {
        a[i]--;
        if (i + 1 < n * k) {
            for (int j = 0; j < n; ++j) {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][a[i + 1]] = i + 1;
        }
    }

    SegmentTree tree(n * k);
    vector<pair<int, int>> ans(n, make_pair(-1, -1));
    vector<bool> used(n);
    
    for (int i = n * k - 1; i >= 0; --i) {
        if (used[a[i]]) continue;
        if (nxt[i][a[i]] == -1) continue;
        int l = i;
        int r = nxt[i][a[i]];
        tree.upd(l, r, 1);
        if (tree.get() > ((n + (k - 1) - 1) / (k - 1))) {
            tree.upd(l, r, -1);
            continue;
        }
        used[a[i]] = true;
        // ans.push_back({l, r});
        ans[a[i]] = {l, r};
    }
    for (auto i : ans) {
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
    cout.flush();
    check(ans);

    return 0;
}