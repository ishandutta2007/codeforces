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

bool dp[501][500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    long long tot = 0;
    dp[0][0] = true;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        tot += a + b;
        for (int j=0; j<k; j++) {
            dp[i][j] = dp[i-1][(j-a%k+k)%k];
            for (int l=0; l<=min(k-1, a); l++)
                if ((a - l) % k + b >= k)
                    dp[i][j] |= dp[i-1][(j-l+k)%k];
        }
    }

    long long ret = 0;
    for (int j=0; j<k; j++)
        if (dp[n][j])
            ret = max(ret, (tot - j) / k);

    cout << ret << "\n";

    return 0;
}