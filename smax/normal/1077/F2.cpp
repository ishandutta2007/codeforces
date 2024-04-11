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

int a[5000];
long long dp[5001][5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k, x;
    cin >> n >> k >> x;
    for (int i=0; i<n; i++)
        cin >> a[i];

    memset(dp, 128, sizeof(dp));
    dp[0][0] = 0;
    for (int j=1; j<=x; j++) {
        deque<pair<long long, int>> dq;
        dq.push_back({dp[0][j-1], 0});
        for (int i=1; i<=n; i++) {
            if (i > k && dq.front().second == i - k - 1)
                dq.pop_front();
            dp[i][j] = dq.front().first + a[i-1];
            while (!dq.empty() && dq.back().first <= dp[i][j-1])
                dq.pop_back();
            dq.push_back({dp[i][j-1], i});
        }
    }

    long long ret = -1;
    for (int i=n-k+1; i<=n; i++)
        ret = max(ret, dp[i][x]);

    cout << ret << "\n";

    return 0;
}