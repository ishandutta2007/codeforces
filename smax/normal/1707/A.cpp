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

const int INF = 1e9;

int q;

struct SegmentTree {
    struct Node {
        int ans = 0, sum = 0, lazy = 0, l, r;

        void leaf(int val, bool f) {
            ans = f ? val : -INF;
            sum = !f;
        }

        void pull(const Node &a, const Node &b) {
            ans = max(a.ans, b.ans);
            sum = a.sum + b.sum;
        }

        void push(int val) {
            lazy += val;
        }

        void apply() {
            ans += lazy;
            lazy = 0;
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
            st[p].leaf(a[l], true);
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

    int query(int i, int j) {
        return query(1, i, j).sum;
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

    int go(int p, int i, int j) {
        if (i > st[p].r || j < st[p].l || st[p].ans <= q)
            return -1;
        if (st[p].l == st[p].r) {
            st[p].leaf(st[p].ans, false);
            return st[p].l;
        }
        push(2 * p);
        push(2 * p + 1);
        int ret = go(2 * p, i, j);
        if (ret == -1)
            ret = go(2 * p + 1, i, j);
        st[p].pull(st[2*p], st[2*p+1]);
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> q;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        vector<int> pref(n);
        for (int i=0; i<n; i++)
            pref[i] = (i > 0 ? pref[i-1] : 0) + (a[i] <= q);

        int ret = 0, best = -1;
        SegmentTree st(n);
        for (int i=n-1; i>=0; i--) {
            st.update(i, i, a[i]);
            int cur = st.go(1, i, n - 1);
            while (cur != -1) {
                if (cur + 1 < n)
                    st.update(cur + 1, n - 1, 1);
                cur = st.go(1, i, n - 1);
            }
            if (st.query(i, n - 1) <= q) {
                cur = n - i + (i > 0 ? pref[i-1] : 0);
                if (cur > ret) {
                    ret = cur;
                    best = i;
                }
            }
        }

        for (int i=0; i<best; i++)
            cout << (a[i] <= q);
        for (int i=best; i<n; i++)
            cout << 1;
        cout << "\n";
    }

    return 0;
}