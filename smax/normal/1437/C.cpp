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

int dp[205][405];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> t(n);
        for (int i=0; i<n; i++)
            cin >> t[i];

        sort(t.begin(), t.end());
        memset(dp, 127, sizeof(dp));
        dp[0][1] = 0;
        for (int i=0; i<n; i++) {
            for (int j=1; j<=400; j++) {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(j - t[i]));
            }
        }
        cout << *min_element(dp[n], dp[n] + 405) << "\n";
    }

    return 0;
}