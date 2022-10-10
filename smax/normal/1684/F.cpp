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
        int ans = -1, lazy = -1, l, r;

        void leaf(int val) {
            ans = val;
        }

        void pull(const Node &a, const Node &b) {
            ans = max(a.ans, b.ans);
        }

        void push(int val) {
            lazy = max(lazy, val);
        }

        void apply() {
            ans = max(ans, lazy);
            lazy = -1;
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        vector<vector<int>> interL(n), interR(n);
        for (int i=0; i<m; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            interL[l].push_back(r);
            interR[r].push_back(l);
        }

        int ri = -1;
        map<int, int> last;
        map<int, vector<int>> mp;
        SegmentTree st(n);
        for (int r=0; r<n; r++) {
            if (last.contains(a[r]))
                st.update(0, last[a[r]], last[a[r]]);
            last[a[r]] = r;
            mp[a[r]].push_back(r);
            for (int l : interR[r])
                ri = max(ri, st.query(l, r));
        }
        DEBUG(ri);

        int ret = INT_MAX, reach = -1;
        vector<bool> fail(n);
        for (int l=0; l<n; l++) {
            DEBUG(l, ri);
            ret = min(ret, max(ri, l - 1) - l + 1);
            for (int r : interL[l])
                reach = max(reach, r);
            DEBUG(reach);
            auto &v = mp[a[l]];
            auto it = upper_bound(v.begin(), v.end(), max(reach, l));
            if (it != v.begin()) {
                it--;
                auto cur = lower_bound(v.begin(), v.end(), l);
                DEBUG(*cur, *it);
                if (cur != it) {
                    int pos = *it;
                    ri = max(ri, pos);
                    pos = *next(cur);
                    fail[pos] = true;
                }
            }
            if (fail[l])
                break;
        }
        cout << ret << "\n";
    }

    return 0;
}