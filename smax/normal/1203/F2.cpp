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

#define MAXN 105

int dp[MAXN][MAXN];
pair<int, int> p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, r;
    cin >> n >> r;
    for (int i=0; i<n; i++)
        cin >> p[i].first >> p[i].second;

    sort(p, p + n, [] (const pair<int, int> &a, const pair<int, int> &b) {
        if ((a.second >= 0) != (b.second >= 0))
            return (a.second >= 0) > (b.second >= 0);
        else if (a.second >= 0)
            return a.first < b.first;
        else
            return a.first + a.second > b.first + b.second;
    });
    memset(dp, 128, sizeof(dp));
    dp[0][0] = r;
    for (int i=0; i<n; i++)
        for (int j=0; j<=i; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (dp[i][j] >= p[i].first)
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + p[i].second);
        }

    for (int j=n; j>=0; j--)
        if (dp[n][j] >= 0) {
            cout << j << "\n";
            return 0;
        }

    return 0;
}