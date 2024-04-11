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

const int MAX = 1e7 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> lp(MAX);
    iota(lp.begin(), lp.end(), 0);
    for (int p=2; p<MAX; p++)
        if (lp[p] == p)
            for (int i=2*p; i<MAX; i+=p)
                lp[i] = p;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ret = 1;
        set<int> st;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            int cur = 1;
            while (a > 1) {
                int p = lp[a];
                bool has = false;
                while (a % p == 0) {
                    a /= p;
                    has ^= 1;
                }
                if (has)
                    cur *= p;
            }
            if (st.count(cur)) {
                ret++;
                st.clear();
            }
            st.insert(cur);
        }
        cout << ret << "\n";
    }

    return 0;
}