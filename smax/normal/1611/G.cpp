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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i=0; i<n; i++)
            cin >> grid[i];

        // (r + c, r - c)
        int ret = 0;
        for (int rep=0; rep<2; rep++) {
            vector<pair<int, int>> pts;
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (grid[i][j] == '1' && (i + j) % 2 == rep)
                        pts.emplace_back(i, j);
            sort(pts.begin(), pts.end(), [] (const pair<int, int> &a, const pair<int, int> &b) -> bool {
                if (a.first + a.second == b.first + b.second)
                    return a.first - a.second < b.first - b.second;
                return a.first + a.second < b.first + b.second;
            });
            multiset<int> st;
            for (auto [r, c] : pts) {
                auto it = st.upper_bound(r - c);
                if (it == st.begin())
                    ret++;
                else
                    st.erase(prev(it));
                st.insert(r - c);
            }
        }
        cout << ret << "\n";
    }

    return 0;
}