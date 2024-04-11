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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const long long INF = 1e18;

struct SegmentTree {
    int n;
    vector<long long> a, st, lazy;

    SegmentTree(int _n) : n(_n), st(4*n, INF), lazy(4*n) {}

    SegmentTree(const vector<long long> &_a) : n((int) _a.size()), a(_a), st(4*n), lazy(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p] = min(st[2*p], st[2*p+1]);
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

    long long query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (i > r || j < l)
            return INF;
        if (i <= l && r <= j)
            return st[p];
        int m = (l + r) / 2;
        return min(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
    }

    long long query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }

    void update(int p, int l, int r, int i, int j, long long val) {
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
        st[p] = min(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, long long val) {
        update(1, 0, n-1, i, j, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i=1; i<=n; i++)
        cin >> a[i];

    SegmentTree st(n);
    st.update(0, 0, -INF);
    vector<long long> dp(n + 1);
    for (int rep=0; rep<k; rep++) {
        vector<int> last(n + 1);
        for (int i=1; i<=n; i++) {
            if (last[a[i]])
                st.update(0, last[a[i]] - 1, i - last[a[i]]);
            dp[i] = st.query(0, i - 1);
            last[a[i]] = i;
        }
        st = SegmentTree(dp);
    }
    cout << dp[n] << "\n";

    return 0;
}