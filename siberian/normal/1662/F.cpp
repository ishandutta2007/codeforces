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

struct NodeMin{
    int max_val = INT_MAX, pos = -1;
    NodeMin() = default;
    NodeMin(int _max_val, int _pos) : max_val(_max_val), pos(_pos) {}
    bool operator<(const NodeMin& other) const {
        return max_val > other.max_val;
    }
};

struct SegmentTreeMin{
    int n;
    vector<NodeMin> tree;
    SegmentTreeMin() = default;
    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = {a[tl], tl};
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm, a);
            build(v * 2 + 1, tm, tr, a);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    SegmentTreeMin(const vector<int>& a) : n(a.size()), tree(n * 4, NodeMin()) {
        build(1, 0, n, a);
    }
    void upd(int v, int tl, int tr, int pos, NodeMin val) {
        if (tl >= pos + 1 || tr <= pos) return;
        if (tl == tr - 1) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            upd(v * 2, tl, tm, pos, val);
            upd(v * 2 + 1, tm, tr, pos, val);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void upd(int pos, NodeMin val) {
        upd(1, 0, n, pos, val);
    }
    void set_inf(int pos) {
        upd(pos, NodeMin(INT_MAX, -1));
    }
    NodeMin get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return {};
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return max(
            get(v * 2, tl, tm, l, r),
            get(v * 2 + 1, tm, tr, l, r)
            );
    }
    NodeMin get(int l, int r) {
        chkmin(r, n - 1);
        chkmax(l, 0);
        if (l > r) return {};
        return get(1, 0, n, l, r + 1);
    }
};

struct NodeMax{
    int max_val = INT_MIN, pos = -1;
    NodeMax() = default;
    NodeMax(int _max_val, int _pos) : max_val(_max_val), pos(_pos) {}
    bool operator<(const NodeMax& other) const {
        return max_val < other.max_val;
    }
};

struct SegmentTreeMax{
    int n;
    vector<NodeMax> tree;
    SegmentTreeMax() = default;
    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = {a[tl], tl};
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm, a);
            build(v * 2 + 1, tm, tr, a);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    SegmentTreeMax(const vector<int>& a) : n(a.size()), tree(n * 4, NodeMax()) {
        build(1, 0, n, a);
    }
    void upd(int v, int tl, int tr, int pos, NodeMax val) {
        if (tl >= pos + 1 || tr <= pos) return;
        if (tl == tr - 1) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            upd(v * 2, tl, tm, pos, val);
            upd(v * 2 + 1, tm, tr, pos, val);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void upd(int pos, NodeMax val) {
        upd(1, 0, n, pos, val);
    }
    void set_inf(int pos) {
        upd(pos, NodeMax(INT_MIN, -1));
    }
    NodeMax get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return {};
        if (tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return max(
            get(v * 2, tl, tm, l, r),
            get(v * 2 + 1, tm, tr, l, r)
            );
    }
    NodeMax get(int l, int r) {
        chkmin(r, n - 1);
        chkmax(l, 0);
        if (l > r) return {};
        return get(1, 0, n, l, r + 1);
    }
};

void solve() {
    int n;
    cin >> n;
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    vector<int> p(n);
    vin(p);

    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; ++i) {
        d1[i] = i - p[i];
        d2[i] = p[i] + i;
    }

    SegmentTreeMax st_first_case(p), st_second_case_j_i(d2);
    SegmentTreeMin st_second_case_i_j(d1);
    vector<int> d(n, -1);
    queue<int> q;
    d[from] = 0;
    q.push(from);

    auto clear = [&] (int pos) {
        st_first_case.set_inf(pos);
        st_second_case_i_j.set_inf(pos);
        st_second_case_j_i.set_inf(pos);
    };

    auto upd = [&] (int cur, int pos) {
        // cerr << "cur = " << cur << " pos = " << pos << endl; 
        assert(d[pos] == -1);
        d[pos] = d[cur] + 1;
        q.push(pos);
        clear(pos);
    };

    clear(from);

    while (!q.empty()) {
        int cur = q.front();
        // cerr << "cur = " << cur << endl;
        // if (cur == 9) {
        //     cerr << "kek" << endl;
        // }
        q.pop();
        int pos;
        while ((pos = st_first_case.get(cur, p[cur] + cur).pos) != -1) {
            if (p[pos] < p[cur]) break;
            // cerr << "1" << endl;
            upd(cur, pos);
        }
        while ((pos = st_first_case.get(cur - p[cur], cur).pos) != -1) {
            if (p[pos] < p[cur]) break;
            // cerr << "2" << endl;
            upd(cur, pos);
        }
        while ((pos = st_second_case_i_j.get(cur, cur + p[cur]).pos) != -1) {
            if (pos - p[pos] > cur) break;
            // cerr << "3" << endl;
            upd(cur, pos);
        }
        while ((pos = st_second_case_j_i.get(cur - p[cur], cur).pos) != -1) {
            if (p[pos] + pos < cur) break;
            // cerr << "4" << endl;
            upd(cur, pos);
        }
    }
    cout << d[to] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}