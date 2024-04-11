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

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> pts(MAX);
    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        pts[l].emplace_back(r, i);
        pts[r + 1].emplace_back(-1, i);
    }

    vector<int> ret;
    set<pair<int, int>, greater<pair<int, int>>> st;
    for (int i=1; i<MAX; i++) {
        for (auto [x, j] : pts[i]) {
            if (x == -1)
                st.erase({i - 1, j});
            else
                st.emplace(x, j);
        }
        while ((int) st.size() > k) {
            ret.push_back(st.begin()->second);
            st.erase(st.begin());
        }
    }

    cout << ret.size() << "\n";
    for (int x : ret)
        cout << x + 1 << " ";
    cout << "\n";

    return 0;
}