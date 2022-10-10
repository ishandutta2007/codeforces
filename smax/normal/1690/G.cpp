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
struct SegmentTree {
    int n;
    const T id = numeric_limits<T>::max();
    vector<T> st;

    T merge(const T &a, const T &b) {
        return min(a, b);
    }

    SegmentTree(int _n) : n(_n), st(2 * n, id) {}

    SegmentTree(const vector<T> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = merge(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ls = id, rs = id;
        for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
            if (l&1) ls = merge(ls, st[l++]);
            if (r&1) rs = merge(st[--r], rs);
        }
        return merge(ls, rs);
    }

    void update(int p, T val) {
        for (st[p+=n]+=val, p>>=1; p>0; p>>=1)
            st[p] = merge(st[p<<1], st[p<<1|1]);
    }
};

struct Walk {
    int n;
    vector<int> st;

    Walk(int _n) : n(_n), st(4 * n, -1) {}

    void update(int p, int l, int r, int i, int v) {
        if (l == r) {
            st[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            update(2 * p, l, m, i, v);
        else
            update(2 * p + 1, m + 1, r, i, v);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void update(int i, int v) {
        update(1, 0, n - 1, i, v);
    }

    void query(int p, int l, int r, int i, int j, int v, vector<int> &ret) {
        if (st[p] < v || i > r || j < l)
            return;
        if (l == r) {
            ret.push_back(l);
            st[p] = -1;
            return;
        }
        int m = (l + r) / 2;
        query(2 * p, l, m, i, j, v, ret);
        query(2 * p + 1, m + 1, r, i, j, v, ret);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void query(int i, int j, int v, vector<int> &ret) {
        if (i > j)
            return;
        query(1, 0, n - 1, i, j, v, ret);
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

        int ret = n;
        SegmentTree<int> st(a);
        Walk walk(n);
        vector<bool> conn(n);
        for (int i=1; i<n; i++) {
            if (st.query(0, i - 1) <= a[i]) {
                ret--;
                conn[i] = true;
            } else {
                walk.update(i, a[i]);
            }
        }

        for (int i=0; i<m; i++) {
            int k, d;
            cin >> k >> d;
            k--;
            a[k] -= d;
            st.update(k, -d);
            if (k > 0) {
                ret += conn[k];
                conn[k] = st.query(0, k - 1) <= a[k];
                ret -= conn[k];
                walk.update(k, conn[k] ? -1 : a[k]);
            }
            vector<int> cur;
            walk.query(k + 1, n - 1, a[k], cur);
            for (int j : cur) {
                conn[j] = true;
                ret--;
            }
            cout << ret << " \n"[i==m-1];
        }
    }

    return 0;
}