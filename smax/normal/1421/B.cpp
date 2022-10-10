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

string s[205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> s[i];

        vector<pair<int, int>> ret;
        if (s[0][1] == s[1][0]) {
            // case 1: same from beginning
            if (s[n-2][n-1] == s[0][1])
                ret.emplace_back(n-2, n-1);
            if (s[n-1][n-2] == s[0][1])
                ret.emplace_back(n-1, n-2);
        } else if (s[n-2][n-1] == s[n-1][n-2]) {
            // case 2: same from end
            if (s[0][1] == s[n-2][n-1])
                ret.emplace_back(0, 1);
            if (s[1][0] == s[n-2][n-1])
                ret.emplace_back(1, 0);
        } else {
            // different on both, make top 1, bottom 0
            if (s[0][1] == '0')
                ret.emplace_back(0, 1);
            if (s[1][0] == '0')
                ret.emplace_back(1, 0);
            if (s[n-2][n-1] == '1')
                ret.emplace_back(n-2, n-1);
            if (s[n-1][n-2] == '1')
                ret.emplace_back(n-1, n-2);
        }

        assert((int) ret.size() <= 2);
        cout << ret.size() << "\n";
        for (auto &p : ret)
            cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}