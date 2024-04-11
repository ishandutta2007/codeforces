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

const long long INF = 1e18;

long long a[1000005], dp[1000005][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    long long r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i=0; i<=n; i++)
        for (int j=0; j<2; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=0; j<2; j++) {
            // case 1: kill all minions and boss at once
            dp[i+1][0] = min(dp[i+1][0], dp[i][j] + a[i] * r1 + r3);
            dp[i+1][1] = min(dp[i+1][1], dp[i][j] + a[i] * r1 + r3 + 2 * d);
            // case 2: kill all minions and damage boss
            dp[i+1][0] = min(dp[i+1][0], dp[i][j] + min((a[i] + 1) * r1, r2) + r1 + (j ? 0 : 2 * d));
            dp[i+1][1] = min(dp[i+1][1], dp[i][j] + min((a[i] + 1) * r1, r2) + r1 + 2 * d);
        }
    }

    long long rDp = min(a[n-1] * r1 + r3, min((a[n-1] + 1) * r1, r2) + r1 + 2 * d), ret = dp[n][0];
    for (int i=n-2; i>=0; i--) {
        rDp += d + min(a[i] * r1 + r3, min((a[i] + 1) * r1, r2) + r1);
        ret = min(ret, dp[i][0] + rDp);
    }
    cout << ret + (n - 1) * d << "\n";

    return 0;
}