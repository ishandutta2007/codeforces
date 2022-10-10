#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

//        sort(a, a + n);
//        set<int> st;
//        map<int, int> mp;
//        int ret = 0, mx = 0;
//        for (int i=0; i<n; i++) {
//            st.insert(a[i]);
//            mx = max(mx, ++mp[a[i]]);
//            ret = max(ret, min(mx, (int) st.size() - 1));
//        }
//
//        cout << ret << "\n";

        pair<int, int> mx;
        map<int, int> mp;
        for (int i=0; i<n; i++)
            mx = max(mx, {++mp[a[i]], a[i]});

        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            bool ok = (m <= mx.first);
            int diff = mx.first - m;
            set<int> st;
            for (int i=0; i<n; i++)
                if ((a[i] == mx.second && diff > 0) || a[i] != mx.second)
                    st.insert(a[i]);
            if (ok && st.size() >= m)
                l = m + 1;
            else
                r = m;
        }

        cout << l - 1 << "\n";
    }

    return 0;
}