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

long long dp[10000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + x);
        if (i > 0 && 2 * i <= n)
            dp[2*i] = min(dp[2*i], dp[i] + y);
        if (i > 1 && 2 * i - 1 <= n)
            dp[2*i-1] = min(dp[2*i-1], dp[i] + x + y);
    }
    cout << dp[n] << "\n";

    return 0;
}