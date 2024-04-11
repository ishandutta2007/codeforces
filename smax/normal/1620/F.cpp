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

const int INF = 1e9;

int dp[1000000][2][2];
pair<int, int> par[1000000][2][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i=0; i<n; i++)
            cin >> p[i];

        for (int i=0; i<n; i++)
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++)
                    dp[i][j][k] = INF;

        dp[0][0][0] = dp[0][0][1] = -INF;
        for (int i=1; i<n; i++)
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++) {
                    int one = j == 0 ? p[i-1] * (k == 0 ? 1 : -1) : dp[i-1][j][k];
                    int two = j == 1 ? p[i-1] * (k == 0 ? 1 : -1) : dp[i-1][j][k];
                    for (int l=0; l<2; l++) {
                        int x = p[i] * (l == 0 ? 1 : -1);
                        if (x < two)
                            continue;
                        if (x < one && one < dp[i][1][l]) {
                            dp[i][1][l] = one;
                            par[i][1][l] = {j, k};
                        } else if (x > one && two < dp[i][0][l]) {
                            dp[i][0][l] = two;
                            par[i][0][l] = {j, k};
                        }
                    }
                }

        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                if (dp[n-1][j][k] < INF) {
                    cout << "YES\n";
                    vector<int> ret;
                    for (int i=n-1; i>=0; i--) {
                        ret.push_back(p[i] * (k == 0 ? 1 : -1));
                        tie(j, k) = par[i][j][k];
                    }
                    for (int i=n-1; i>=0; i--)
                        cout << ret[i] << " ";
                    cout << "\n";
                    goto done;
                }
        cout << "NO\n";
        done:;
    }

    return 0;
}