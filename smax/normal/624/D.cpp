#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const long long INF = 2e18;

int c[1000005];
long long dp[1000005][3];
unordered_set<int> st;

void factor(int x) {
    for (int i=2; 1LL*i*i<=x; i++)
        if (x % i == 0) {
            st.insert(i);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        st.insert(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, a, b;
    cin >> n >> a >> b;
    for (int i=0; i<n; i++)
        cin >> c[i];

    factor(c[0] - 1);
    factor(c[0]);
    factor(c[0] + 1);
    factor(c[n-1] - 1);
    factor(c[n-1]);
    factor(c[n-1] + 1);

    long long ret = LLONG_MAX;
    for (int p : st) {
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for (int i=0; i<n; i++) {
            dp[i+1][1] = min(dp[i][0], dp[i][1]) + a;
            if (c[i] % p == 0) {
                dp[i+1][0] = dp[i][0];
                dp[i+1][2] = min(dp[i][1], dp[i][2]);
            } else if ((c[i] - 1) % p == 0 || (c[i] + 1) % p == 0) {
                dp[i+1][0] = dp[i][0] + b;
                dp[i+1][2] = min(dp[i][1], dp[i][2]) + b;
            } else {
                dp[i+1][0] = dp[i+1][2] = INF;
            }
        }
        ret = min({ret, dp[n][0], dp[n][1], dp[n][2]});
    }

    cout << ret << "\n";

    return 0;
}