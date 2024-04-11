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
        memset(st, 0, sizeof(st));
    }

    int query(int l, int r) {
        int ret = INT_MAX;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret = min(ret, st[l++]);
            if (r&1) ret = min(ret, st[--r]);
        }
        return ret;
    }

    void update(int p, int val) {
        for (st[p+=n]=val; p>1; p>>=1)
            st[p>>1] = min(st[p], st[p^1]);
    }
};

int last[100005];
SegmentTree<100005> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    st.init(n);
    bool allOne = true;
    vector<bool> has(n + 2);
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        a--;
        if (a > 0) {
            allOne = false;
            if (st.query(0, a) > last[a])
                has[a] = true;
        }
        st.update(a, i);
        last[a] = i;
    }
    for (int a=1; a<=n; a++)
        if (st.query(0, a) > last[a])
            has[a] = true;
    if (!allOne)
        has[0] = true;

    int ret = 0;
    while (has[ret])
        ret++;
    cout << ret + 1 << "\n";

    return 0;
}