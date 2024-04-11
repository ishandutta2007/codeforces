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

struct SegmentTree {
    int n;
    vector<int> a, st, lazy;

    SegmentTree(int _n) : n(_n), st(4*n), lazy(4*n) {}

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n), lazy(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] += a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void push(int p, int l, int r) {
        if (lazy[p]) {
            st[p] += lazy[p];
            if (l != r) {
                lazy[2*p] += lazy[p];
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    int query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (i > r || j < l)
            return INT_MIN;
        if (i <= l && r <= j)
            return st[p];
        int m = (l + r) / 2;
        return max(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
    }

    int query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }

    void update(int p, int l, int r, int i, int j, int val) {
        push(p, l, r);
        if (i > r || j < l)
            return;
        if (i <= l && r <= j) {
            st[p] += val;
            if (l != r) {
                lazy[2*p] += val;
                lazy[2*p+1] += val;
            }
            return;
        }
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, val);
        update(2*p+1, m+1, r, i, j, val);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val) {
        update(1, 0, n-1, i, j, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;
    vector<pair<int, int>> a(n), b(m);
    vector<array<int, 3>> c(p);
    for (int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i=0; i<m; i++)
        cin >> b[i].first >> b[i].second;
    for (int i=0; i<p; i++)
        cin >> c[i][0] >> c[i][1] >> c[i][2];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<int> neg(m);
    for (int i=0; i<m; i++)
        neg[i] = -b[i].second;
    SegmentTree st(neg);

    int ret = INT_MIN;
    for (int i=0, j=0; i<n; i++) {
        while (j < p && c[j][0] < a[i].first) {
            int pos = int(upper_bound(b.begin(), b.end(), make_pair(c[j][1], INT_MAX)) - b.begin());
            if (pos < m)
                st.update(pos, m - 1, c[j][2]);
            j++;
        }
        ret = max(ret, st.st[1] - a[i].second);
    }
    cout << ret << "\n";

    return 0;
}