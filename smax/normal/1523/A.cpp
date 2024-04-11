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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;

        m = min(m, n - 1);
        vector<vector<int>> q(m);
        for (int i=0; i<n; i++)
            if (s[i] == '0') {
                int cnt = 0;
                if (i > 0 && s[i-1] == '1') cnt++;
                if (i + 1 < n && s[i+1] == '1') cnt++;
                if (cnt == 1) q[0].push_back(i);
            }

        for (int i=0; i<m; i++) {
            for (int j : q[i])
                s[j] = '1';
            if (i + 1 < m) {
                set<int> st;
                for (int j : q[i]) {
                    if (j > 0 && s[j-1] == '0')
                        st.insert(j - 1);
                    if (j + 1 < n && s[j+1] == '0')
                        st.insert(j + 1);
                }
                for (int j : st) {
                    int cnt = 0;
                    if (j > 0 && s[j-1] == '1') cnt++;
                    if (j + 1 < n && s[j+1] == '1') cnt++;
                    if (cnt == 1) q[i+1].push_back(j);
                }
            }
        }
        cout << s << "\n";
    }

    return 0;
}