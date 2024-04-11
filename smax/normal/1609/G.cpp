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
        int l, r;
        long long ans, mx, lazy = 0;

        void leaf(long long val) {
            ans = mx = val;
        }

        void pull(const Node &a, const Node &b) {
            ans = a.ans + b.ans;
            mx = max(a.mx, b.mx);
        }

        void push(long long val) {
            lazy += val;
        }

        void apply() {
            ans += (r - l + 1) * lazy;
            mx += lazy;
            lazy = 0;
        }
    };

    int n;
    vector<long long> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), a(n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<long long> &_a) : n((int) _a.size()), a(_a), st(4*n) {
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

    int leftMost(long long val, int p = 1) {
        if (st[p].l == st[p].r)
            return st[p].mx > val ? st[p].l : -1;
        push(2 * p);
        push(2 * p + 1);
        if (st[2*p].mx > val)
            return leftMost(val, 2 * p);
        return leftMost(val, 2 * p + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> a(n), b(m);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++)
        cin >> b[i];

    long long tot = 0;
    for (int j=0; j<m; j++)
        tot += a[0] + b[j];
    for (int i=1; i<n; i++)
        tot += a[i] + b[m-1];

    for (int i=n-1; i>0; i--)
        a[i] -= a[i-1];
    for (int i=m-1; i>0; i--)
        b[i] -= b[i-1];
    b[0] = LLONG_MIN;
    SegmentTree st(b);

    while (q--) {
        int type, k, d;
        cin >> type >> k >> d;
        if (type == 1) {
            for (int i=n-k; i<n; i++)
                a[i] += d;
            tot += (long long) d * k * (k + 1) / 2;
            if (k == n)
                tot += d * (m - 1);
        } else {
            st.update(m - k, m - 1, d);
            tot += (long long) d * k * (k + 1) / 2 + (long long) d * k * (n - 1);
        }

        long long ret = tot;
        for (int i=1; i<n; i++) {
            int j = st.leftMost(a[i]);
            if (j == -1)
                break;
            ret += (m - j) * a[i] - st.query(j, m - 1);
        }
        cout << ret << "\n";
    }

    return 0;
}