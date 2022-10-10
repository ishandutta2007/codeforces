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
    int mn, lazy = 0, l, r;
    long long sum;

    void leaf(int val) {
        sum = mn = val;
    }

    void pull(Node &a, Node &b) {
        sum = a.sum + b.sum;
        mn = b.mn;
    }

    void push(int val) {
        lazy = val;
    }

    void apply() {
        sum = (long long) (r - l + 1) * lazy;
        mn = lazy;
        lazy = 0;
    }
};

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

    void setMax(int p, int x, int y) {
        if (st[p].l == st[p].r) {
            if (st[p].mn < y && st[p].l <= x)
                update(st[p].l, x, y);
            return;
        }
        push(2*p);
        push(2*p+1);
        if (st[2*p].mn < y)
            setMax(2*p, x, y);
        else
            setMax(2*p+1, x, y);
    }

    int leftMost(int p, int x, int y) {
        if (st[p].l == st[p].r) {
            if (st[p].mn <= y)
                return max(st[p].l, x);
            return n;
        }
        push(2*p);
        push(2*p+1);
        if (st[2*p].mn <= y)
            return leftMost(2*p, x, y);
        return leftMost(2*p+1, x, y);
    }

    int rightMost(int p, long long y) {
        if (st[p].l == st[p].r) {
            if (st[p].sum > y)
                return st[p].l - 1;
            return st[p].l;
        }
        push(2*p);
        push(2*p+1);
        if (st[2*p].sum >= y)
            return rightMost(2*p, y);
        return rightMost(2*p+1, y-st[2*p].sum);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    SegmentTree st(a);
    for (int i=0; i<q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1)
            st.setMax(1, x, y);
        else {
            int l = st.leftMost(1, x, y), ret = 0;
            while (l < n) {
                long long sub = l == 0 ? 0 : st.query(0, l - 1);
                int r = st.rightMost(1, y + sub);
                assert(l <= r);
                ret += r - l + 1;
                x = r + 1;
                y -= st.query(l, r);
                l = st.leftMost(1, x, y);
            }
            cout << ret << "\n";
        }
    }

    return 0;
}