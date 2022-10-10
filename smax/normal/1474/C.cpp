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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        for (int i=0; i<2*n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        vector<int> candidates;
        for (int i=0; i<2*n-1; i++)
            candidates.push_back(a[i] + a.back());
        for (int cur : candidates) {
            int x = cur;
            multiset<int> st(a.begin(), a.end());
            bool ok = true;
            while (!st.empty()) {
                int mx = *st.rbegin();
                st.erase(prev(st.end()));
                auto it = st.find(x - mx);
                if (it == st.end()) {
                    ok = false;
                    break;
                }
                st.erase(it);
                x = mx;
            }
            if (ok) {
                cout << "YES\n" << cur << "\n";
                x = cur;
                st.insert(a.begin(), a.end());
                while (!st.empty()) {
                    int mx = *st.rbegin();
                    st.erase(prev(st.end()));
                    auto it = st.find(x - mx);
                    assert(it != st.end());
                    cout << mx << " " << *it << "\n";
                    st.erase(it);
                    x = mx;
                }
                goto done;
            }
        }
        cout << "NO\n";
        done:;
    }

    return 0;
}