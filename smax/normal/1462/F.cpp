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

template<int SZ>
struct SegmentTree {
    int n, st[2*SZ];

    void init(int _n) {
        n = _n;
        memset(st, 0, sizeof(int) * 2 * n);
    }

    void build(int _n, int *a) {
        n = _n;
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = st[i<<1] + st[i<<1|1];
    }

    int query(int l, int r) {
        int ret = 0;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret += st[l++];
            if (r&1) ret += st[--r];
        }
        return ret;
    }

    void update(int p, int val) {
        for (st[p+=n]+=val; p>1; p>>=1)
            st[p>>1] = st[p] + st[p^1];
    }
};

int l[200005], r[200005];
SegmentTree<400005> st1, st2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i=0; i<n; i++) {
            cin >> l[i] >> r[i];
            v.push_back(l[i]);
            v.push_back(r[i]);
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i=0; i<n; i++) {
            l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
            r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
        }

        vector<vector<int>> add(2 * n), rem(2 * n);
        for (int i=0; i<n; i++) {
            add[l[i]].push_back(i);
            rem[r[i]].push_back(i);
        }

        // st1 - count segments based on left endpoint
        // st2 - count segments based on right endpoint
        st1.init(2 * n);
        st2.init(2 * n);
        vector<int> ret(n);
        for (int i=0; i<2*n; i++) {
            for (int x : add[i]) {
                st1.update(l[x], 1);
            }
            for (int x : rem[i]) {
                ret[x] += st1.query(0, i + 1);
                ret[x] += st2.query(l[x], r[x]);
            }
            for (int x : rem[i]) {
                st1.update(l[x], -1);
                st2.update(r[x], 1);
            }
        }

        int ans = INT_MAX;
        for (int i=0; i<n; i++)
            ans = min(ans, n - ret[i]);
        cout << ans << "\n";
    }

    return 0;
}