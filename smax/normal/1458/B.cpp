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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++)
        cin >> a[i] >> b[i];

    int A = accumulate(a.begin(), a.end(), 0), B = accumulate(b.begin(), b.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(A + 1, -INF)), ndp;
    dp[0][0] = 0;
    for (int i=0; i<n; i++) {
        ndp = dp;
        for (int j=0; j<=i; j++)
            for (int k=0; k<=A-a[i]; k++)
                ndp[j+1][k+a[i]] = max(ndp[j+1][k+a[i]], dp[j][k] + b[i]);
        dp.swap(ndp);
    }

    for (int j=1; j<=n; j++) {
        int ret = 0;
        for (int k=0; k<=A; k++)
            ret = max(ret, min(dp[j][k] + B, 2 * k));
        cout << fixed << setprecision(10) << ret / 2.0 << " ";
    }
    cout << "\n";

    return 0;
}