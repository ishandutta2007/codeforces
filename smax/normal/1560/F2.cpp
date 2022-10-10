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

const int INF = 2e9;

long long pw[10], dp[11][11][1<<10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pw[0] = 1;
    for (int i=1; i<10; i++)
        pw[i] = pw[i-1] * 10;

    for (int k=1; k<=10; k++) {
        for (int mask=0; mask<1<<10; mask++)
            dp[k][10][mask] = __builtin_popcount(mask) <= k ? 0 : INF;
        for (int i=9; i>=0; i--)
            for (int mask=0; mask<1<<10; mask++) {
                dp[k][i][mask] = INF;
                for (int d=0; d<10; d++)
                    dp[k][i][mask] = min(dp[k][i][mask], dp[k][i+1][mask|(1<<d)] + d * pw[9-i]);
            }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s = to_string(n);
        s = string(10 - s.size(), '0') + s;

        long long ret = INF, cur = 0;
        int mask = 0;
        bool started = false;
        for (int i=0; i<10; i++) {
            for (int d=s[i]-'0'+1; d<10; d++)
                ret = min(ret, cur + d * pw[9-i] + dp[k][i+1][mask|(1<<d)]);
            cur += int(s[i] - '0') * pw[9-i];
            started |= s[i] != '0';
            if (started)
                mask |= 1 << int(s[i] - '0');
        }
        if (__builtin_popcount(mask) <= k)
            ret = min(ret, cur);
        cout << ret << "\n";
    }

    return 0;
}