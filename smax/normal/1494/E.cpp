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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<pair<int, int>, char> mp;
    int cnt = 0, edges = 0;
    for (int i=0; i<m; i++) {
        char t;
        cin >> t;
        if (t == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            mp[{u, v}] = c;
            if (mp.count({v, u}))
                edges++;
            if (mp.count({v, u}) && c == mp[{v, u}])
                cnt++;
        } else if (t == '-') {
            int u, v;
            cin >> u >> v;
            if (mp.count({v, u}))
                edges--;
            if (mp.count({v, u}) && mp[{u, v}] == mp[{v, u}])
                cnt--;
            mp.erase({u, v});
        } else {
            int k;
            cin >> k;
            cout << (edges != 0 && (k % 2 || cnt > 0) ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}