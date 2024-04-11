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

long long ntot[10];

struct SegmentTree {
    struct Node {
        int l, r;
        bool lazy;
        long long sum;
        array<int, 10> nxt;
        array<long long, 10> tot;

        Node() {
            iota(nxt.begin(), nxt.end(), 0);
        }

        void leaf(int val) {
            sum = val;
            for (int i=0; i<10; i++) {
                nxt[i] = i;
                tot[i] = 0;
            }
            lazy = false;
            int pw = 1;
            while (val > 0) {
                tot[val % 10] += pw;
                val /= 10;
                pw *= 10;
            }
            for (int i=0; i<10; i++)
                DEBUG(i, sum, tot[i]);
        }

        void pull(const Node &a, const Node &b) {
            sum = a.sum + b.sum;
            for (int i=0; i<10; i++)
                tot[i] = a.tot[i] + b.tot[i];
        }

        void push(const array<int, 10> &other) {
            DEBUG(l, r, nxt, other);
            for (int i=0; i<10; i++)
                nxt[i] = other[nxt[i]];
            DEBUG(nxt);
            lazy = true;
        }

        void apply() {
            DEBUG(sum);
            sum = 0;
            for (int i=0; i<10; i++) {
                DEBUG(l, r, sum, i, nxt[i], tot[i]);
                sum += nxt[i] * tot[i];
                ntot[nxt[i]] += tot[i];
            }
            for (int i=0; i<10; i++) {
                tot[i] = ntot[i];
                ntot[i] = 0;
                nxt[i] = i;
            }
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
                st[2*p].push(st[p].nxt);
                st[2*p+1].push(st[p].nxt);
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

    void update(int p, int i, int j, int x, int y) {
        if (st[p].l == i && st[p].r == j) {
            array<int, 10> cur;
            for (int i=0; i<10; i++)
                cur[i] = i;
            cur[x] = y;
            st[p].push(cur);
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, x, y);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, x, y);
        } else {
            update(2*p, i, m, x, y);
            update(2*p+1, m+1, j, x, y);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int x, int y) {
        update(1, i, j, x, y);
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
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            st.update(l, r, x, y);
            DEBUG(st.query(l, r));
        } else {
            cout << st.query(l, r) << "\n";
        }
    }

    return 0;
}