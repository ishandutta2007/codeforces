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
        int n;
        long long x, y;
        string a, b;
        cin >> n >> x >> y >> a >> b;

        vector dp(1, vector<long long>(3, INF));
        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            vector ndp(2 * (i + 1) + 1, vector<long long>(3, INF));
            for (int j=0; j<=2*i; j++)
                for (int k=0; k<3; k++)
                    if (dp[j][k] < INF) {
                        for (int open=0; open<=2; open++)
                            for (int close=0; close<=min(j,2); close++)
                                for (int back=0; back<=k; back++)
                                    if ((open + close + back) % 2 == (a[i] != b[i]))
                                        ndp[j-close+k-back][open] = min(ndp[j-close+k-back][open], dp[j][k] + x * back + y * close);
                    }
            dp = move(ndp);
        }
        cout << (dp[0][0] == INF ? -1 : dp[0][0]) << "\n";
    }

    return 0;
}