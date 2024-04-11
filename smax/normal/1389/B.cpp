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

int a[100000], mx[100000], dp[100000][6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        for (int i=0; i<n; i++)
            cin >> a[i];

        for (int i=0; i<n; i++)
            for (int j=0; j<=z; j++)
                dp[i][j] = -1e9;
        dp[0][0] = a[0];
        for (int j=0; j<=z; j++)
            for (int i=0; i<n; i++) {
                if (i + 1 < n)
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+1]);
                if (i > 0 && j < z)
                    dp[i-1][j+1] = max(dp[i-1][j+1], dp[i][j] + a[i-1]);
            }

        int ret = 0;
        for (int j=0; j<=z; j++)
            for (int i=0; i<=k-2*j; i++)
                ret = max(ret, dp[i][j]);

        cout << ret << "\n";

//        mx[0] = 0;
//        for (int i=1; i<n; i++)
//            mx[i] = max(mx[i-1], a[i-1] + a[i]);
//
//        int cur = 0;
//        for (int i=0; i<=k; i++)
//            cur += a[i];
//        int ret = cur;
//        // fold back
//        int numExtra = 0;
//        for (int i=k; i>=0; i--) {
//            cur -= a[i];
//            numExtra++;
//            int ans = cur;
//            int baZ = z;
//            if (numExtra % 2 && i > 0 && baZ > 0) {
//                ans += a[i-1];
//                baZ--;
//            }
//            if (i > 0)
//                ans += min(numExtra / 2, baZ) * mx[i-1];
//            DEBUG(i, ans)
//            ret = max(ret, ans);
//        }
//
//        cout << ret << "\n";
    }

    return 0;
}