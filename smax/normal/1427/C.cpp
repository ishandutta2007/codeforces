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

int t[100005], x[100005], y[100005], dp[100005], pref[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, n;
    cin >> r >> n;
    memset(dp, 128, sizeof(dp));
    t[0] = dp[0] = pref[0] = 0;
    x[0] = y[0] = 1;
    int ret = 0;
    for (int i=1, j; i<=n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        for (j=i-1; j>=0 && t[i] - t[j] <= 2 * r; j--)
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
        if (j >= 0)
            dp[i] = max(dp[i], pref[j] + 1);
        ret = max(ret, dp[i]);
        pref[i] = max(dp[i], pref[i-1]);
    }
    cout << ret << "\n";

    return 0;
}