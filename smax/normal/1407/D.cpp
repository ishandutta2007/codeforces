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

int h[300005], dp[300005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> h[0];
    stack<int> higher, lower;
    higher.push(0);
    lower.push(0);
    for (int i=1; i<n; i++) {
        cin >> h[i];
        dp[i] = dp[i-1] + 1;
        while (!higher.empty() && h[higher.top()] > h[i]) {
            dp[i] = min(dp[i], dp[higher.top()] + 1);
            higher.pop();
        }
        if (!higher.empty()) {
            dp[i] = min(dp[i], dp[higher.top()] + 1);
            if (h[higher.top()] == h[i])
                higher.pop();
        }
        while (!lower.empty() && h[lower.top()] < h[i]) {
            dp[i] = min(dp[i], dp[lower.top()] + 1);
            lower.pop();
        }
        if (!lower.empty()) {
            dp[i] = min(dp[i], dp[lower.top()] + 1);
            if (h[lower.top()] == h[i])
                lower.pop();
        }
        higher.push(i);
        lower.push(i);
    }
    cout << dp[n-1] << "\n";

    return 0;
}