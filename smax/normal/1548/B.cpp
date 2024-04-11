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
    vector<T> st;

    SegmentTree(int _n) : n(_n), st(2 * n) {}

    SegmentTree(const vector<T> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = gcd(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ret = 0;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret = gcd(ret, st[l++]);
            if (r&1) ret = gcd(ret, st[--r]);
        }
        return ret;
    }

    void update(int p, T val) {
        for (st[p+=n]=val; p>1; p>>=1)
            st[p>>1] = gcd(st[p], st[p^1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        for (int i=0; i<n-1; i++)
            a[i] = abs(a[i+1] - a[i]);
        a[n-1] = 1;

        int ret = 0;
        SegmentTree<long long> st(n);
        for (int i=0, j=0; i<n; i++) {
            while (j < n && st.query(0, n) != 1) {
                st.update(j, a[j]);
                j++;
            }
            ret = max(ret, j - i), DEBUG(t, i, j);
            st.update(i, 0);
        }
        cout << ret << "\n";
    }

    return 0;
}