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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    int l = 0, r = 2e9 + 5;
    while (l < r) {
        int m = l + (r - l) / 2;
        vector<int> dp(n);
        dp[0] = 0;
        int cur = n - 1;
        for (int i=1; i<n; i++) {
            dp[i] = i;
            for (int j=0; j<i; j++)
                if (abs(a[i] - a[j]) <= (long long) (i - j) * m)
                    dp[i] = min(dp[i], dp[j] + i - j - 1);
            cur = min(cur, dp[i] + n - i - 1);
        }
        if (cur <= k)
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";

    return 0;
}