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

const long long INF = 1e18;

struct Node {
    int l, r;
    long long dp[3][3];

    Node() {
        l = r = -1;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                dp[i][j] = -INF;
    }
};

int w[30005], h[30005], ban[30005];
long long dp[5];

inline long long cost(int l, int r) {
    if (l > r) return 0;
    for (int i=l; i<=r; i++) {
        dp[i-l+1] = -INF;
        if (ban[i] != i)
            dp[i-l+1] = max(dp[i-l+1], dp[i-l] + (long long) w[i] * h[i]);
        if (i > l && ban[i] != i - 1 && ban[i-1] != i)
            dp[i-l+1] = max(dp[i-l+1], dp[i-l-1] + (long long) w[i] * h[i-1] + (long long) w[i-1] * h[i]);
        if (i - l > 1) {
            if (ban[i] != i - 1 && ban[i-1] != i - 2 && ban[i-2] != i)
                dp[i-l+1] = max(dp[i-l+1], dp[i-l-2] + (long long) w[i] * h[i-1] + (long long) w[i-1] * h[i-2] + (long long) w[i-2] * h[i]);
            if (ban[i] != i - 2 && ban[i-1] != i && ban[i-2] != i - 1)
                dp[i-l+1] = max(dp[i-l+1], dp[i-l-2] + (long long) w[i] * h[i-2] + (long long) w[i-1] * h[i] + (long long) w[i-2] * h[i-1]);
        }
    }
    return dp[r-l+1];
}

template<typename T>
struct SegmentTree {
    int n;
    const T id;
    vector<T> st;

    T merge(const T &a, const T &b) {
        if (a.l == -1) return b;
        if (b.l == -1) return a;
        Node ret;
        ret.l = a.l;
        ret.r = b.r;
        if (ret.r - ret.l + 1 >= 4) {
            for (int i=0; i<3; i++)
                for (int j=0; j<3; j++)
                    for (int k=0; k<3; k++)
                        for (int l=0; l<3; l++)
                            ret.dp[i][l] = max(ret.dp[i][l], a.dp[i][j] + b.dp[k][l] + cost(a.r - j + 1, b.l + k - 1));
        } else {
            for (int i=0; i<3; i++)
                for (int j=0; j<3; j++)
                    if (i + j <= ret.r - ret.l + 1)
                        ret.dp[i][j] = cost(ret.l + i, ret.r - j);
        }
        return ret;
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

    void update(int p) {
        st[p+n] = id;
        st[p+n].l = st[p+n].r = p;
        if (ban[p] != p)
            st[p+n].dp[0][0] = (long long) w[p] * h[p];
        st[p+n].dp[0][1] = st[p+n].dp[1][0] = 0;
        for (p+=n, p>>=1; p>0; p>>=1)
            st[p] = merge(st[p<<1], st[p<<1|1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++)
        cin >> w[i];
    for (int i=0; i<n; i++)
        cin >> h[i];

    vector<int> worder(n), wpos(n), horder(n), hpos(n);
    iota(worder.begin(), worder.end(), 0);
    iota(horder.begin(), horder.end(), 0);
    sort(worder.begin(), worder.end(), [&] (int i, int j) -> bool {
        return w[i] < w[j];
    });
    sort(horder.begin(), horder.end(), [&] (int i, int j) -> bool {
        return h[i] < h[j];
    });
    for (int i=0; i<n; i++)
        wpos[worder[i]] = hpos[horder[i]] = i;
    for (int i=0; i<n; i++)
        ban[i] = hpos[worder[i]];
    sort(w, w + n);
    sort(h, h + n);
    vector<Node> init(n);
    for (int i=0; i<n; i++) {
        init[i].l = init[i].r = i;
        if (ban[i] != i)
            init[i].dp[0][0] = (long long) w[i] * h[i];
        init[i].dp[0][1] = init[i].dp[1][0] = 0;
    }

    SegmentTree<Node> st(init);
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        a = wpos[a];
        b = wpos[b];
        swap(ban[a], ban[b]);
        st.update(a);
        st.update(b);
        cout << st.query(0, n - 1).dp[0][0] << "\n";
    }

    return 0;
}