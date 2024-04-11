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

int a[20], b[20];
long long dp[20][2][2][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;

        for (int i=18; i>=0; i--) {
            a[i] = l % 10;
            b[i] = r % 10;
            l /= 10;
            r /= 10;
        }

        memset(dp, 0, sizeof(dp));
        dp[0][1][1][0] = 1;
        for (int i=0; i<19; i++)
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++)
                    for (int l=0; l<4; l++) {
                        int mn = (j ? a[i] : 0), mx = (k ? b[i] : 9);
                        for (int d=mn; d<=mx; d++)
                            dp[i+1][d == mn ? j : 0][d == mx ? k : 0][l + (d != 0)] += dp[i][j][k][l];
                    }

        long long ret = 0;
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                for (int l=0; l<4; l++)
                    ret += dp[19][j][k][l];

        cout << ret << "\n";
    }

    return 0;
}