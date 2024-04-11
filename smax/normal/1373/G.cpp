#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

struct SegmentTree {
    int n;
    vector<int> a, st, lazy;

    SegmentTree(int _n) : n(_n), st(4*n), lazy(4*n) {}

    SegmentTree(const vector<int> &_a) : n(_a.size()), a(_a), st(4*n), lazy(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] += a[l];
            return;
        }

        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void push(int p, int l, int r) {
        if (lazy[p]) {
            st[p] += lazy[p];
            if (l != r) {
                lazy[2*p] += lazy[p];
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    int query(int p, int l, int r, int i, int j) {
        push(p, l, r);

        if (i > r || j < l)
            return 0;
        if (i <= l && r <= j)
            return st[p];

        int m = (l + r) / 2;
        return max(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
    }

    int query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }

    void update(int p, int l, int r, int i, int j, int val) {
        push(p, l, r);

        if (i > r || j < l)
            return;
        if (i <= l && r <= j) {
            st[p] += val;
            if (l != r) {
                lazy[2*p] += val;
                lazy[2*p+1] += val;
            }
            return;
        }

        int m = (l + r) / 2;
        update(2*p, l, m, i, j, val);
        update(2*p+1, m+1, r, i, j, val);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val) {
        update(1, 0, n-1, i, j, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(2*n);
    for (int i=0; i<2*n; i++)
        a[i] = i - (n - 1);
    SegmentTree st(a);

    set<pair<int, int>> pts;
    multiset<int> mx;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        y--;
        int idx = abs(x - k) + y;
        if (pts.count({x, y})) {
            pts.erase({x, y});
            mx.erase(mx.find(idx));
            st.update(0, idx - 1, -1);
        } else {
            pts.insert({x, y});
            mx.insert(idx);
            st.update(0, idx - 1, 1);
        }
        cout << (mx.empty() ? 0 : max(st.query(0, *mx.rbegin()), 0)) << "\n";
    }

    return 0;
}