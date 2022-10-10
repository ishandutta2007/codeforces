#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int pref[1000000], dp[1000000][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        for (int i=0; i<n; i++)
            pref[i] = (i > 0 ? pref[i-1] : 0) + (s[i] == '1');

        dp[0][0] = (s[0] == '1');
        dp[0][1] = (s[0] == '0');
        for (int i=1; i<n; i++) {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + (s[i] == '1');
            dp[i][1] = min(i >= k ? dp[i-k][1] + pref[i-1] - pref[i-k] : INT_MAX, pref[i-1]) + (s[i] == '0');
        }

        cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
    }

    return 0;
}