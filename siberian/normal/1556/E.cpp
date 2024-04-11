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

#define int ll

struct Node{
    int minVal, maxVal;
    Node() {
        minVal = 1e18;
        maxVal = -1e18;
    }
    Node(int a) : minVal(a), maxVal(a) {}
};

Node merge(const Node& a, const Node& b) {
    Node ans;
    ans.minVal = min(a.minVal, b.minVal);
    ans.maxVal = max(a.maxVal, b.maxVal);
    return ans;
}

struct SegmentTree{
    int n;
    vector<Node> tree;
    SegmentTree() {}
    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = Node(a[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm, a);
            build(v * 2 + 1, tm, tr, a);
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(n * 4);
        build(1, 0, n, a);
    }
    Node get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return Node();
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return merge(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
    }
    Node get(int l, int r) {
        return get(1, 0, n, l, r + 1);
    }
};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vin(a);
    vector<int> b(n);
    vin(b);
    for (int i = 0; i < n; ++i) {
        b[i] -= a[i];
        if (i > 0) b[i] += b[i - 1];
    }
    SegmentTree st(b);
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        Node have = st.get(l, r);
        int prev = (l > 0 ? b[l - 1] : 0);
        have.minVal -= prev;
        have.maxVal -= prev;
        if (have.minVal < 0 || b[r] - prev != 0) {
            cout << "-1\n";
        } else {
            cout << have.maxVal << '\n';
        }
    }
    return 0;
}