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

// 00, 01, 10, 11
struct Node {
    int l, r, pref[4], suff[4], ans[2];
    bool lazy = false;

    void leaf(char c) {
        pref[0] = suff[0] = c == '<';
        pref[3] = suff[3] = c == '>';
        pref[1] = pref[2] = suff[1] = suff[2] = ans[0] = ans[1] = 1;
    }

    void pull(const Node &a, const Node &b) {
        pref[0] = a.pref[0] + (a.pref[0] == a.size() ? b.pref[0] : 0);
        pref[1] = max(a.pref[0] + (a.pref[0] == a.size() ? max(b.pref[1], b.pref[3]) : 0), a.pref[1] + (a.pref[1] == a.size() ? b.pref[3] : 0));
        pref[2] = max(a.pref[2] + (a.pref[2] == a.size() ? b.pref[0] : 0), a.pref[3] + (a.pref[3] == a.size() ? max(b.pref[0], b.pref[2]) : 0));
        pref[3] = a.pref[3] + (a.pref[3] == a.size() ? b.pref[3] : 0);
        suff[0] = b.suff[0] + (b.suff[0] == b.size() ? a.suff[0] : 0);
        suff[1] = max(b.suff[1] + (b.suff[1] == b.size() ? a.suff[0] : 0), b.suff[3] + (b.suff[3] == b.size() ? max(a.suff[0], a.suff[1]) : 0));
        suff[2] = max(b.suff[0] + (b.suff[0] == b.size() ? max(a.suff[2], a.suff[3]) : 0), b.suff[2] + (b.suff[2] == b.size() ? a.suff[3] : 0));
        suff[3] = b.suff[3] + (b.suff[3] == b.size() ? a.suff[3] : 0);
        ans[0] = max({a.ans[0], b.ans[0], a.suff[0] + max(b.pref[1], b.pref[3]), a.suff[1] + b.pref[3]});
        ans[1] = max({a.ans[1], b.ans[1], max(a.suff[2], a.suff[3]) + b.pref[0], a.suff[3] + b.pref[2]});
    }

    void push() {
        lazy ^= true;
    }

    void apply() {
        swap(pref[0], pref[3]);
        swap(pref[1], pref[2]);
        swap(suff[0], suff[3]);
        swap(suff[1], suff[2]);
        swap(ans[0], ans[1]);
        lazy = false;
    }

    int size() const {
        return r - l + 1;
    }
};

struct SegmentTree {
    int n;
    string s;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), s(n, ' '), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const string &_s) : n((int) _s.size()), s(_s), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(s[l]);
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
                st[2*p].push();
                st[2*p+1].push();
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
            st[p].push();
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

    int n, q;
    string s;
    cin >> n >> q >> s;
    SegmentTree st(s);
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        st.update(l, r);
        Node ret = st.query(l, r);
        cout << max({ret.pref[0], ret.suff[3], ret.ans[1]}) << "\n";
    }

    return 0;
}