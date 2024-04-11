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

#define MAXN 200005

const int INF = 1e9;

struct SegmentTree {
    int n;
    vector<int> st, lazy;

    SegmentTree(int _n) : n(_n), st(4*n, -INF), lazy(4*n) {}

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

    void update(int p, int l, int r, int idx, int val) {
        push(p, l, r);

        if (idx < l || idx > r)
            return;
        if (l == r) {
            st[p] = max(st[p], val);
            return;
        }

        int m = (l + r) / 2;
        update(2*p, l, m, idx, val);
        update(2*p+1, m+1, r, idx, val);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int l[MAXN], r[MAXN], t[MAXN];
vector<pair<int, int>> seg[2*MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i] >> t[i];
        t[i]--;
        v.push_back(l[i]);
        v.push_back(r[i]);
    }

    sort(v.begin(), v.end());
    map<int, int> compression;
    for (int i=0; i<2*n; i++)
        compression[v[i]] = i + 1;

    for (int i=0; i<n; i++)
        seg[compression[r[i]]].emplace_back(compression[l[i]], t[i]);

    SegmentTree st0(2 * n + 1), st1(2 * n + 1);
    st0.update(0, 0);
    st1.update(0, 0);
    int ret = 0;
    for (int i=1; i<=2*n; i++) {
        for (auto &p : seg[i]) {
            if (p.second)
                st0.update(0, p.first - 1, 1);
            else
                st1.update(0, p.first - 1, 1);
        }
        for (auto &p : seg[i]) {
            int cur = (p.second ? st0.query(0, p.first - 1) : st1.query(0, p.first - 1));
            ret = max(ret, cur);
            if (p.second)
                st1.update(i, cur);
            else
                st0.update(i, cur);
        }
    }

    cout << ret << "\n";

    return 0;
}