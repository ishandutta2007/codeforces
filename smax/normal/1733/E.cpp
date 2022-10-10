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

    int q;
    cin >> q;
    while (q--) {
        long long t;
        int x, y;
        cin >> t >> x >> y;

        if (x + y > t) {
            cout << "NO\n";
            continue;
        }

        t -= x + y;
        vector dp(121, vector<long long>(121));
        dp[0][0] = t;
        for (int i=0; i<120; i++)
            for (int j=0; j<120; j++) {
                dp[i+1][j] += dp[i][j] / 2;
                dp[i][j+1] += (dp[i][j] + 1) / 2;
                dp[i][j] %= 2;
            }

        int cx = 0, cy = 0;
        for (int rep=0; rep<x+y; rep++) {
            if (dp[cx][cy])
                cx++;
            else
                cy++;
            if (cx == 120 || cy == 120)
                break;
        }
        cout << (cx == x && cy == y ? "YES" : "NO") << "\n";
    }

    return 0;
}