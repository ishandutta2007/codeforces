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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int lim = INT_MAX;
        vector<bool> has(m + 1);
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            lim = min(lim, a);
            has[a] = true;
        }

        vector<int> dp(m + 1), cnt(m + 1);
        for (int i=1; i<=m; i++) {
            dp[i] = i;
            cnt[i] = has[i];
        }

        int ret = INT_MAX, mx = m;
        for (int mn=m; mn>0; mn--) {
            if (mn <= m / mn)
                for (int i=mn*mn; i<=m; i+=mn) {
                    if (has[i])
                        cnt[dp[i]]--;
                    dp[i] = min(dp[i], dp[i/mn]);
                    if (has[i])
                        cnt[dp[i]]++;
                }
            while (cnt[mx] == 0)
                mx--;
            if (mn <= lim)
                ret = min(ret, mx - mn);
        }
        cout << ret << "\n";
    }

    return 0;
}