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

struct Node {
    int ans = 0, lazy = -1, l, r;

    void leaf(int val) {
        ans = val;
    }

    void pull(Node &a, Node &b) {
        ans = a.ans + b.ans;
    }

    void push(int val) {
        lazy = val;
    }

    void apply() {
        ans = (r - l + 1) * lazy;
        lazy = -1;
    }
};

struct SegmentTree {
    int n;
    string s;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const string &_s) : n(_s.size()), s(_s), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(s[l] - '0');
            return;
        }

        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void push(int p) {
        if (st[p].lazy != -1) {
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

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        string s, f;
        cin >> n >> q >> s >> f;
        vector<pair<int, int>> queries;
        for (int i=0; i<q; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            queries.emplace_back(l, r);
        }
        swap(s, f);
        reverse(queries.begin(), queries.end());
        SegmentTree st(s);
        bool ok = true;
        for (auto [l, r] : queries) {
            int sz = r - l + 1, one = st.query(l, r), zero = sz - one;
            if (one * 2 < sz) {
                assert(zero * 2 >= sz);
                st.update(l, r, 0);
            } else if (zero * 2 < sz) {
                st.update(l, r, 1);
            } else {
                ok = false;
            }
        }
        for (int i=0; i<n; i++)
            ok &= st.query(i, i) == int(f[i] - '0');
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}