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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int tot = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            tot += a[i] * a[i] * (n - 1);
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
            tot += b[i] * b[i] * (n - 1);
        }

        vector<vector<int>> dp(n, vector<int>(n * 100 + 1, -1));

        auto solve = [&] (auto &self, int i, int sumA, int sumB) -> int {
            if (i == n)
                return 0;
            int &ret = dp[i][sumA];
            if (ret != -1)
                return ret;
            return ret = min(2 * sumA * a[i] + 2 * sumB * b[i] + self(self, i + 1, sumA + a[i], sumB + b[i]), 2 * sumA * b[i] + 2 * sumB * a[i] + self(self, i + 1, sumA + b[i], sumB + a[i]));
        };

        cout << tot + solve(solve, 0, 0, 0) << "\n";
    }

    return 0;
}