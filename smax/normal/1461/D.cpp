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

int a[100005];
long long pref[100005];
set<long long> st;
set<pair<int, int>> vis;

void recur(int l, int r) {
    if (l > r || vis.count({l, r}))
        return;
    st.insert(pref[r] - pref[l-1]);
    vis.emplace(l, r);
    if (l != r) {
        int m = (a[l] + a[r]) / 2, idx = upper_bound(a + l, a + r + 1, m) - a;
        recur(l, idx - 1);
        recur(idx, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i=1; i<=n; i++)
            cin >> a[i];

        sort(a + 1, a + n + 1);
        for (int i=1; i<=n; i++)
            pref[i] = a[i] + pref[i-1];
        st.clear();
        vis.clear();
        recur(1, n);
        for (int i=0; i<q; i++) {
            int s;
            cin >> s;
            cout << (st.count(s) ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}