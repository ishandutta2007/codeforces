#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

struct SegmentTree {
    int n;
    vector<int> a, st;

    SegmentTree(int _n) : n(_n), st(4*n) {}

    SegmentTree(vector<int> &_a) {
        a = _a;
        n = a.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = a[l];
            return;
        }

        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p] = st[2*p] + st[2*p+1];
    }

    int leftMost(int p, int l, int r) {
        if (l == r)
            return l;

        int m = (l + r) / 2;
        if (st[2*p] > 0)
            return leftMost(2*p, l, m);
        return leftMost(2*p+1, m+1, r);
    }

    int query(int p, int l, int r, int i, int j) {
        if (i > r || j < l || st[p] == 0)
            return -1;
        if (i <= l && r <= j)
            return leftMost(p, l, r);

        int m = (l + r) / 2, ret = query(2*p, l, m, i, j);
        if (ret == -1)
            ret = query(2*p+1, m+1, r, i, j);
        return ret;
    }

    int query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }

    void update(int p, int l, int r, int idx) {
        if (l == r) {
            st[p]--;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m)
            update(2*p, l, m, idx);
        else
            update(2*p+1, m+1, r, idx);
        st[p] = st[2*p] + st[2*p+1];
    }

    void update(int idx) {
        update(1, 0, n-1, idx);
    }
};

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    vector<int> cnt(n);
    for (int i=0; i<n; i++) {
        int b;
        cin >> b;
        cnt[b]++;
    }

    SegmentTree st(cnt);
    for (int i=0; i<n; i++) {
        int c = st.query((n - a[i]) % n, n - 1);
        if (c == -1)
            c = st.query(0, (n - a[i]) % n - 1);
        cout << (a[i] + c) % n << " ";
        st.update(c);
    }
    cout << "\n";

    return 0;
}