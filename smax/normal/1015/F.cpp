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

const int MOD = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int nxt[201][2], dp[201][201][201], dp2[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;
    n *= 2;
    int m = s.length();

    for (int i=0; i<m; i++) {
        int x = (s[i] == ')');
        nxt[i][x] = (i > 0 ? nxt[i-1][s[i-1] == ')'] : 0) + 1;
        nxt[i][1-x] = 0;
        for (int j=0; j<=i; j++)
            if (s.substr(j, i-j) + (x ? '(' : ')') == s.substr(0, i-j+1)) {
                nxt[i][1-x] = i - j + 1;
                break;
            }
    }

    dp[0][0][0] = 1;
    for (int i=0; i<n; i++)
        for (int j=0; j<=n; j++)
            for (int k=0; k<m; k++) {
                if (j < n) {
                    int nk = nxt[k][0];
                    if (nk < m)
                        add(dp[i+1][j+1][nk], dp[i][j][k]);
                }
                if (j > 0) {
                    int nk = nxt[k][1];
                    if (nk < m)
                        add(dp[i+1][j-1][nk], dp[i][j][k]);
                }
            }

    dp2[0][0] = 1;
    for (int i=0; i<n; i++)
        for (int j=0; j<=n; j++) {
            if (j < n)
                add(dp2[i+1][j+1], dp2[i][j]);
            if (j > 0)
                add(dp2[i+1][j-1], dp2[i][j]);
        }

    int ret = dp2[n][0];
    for (int k=0; k<m; k++) {
        ret -= dp[n][0][k];
        if (ret < 0)
            ret += MOD;
    }

    cout << ret << "\n";

    return 0;
}