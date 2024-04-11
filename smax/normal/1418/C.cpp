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

const int INF = 1e9;

int a[200005], dp[200005][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        dp[0][0] = 0;
        dp[0][1] = INF;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            for (int j=0; j<2; j++) {
                dp[i][j] = dp[i-1][1-j] + (j && a[i]);
                if (i > 1) dp[i][j] = min(dp[i][j], dp[i-2][1-j] + (j && a[i]) + (j && a[i-1]));
            }
        }
        cout << min(dp[n][0], dp[n][1]) << "\n";
    }

    return 0;
}