#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Node {
    int l, r;
    long long ans = 0, sz = 1, lazy = 0;

    void leaf(int val) {
        ans = val;
    }

    void pull(const Node &a, const Node &b) {
        ans = a.ans + (a.sz % 2 ? -1 : 1) * b.ans;
        sz = a.sz + b.sz;
        DEBUG(sz, l, r, ans);
    }

    void push(long long val) {
        lazy += val;
    }

    void apply() {
        if (sz % 2)
            ans += lazy;
        lazy = 0;
    }
};

struct SegmentTree {
    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), a(n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void push(int p) {
        if (st[p].lazy) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].lazy);
                st[2*p+1].push(st[p].lazy);
            }
            st[p].apply();
        }
    }

    Node query(int p, int i, int j) {
        push(p);
        if (st[p].l == i && st[p].r == j)
            return st[p];
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m)
            return query(2*p, i, j);
        else if (i > m)
            return query(2*p+1, i, j);
        Node ret, ls = query(2*p, i, m), rs = query(2*p+1, m+1, j);
        ret.pull(ls, rs);
        return ret;
    }

    long long query(int i, int j) {
        return query(1, i, j).ans;
    }

    void update(int p, int i, int j, int val) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(val);
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, val);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, val);
        } else {
            update(2*p, i, m, val);
            update(2*p+1, m+1, j, val);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val) {
        update(1, i, j, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++)
        cin >> b[i];

    long long cur = 0;
    for (int i=0; i<n; i++)
        cur += (i % 2 ? 1 : -1) * b[i];
    vector<long long> v{cur};
    DEBUG(cur);
    for (int i=n; i<m; i++) {
        cur += b[i-n];
        DEBUG(i, cur);
        cur = -cur + (n % 2 ? -1 : 1) * b[i];
        v.push_back(cur);
    }
    DEBUG(v);

    sort(v.begin(), v.end());
    SegmentTree st(a);
    long long aa = st.st[1].ans;
    int pos = int(lower_bound(v.begin(), v.end(), -aa) - v.begin());
    long long ret = LLONG_MAX;
    if (pos < (int) v.size())
        ret = min(ret, abs(aa + v[pos]));
    if (pos > 0)
        ret = min(ret, abs(aa + v[pos-1]));
    cout << ret << "\n";
    DEBUG(aa, v, pos);
    for (int i=0; i<q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        st.update(l, r, x);
        aa = st.st[1].ans;
        pos = int(lower_bound(v.begin(), v.end(), -aa) - v.begin());
        ret = LLONG_MAX;
        DEBUG(aa, pos);
        if (pos < (int) v.size())
            ret = min(ret, abs(aa + v[pos]));
        if (pos > 0)
            ret = min(ret, abs(aa + v[pos-1]));
        cout << ret << "\n";
    }

    return 0;
}