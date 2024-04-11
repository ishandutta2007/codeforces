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
        int l, r, cnt;
        long long sum, sumsq, lazy = 0;

        void leaf(int val) {
            if (val == -1) {
                cnt = sum = sumsq = 0;
            } else {
                cnt = 1;
                sum = val;
                sumsq = (long long) val * val;
            }
        }

        void pull(const Node &a, const Node &b) {
            cnt = a.cnt + b.cnt;
            sum = a.sum + b.sum;
            sumsq = a.sumsq + b.sumsq;
        }

        void push(long long val) {
            lazy += val;
        }

        void apply() {
            sumsq += 2 * sum * lazy + cnt * lazy * lazy;
            sum += cnt * lazy;
            lazy = 0;
        }
    };

    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), a(n, -1), st(4*n) {
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

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, d;
    cin >> q >> d;
    vector<bool> has(MAX);
    SegmentTree st(MAX);
    for (int i=0; i<q; i++) {
        int a;
        cin >> a;
        if (has[a]) {
            st.update(max(a - d, 0), a - 1, -1);
            st.point(a, -1);
        } else {
            st.update(max(a - d, 0), a - 1, 1);
            st.point(a, st.query(a + 1, min(a + d, MAX - 1)).cnt);
        }
        has[a] = !has[a];
        cout << (st.st[1].sumsq - st.st[1].sum) / 2 << "\n";
    }

    return 0;
}