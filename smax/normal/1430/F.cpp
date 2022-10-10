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

const int MAXN = 2005;
const int INF = 1e9 + 5;

int l[MAXN], r[MAXN], a[MAXN];
pair<int, int> dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> l[i] >> r[i] >> a[i];

    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = {INF, 0};
    dp[0][0] = {1, k};

    // dp[i][j] - number of magazines used up to ith wave, j was last position where reloaded
    for (int i=0; i<n; i++)
        for (int j=0; j<=i; j++)
            if (dp[i][j].second + (long long) (r[i] - l[i]) * k >= a[i]) {
                int used = (a[i] - dp[i][j].second + k - 1) / k;
                // no reload
                dp[i+1][j] = min(dp[i+1][j], {dp[i][j].first + used, used * k - a[i] + dp[i][j].second});
                // yes reload
                if (r[i] < l[i+1] || (r[i] > l[i] && dp[i][j].second + (long long) (r[i] - l[i] - 1) * k >= a[i]))
                    dp[i+1][i+1] = min(dp[i+1][i+1], {dp[i][j].first + used + 1, k});
            }

    int ret = INF, extra = 0;
    for (int j=0; j<=n; j++)
        if (dp[n][j].first <= ret) {
            ret = dp[n][j].first;
            extra = max(extra, dp[n][j].second);
        }
    cout << (ret == INF ? -1 : (long long) ret * k - extra) << "\n";

    return 0;
}