#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const long long INF = 1e18;

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

        vector<long long> dp(4, INF);
        dp[0] = 0;
        for (int i=0; i<=n; i++) {
            int l = i == 0 ? 0 : a[i-1], r = i == n ? 0 : a[i];
            vector<long long> ndp(4, INF);
            for (int j=0; j<4; j++) {
                // insert nothing
                ndp[j] = min(ndp[j], dp[j] + (i == 0 || i == n ? 0 : abs(r - l)));
                // insert 1
                if (~j & 1)
                    ndp[j|1] = min(ndp[j|1], dp[j] + (i == 0 ? 0 : abs(1 - l)) + (i == n ? 0 : abs(r - 1)));
                // insert x
                if (~j & 2)
                    ndp[j|2] = min(ndp[j|2], dp[j] + (i == 0 ? 0 : abs(x - l)) + (i == n ? 0 : abs(r - x)));
                // insert both 1 and x
                if (j == 0)
                    ndp[3] = min(ndp[3], dp[0] + min((i == 0 ? 0 : abs(1 - l)) + (i == n ? 0 : abs(r - x)), (i == 0 ? 0 : abs(x - l)) + (i == n ? 0 : abs(r - 1))) + abs(x - 1));
            }
            dp.swap(ndp);
        }
        cout << dp[3] << "\n";
    }

    return 0;
}