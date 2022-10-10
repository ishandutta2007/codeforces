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
    int mn = 0, cnt = 1, lazy = 0, l, r;

    void pull(Node &a, Node &b) {
        mn = min(a.mn, b.mn);
        cnt = 0;
        if (a.mn == mn)
            cnt += a.cnt;
        if (b.mn == mn)
            cnt += b.cnt;
    }

    void push(int val) {
        lazy += val;
    }

    void apply() {
        mn += lazy;
        lazy = 0;
    }
};

struct SegmentTree {
    int n;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l != r) {
            int m = (l + r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
        }
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
        Node ret = query(1, i, j);
        return ret.mn == 0 ? ret.cnt : 0;
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

    int n;
    cin >> n;

    vector<vector<int>> pos(n, vector<int>{-1});
    SegmentTree st(n);
    long long ret = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        a--;
        st.update(pos[a].back() + 1, i, 1);
        if ((int) pos[a].size() >= 3)
            st.update(pos[a][(int)pos[a].size()-3] + 1, pos[a][(int)pos[a].size()-2], -1);
        if ((int) pos[a].size() >= 4)
            st.update(pos[a][(int)pos[a].size()-4] + 1, pos[a][(int)pos[a].size()-3], 1);
        ret += st.query(0, i);
        pos[a].push_back(i);
    }
    cout << ret << "\n";

    return 0;
}