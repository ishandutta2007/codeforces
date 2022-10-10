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
        int mx, cnt, lazy, l, r;

        void leaf(int val) {
            mx = lazy = 0;
            cnt = 1;
        }

        void pull(const Node &a, const Node &b) {
            mx = max(a.mx, b.mx);
            cnt = (mx == a.mx ? a.cnt : 0) + (mx == b.mx ? b.cnt : 0);
        }

        void push(int val) {
            lazy += val;
        }

        void apply() {
            mx += lazy;
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

    // Node query(int p, int i, int j) {
    //     push(p);
    //     if (st[p].l == i && st[p].r == j)
    //         return st[p];
    //     int m = (st[p].l + st[p].r) / 2;
    //     if (j <= m)
    //         return query(2*p, i, j);
    //     else if (i > m)
    //         return query(2*p+1, i, j);
    //     Node ret, ls = query(2*p, i, m), rs = query(2*p+1, m+1, j);
    //     ret.pull(ls, rs);
    //     return ret;
    // }

    // int query(int i, int j) {
    //     return query(1, i, j).ans;
    // }

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
    vector<long long> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    auto getNext = [&] () -> pair<vector<int>, vector<int>> {
        vector<int> stk, nxtL(n), nxtR(n);
        for (int i=0; i<n; i++) {
            while (!stk.empty() && a[stk.back()] < a[i])
                stk.pop_back();
            nxtL[i] = stk.empty() ? -1 : stk.back();
            stk.push_back(i);
        }
        stk.clear();
        for (int i=n-1; i>=0; i--) {
            while (!stk.empty() && a[stk.back()] <= a[i])
                stk.pop_back();
            nxtR[i] = stk.empty() ? n : stk.back();
            stk.push_back(i);
        }
        return {nxtL, nxtR};
    };

    auto [maxL, maxR] = getNext();
    for (long long &x : a)
        x = -x;
    auto [minL, minR] = getNext();

    vector<vector<array<int, 4>>> rects(60);
    for (int i=0; i<n; i++) {
        a[i] = -a[i];
        int cnt = __builtin_popcountll(a[i]);
        rects[cnt].push_back({maxL[i] + 1, i, maxR[i] - 1, 1});
        rects[cnt].push_back({i + 1, i, maxR[i] - 1, -1});
        rects[cnt].push_back({minL[i] + 1, i, minR[i] - 1, 1});
        rects[cnt].push_back({i + 1, i, minR[i] - 1, -1});
    }

    SegmentTree st(n);
    long long ret = 0;
    for (auto &v : rects) {
        sort(v.begin(), v.end());
        int m = (int) v.size();
        for (int i=0; i<m; ) {
            int j = i;
            while (j < m && v[i][0] == v[j][0]) {
                st.update(v[j][1], v[j][2], v[j][3]);
                j++;
            }
            if (j < m)
                ret += st.st[1].mx == 2 ? (long long) st.st[1].cnt * (v[j][0] - v[i][0]) : 0;
            i = j;
        }
    }
    cout << ret << "\n";

    return 0;
}