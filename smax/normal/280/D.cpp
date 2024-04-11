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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct SegmentTree {
    struct Node {
        int l, r, sum[2];
        pair<int, int> pref[2], suff[2];
        array<int, 3> ans[2];
        bool lazy = false;

        void leaf(int v) {
            sum[0] = v;
            pref[0] = suff[0] = {v, l};
            ans[0] = {v, l, l};
            sum[1] = -v;
            pref[1] = suff[1] = {-v, l};
            ans[1] = {-v, l, l};
        }

        void pull(const Node &a, const Node &b) {
            for (int i=0; i<2; i++) {
                sum[i] = a.sum[i] + b.sum[i];
                pref[i] = max(a.pref[i], {a.sum[i] + b.pref[i].first, b.pref[i].second});
                suff[i] = max(b.suff[i], {a.suff[i].first + b.sum[i], a.suff[i].second});
                ans[i] = max({a.ans[i], b.ans[i], {a.suff[i].first + b.pref[i].first, a.suff[i].second, b.pref[i].second}});
            }
        }

        void push(bool val) {
            lazy ^= val;
        }

        void apply() {
            swap(sum[0], sum[1]);
            swap(pref[0], pref[1]);
            swap(suff[0], suff[1]);
            swap(ans[0], ans[1]);
            lazy = false;
        }
    };

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

    Node query(int i, int j) {
        return query(1, i, j);
    }

    void update(int p, int i, int j) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(true);
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

    void point(int p, int i, int val) {
        if (st[p].l == st[p].r) {
            st[p].leaf(val);
            return;
        }
        push(2 * p);
        push(2 * p + 1);
        int m = (st[p].l + st[p].r) / 2;
        if (i <= m)
            point(2 * p, i, val);
        else
            point(2 * p + 1, i, val);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void point(int i, int val) {
        point(1, i, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int m;
    cin >> m;
    SegmentTree st(a);
    for (int i=0; i<m; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            int x, v;
            cin >> x >> v;
            x--;
            st.point(x, v);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            int ret = 0;
            vector<pair<int, int>> subs;
            while (k--) {
                auto [v, x, y] = st.query(l, r).ans[0];
                if (v <= 0)
                    break;
                ret += v;
                subs.emplace_back(x, y);
                st.update(x, y);
            }
            for (auto [x, y] : subs)
                st.update(x, y);
            cout << ret << "\n";
        }
    }

    return 0;
}