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

const long long INF = 1e18;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> st;

    SegmentTree(int _n) : n(_n), st(2 * n, INF) {}

    SegmentTree(const vector<T> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = min(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ret = INF;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret = min(ret, st[l++]);
            if (r&1) ret = min(ret, st[--r]);
        }
        return ret;
    }

    void update(int p, T val) {
        for (st[p+=n]=val; p>1; p>>=1)
            st[p>>1] = min(st[p], st[p^1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    long long ret = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
        ret += a[i].second;
    }

    sort(a.begin(), a.end());
    DEBUG(ret, a);
    SegmentTree<long long> st1(n), st2(n);
    st1.update(n - 1, 0);
    st2.update(n - 1, a[n-1].first);
    for (int i=n-2; i>=0; i--) {
        int pos = int(lower_bound(a.begin(), a.end(), make_pair(a[i].first + a[i].second, INT_MIN)) - a.begin());
        long long dp = min(st1.query(i + 1, pos), st2.query(pos, n) - a[i].first - a[i].second);
        st1.update(i, dp);
        st2.update(i, dp + a[i].first);
    }
    cout << ret + st1.query(0, 1) << "\n";

    return 0;
}