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

#define MAXN 200005

const int INF = 1e9;

int a[MAXN], dp[MAXN][2], pred[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    // 0 - maximal element of end of decreasing sequence
    // 1 - minimal element of end of increasing sequence
    dp[0][0] = INF;
    dp[0][1] = -INF;
    for (int i=1; i<n; i++) {
        dp[i][0] = -INF;
        dp[i][1] = INF;

        // add a[i] to increasing sequence
        if (a[i] > a[i-1] && dp[i-1][0] > dp[i][0]) {
            dp[i][0] = dp[i-1][0];
            pred[i][0] = 0;
        }
        if (a[i] > dp[i-1][1] && a[i-1] > dp[i][0]) {
            dp[i][0] = a[i-1];
            pred[i][0] = 1;
        }

        // add a[i] to decreasing sequence
        if (a[i] < a[i-1] && dp[i-1][1] < dp[i][1]) {
            dp[i][1] = dp[i-1][1];
            pred[i][1] = 1;
        }
        if (a[i] < dp[i-1][0] && a[i-1] < dp[i][1]) {
            dp[i][1] = a[i-1];
            pred[i][1] = 0;
        }
    }

    if (dp[n-1][0] == -INF && dp[n-1][1] == INF) {
        cout << "NO\n";
        return 0;
    }
    vector<int> ret;
    if (dp[n-1][0] != -INF) {
        ret.push_back(0);
        int u = 0;
        for (int i=n-1; i>0; i--) {
            u = pred[i][u];
            ret.push_back(u);
        }
    } else {
        ret.push_back(1);
        int u = 1;
        for (int i=n-1; i>0; i--) {
            u = pred[i][u];
            ret.push_back(u);
        }
    }

    reverse(ret.begin(), ret.end());
    cout << "YES\n";
    for (int x : ret)
        cout << x << " ";
    cout << "\n";

    return 0;
}