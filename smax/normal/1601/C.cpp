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

template<typename T>
struct BIT {
    int n, lg;
    vector<T> bit;

    BIT(int _n) : n(_n), lg(__lg(n)), bit(n + 1) {}

    BIT(const vector<T> &a) : n((int) a.size()), lg(__lg(n)), bit(n + 1) {
        for (int i=1; i<=n; i++) {
            bit[i] += a[i-1];
            if (i + (i & -i) <= n)
                bit[i+(i&-i)] += bit[i];
        }
    }

    T query(int i) {
        T ret = 0;
        for (; i>0; i-=i&-i)
            ret += bit[i];
        return ret;
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
    }

    void update(int i, T val) {
        for (; i<=n; i+=i&-i)
            bit[i] += val;
    }

    int kth(T k) {
        int ret = 0;
        for (int i=lg; i>=0; i--) {
            ret += 1 << i;
            if (ret <= n && bit[ret] < k)
                k -= bit[ret];
            else
                ret -= 1 << i;
        }
        return ret + 1;
    }
};

struct Node {
    int ans, hans, lazy, hlazy, l, r;

    void leaf(int val) {
        ans = hans = val;
        lazy = hlazy = 0;
    }

    void pull(Node &a, Node &b) {
        ans = min(a.ans, b.ans);
        hans = min(a.hans, b.hans);
    }

    void pushAdd(int val) {
        lazy += val;
    }

    void pushHistoric(int val) {
        hlazy = min(hlazy, lazy + val);
    }

    void apply() {
        hans = min(hans, ans + hlazy);
        ans += lazy;
        lazy = hlazy = 0;
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
        if (st[p].l != st[p].r) {
            if (st[p].hlazy) {
                st[2*p].pushHistoric(st[p].hlazy);
                st[2*p+1].pushHistoric(st[p].hlazy);
            }
            if (st[p].lazy) {
                st[2*p].pushAdd(st[p].lazy);
                st[2*p+1].pushAdd(st[p].lazy);
            }
        }
        st[p].apply();
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
        return query(1, i, j).hans;
    }

    void update(int p, int i, int j, int val) {
        if (st[p].l == i && st[p].r == j) {
            st[p].pushHistoric(val);
            st[p].pushAdd(val);
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), compress;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            compress.push_back(a[i]);
        }
        for (int i=0; i<m; i++) {
            cin >> b[i];
            compress.push_back(b[i]);
        }

        sort(compress.begin(), compress.end());
        compress.erase(unique(compress.begin(), compress.end()), compress.end());
        int o = (int) compress.size();
        for (auto &x : a)
            x = int(lower_bound(compress.begin(), compress.end(), x) - compress.begin());
        for (auto &x : b)
            x = int(lower_bound(compress.begin(), compress.end(), x) - compress.begin());

        vector<int> inv(o);
        for (int x : a)
            if (x + 1 < o)
                inv[x+1]++;
        for (int i=1; i<o; i++)
            inv[i] += inv[i-1];

        long long ret = 0;
        BIT<int> bit(o);
        SegmentTree st(inv);
        for (int x : a) {
            ret += bit.query(x + 2, o);
            bit.update(x + 1, 1);
            if (x + 1 < o)
                st.update(x + 1, o - 1, -1);
            if (x > 0)
                st.update(0, x - 1, 1);
        }
        for (int x : b)
            ret += st.query(x, x);
        cout << ret << "\n";
    }

    return 0;
}