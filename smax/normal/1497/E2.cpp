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

template<typename T>
struct SegmentTree {
    int n;
    vector<T> st;

    SegmentTree(int _n) : n(_n), st(2 * n) {}

    SegmentTree(const vector<T> &a) : n((int) a.size()), st(2 * n) {
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = min(st[i<<1], st[i<<1|1]);
    }

    T query(int l, int r) {
        T ret = numeric_limits<T>::max();
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

const int MAX = 1e7 + 5;

int lp[MAX], last[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(lp, lp + MAX, 0);
    for (int p=2; p<MAX; p++)
        if (lp[p] == p)
            for (int i=2*p; i<MAX; i+=p)
                lp[i] = p;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            int cur = 1;
            while (a[i] > 1) {
                int p = lp[a[i]];
                bool has = false;
                while (a[i] % p == 0) {
                    a[i] /= p;
                    has ^= 1;
                }
                if (has)
                    cur *= p;
            }
            a[i] = cur;
            last[cur] = -1;
        }

        set<int> ckpt{-1};
        vector<vector<int>> dp(n, vector<int>(k + 1, n));
        for (int i=0; i<n; i++) {
            ckpt.insert(last[a[i]]);
            last[a[i]] = i;
            for (int j=0; j<=k; j++) {
                auto it = prev(ckpt.end());
                int cnt = 0;
                while (cnt <= j) {
                    int l = *it;
                    dp[i][j] = min(dp[i][j], 1 + (l >= 0 ? dp[l][j-cnt] : 0));
                    if (l == -1)
                        break;
                    it = prev(it);
                    cnt++;
                }
            }
        }
        cout << *min_element(dp[n-1].begin(), dp[n-1].end()) << "\n";
    }

    return 0;
}