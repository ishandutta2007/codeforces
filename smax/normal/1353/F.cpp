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

int n, m;
long long a[100][100], dp[100][100];

long long check(long long x) {
    if (x > a[0][0])
        return LLONG_MAX;
    memset(dp, 127, sizeof(dp));
    dp[0][0] = a[0][0] - x;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            long long nxt = x + i + j + 1;
            if (i < n && a[i+1][j] >= nxt)
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i+1][j] - nxt);
            if (j < m && a[i][j+1] >= nxt)
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + a[i][j+1] - nxt);
        }
    return dp[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin >> a[i][j];

        long long ret = LLONG_MAX;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                ret = min(ret, check(a[i][j] - i - j));

        cout << ret << "\n";
    }

    return 0;
}