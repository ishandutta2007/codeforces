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

struct Node {
    long long sum, mn;
};

template<typename T>
struct SegmentTree {
    int n;
    const T id{0, 0};
    vector<T> st;

    T merge(const T &a, const T &b) {
        return {a.sum + b.sum, min(a.mn, a.sum + b.mn)};
    }

    SegmentTree(int _n) : n(_n), st(2 * n, id) {}

    SegmentTree(const vector<int> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = {a[i], min(a[i], 0)};
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
        for (st[p+=n]=val, p>>=1; p>0; p>>=1)
            st[p] = merge(st[p<<1], st[p<<1|1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        SegmentTree<Node> st(a);
        int mx = 0, l = -1, r = -1;
        for (int i=0; i<n; i++) {
            int lo = i, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (s + st.query(i, mid).mn >= 0)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            int j = lo - 1;
            DEBUG(t, i, j);
            if (j - i + 1 > mx) {
                mx = j - i + 1;
                l = i;
                r = j;
            }
        }

        if (mx == 0) cout << "-1\n";
        else cout << l + 1 << " " << r + 1 << "\n";
    }

    return 0;
}