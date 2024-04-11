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

const int MAX = 105;

struct Node {
    int ans, l, r;
    bool f;
    vector<int> lazy;

    Node() : ans(0), l(0), r(0), f(false), lazy(MAX) {
        iota(lazy.begin(), lazy.end(), 0);
    }

    void leaf(int val) {
        ans = val;
    }

    void pull(Node &a, Node &b) {}

    void push(const vector<int> &nxt) {
        f = true;
        for (int i=0; i<MAX; i++)
            lazy[i] = nxt[lazy[i]];
    }

    void apply() {
        ans = lazy[ans];
        f = false;
        iota(lazy.begin(), lazy.end(), 0);
    }
};

vector<int> temp(MAX);

struct SegmentTree {
    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(const vector<int> &_a) : n(_a.size()), a(_a), st(4*n) {
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
        if (st[p].f) {
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

    int query(int i, int j) {
        return query(1, i, j).ans;
    }

    void update(int p, int i, int j) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(temp);
            push(p);
            return;
        }

        push(p);

        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j);
        } else {
            update(2*p, i, m);
            update(2*p+1, m+1, j);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j) {
        update(1, i, j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    SegmentTree st(a);
    iota(temp.begin(), temp.end(), 0);
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        l--, r--;
        temp[x] = y;
        st.update(l, r);
        temp[x] = x;
    }

    for (int i=0; i<n; i++)
        cout << st.query(i, i) << " ";
    cout << "\n";

    return 0;
}