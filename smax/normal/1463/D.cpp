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
        vector<int> b(n);
        set<int> st;
        for (int i=1; i<=2*n; i++)
            st.insert(i);
        for (int i=0; i<n; i++) {
            cin >> b[i];
            st.erase(b[i]);
        }

        int ret = 0;
        // greedily assign all the peeps biggest element
        vector<int> partner(n, -1);
        set<int> huh;
        int fail = 0;
        for (int i=n-1; i>=0; i--) {
            auto it = st.upper_bound(b[i]);
            if (it != st.begin()) {
                partner[i] = *prev(it);
                st.erase(partner[i]);
                huh.insert(partner[i]);
            } else {
                fail++;
            }
        }
        // set<int> huh(partner.begin(), partner.end());
        if (fail == 0) ret++;
        DEBUG("SURV", ret, huh)
        for (int x=0; x<n; x++) {
            // first x + 1 are the minimum element
            // st.insert(partner[x]);
            auto it = huh.lower_bound(b[x]);
            auto it2 = st.lower_bound(b[x]);
            if (it == huh.end()) {
                // grab new from pool
                auto it = st.lower_bound(b[x]);
                if (it == st.end()) // this part kinda sus
                    break;
                if (partner[x] != -1)
                    st.insert(partner[x]);
                if (partner[x] == -1)
                    fail--;
                st.erase(it);
                if (fail == 0) ret++;
            } else if (it2 == st.end()) {
                // swap with large element
                if (partner[x] == -1)
                    fail--;
                huh.erase(it);
                if (fail == 0) ret++;
            } else {
                // better of two
                if (*it < *it2) {
                    if (partner[x] == -1)
                        fail--;
                    huh.erase(it);
                    if (fail == 0) ret++;
                } else {
                    if (partner[x] != -1)
                        st.insert(partner[x]);
                    if (partner[x] == -1)
                        fail--;
                    st.erase(it2);
                    if (fail == 0) ret++;
                }
            }
        }
        cout << ret << "\n";
    }

    return 0;
}