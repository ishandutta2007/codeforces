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

int dp[505][505], ndp[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        memset(dp, 127, sizeof(dp));
        dp[0][x] = 0;
        for (int i=0; i<n; i++) {
            memset(ndp, 127, sizeof(ndp));
            for (int j=0; j<=500; j++)
                for (int k=0; k<=500; k++) {
                    if (a[i] >= j)
                        ndp[a[i]][k] = min(ndp[a[i]][k], dp[j][k]);
                    if (a[i] > k && k >= j)
                        ndp[k][a[i]] = min(ndp[k][a[i]], dp[j][k] + 1);
                }
            memcpy(dp, ndp, sizeof(dp));
        }

        int ret = INF;
        for (int j=0; j<=500; j++)
            for (int k=0; k<=500; k++)
                ret = min(ret, dp[j][k]);
        cout << (ret >= INF ? -1 : ret) << "\n";
    }

    return 0;
}