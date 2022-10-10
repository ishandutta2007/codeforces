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

long long sumSq(long long n) {
    return n * (n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> k(n), h(n);
        for (int i=0; i<n; i++)
            cin >> k[i];
        for (int i=0; i<n; i++)
            cin >> h[i];

        vector<long long> dp(n);
        for (int i=0; i<n; i++) {
            dp[i] = LLONG_MAX;
            long long base = 0;
            for (int j=i; j>=0; j--) {
                base = max(base, (long long) h[j]);
                if (j == 0 || k[j] - k[j-1] >= base)
                    dp[i] = min(dp[i], sumSq(base + k[i] - k[j]) + (j > 0 ? dp[j-1] : 0));
                if (j > 0)
                    base -= k[j] - k[j-1];
            }
        }
        cout << dp[n-1] << "\n";
    }

    return 0;
}