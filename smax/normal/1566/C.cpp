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

int mex(int mask) {
    for (int i=0; i<3; i++)
        if ((~mask >> i) & 1)
            return i;
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<string> s(2);
        cin >> n >> s[0] >> s[1];

        vector<int> dp(4, -1e9);
        dp[0] = 0;
        for (int i=0; i<n; i++) {
            int add = (1 << int(s[0][i] - '0')) | (1 << int(s[1][i] - '0'));
            vector<int> ndp(4, -1e9);
            for (int mask=0; mask<4; mask++) {
                ndp[mask | add] = max(ndp[mask | add], dp[mask]);
                ndp[add] = max(ndp[add], dp[mask] + mex(mask));
            }
            dp.swap(ndp);
        }

        int ret = INT_MIN;
        for (int mask=0; mask<4; mask++)
            ret = max(ret, dp[mask] + mex(mask));
        cout << ret << "\n";
    }

    return 0;
}