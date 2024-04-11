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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int q, d;
        cin >> q >> d;
        while (q--) {
            int a;
            cin >> a;

            if (a % d == 0) {
                cout << "YES\n";
                continue;
            }
            int cur = 0, actual = 0;
            bool ok = false;
            for (int i=0; i<10; i++) {
                cur = (cur + d) % 10;
                actual += d;
                if (actual <= a && cur == a % 10) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                cout << "YES\n";
                continue;
            }

            // number of addends, carry
            vector<vector<int>> dp(10, vector<int>(10, -INF));
            for (int i=1; i<10; i++)
                dp[i][0] = 0;
            while (a > 0) {
                int c = a % 10;
                a /= 10;
                vector<vector<int>> ndp(10, vector<int>(10, -INF));
                for (int i=1; i<10; i++)
                    for (int j=0; j<10; j++)
                        if (dp[i][j] >= 0)
                            for (int k=0; k<=max(i-dp[i][j], 0); k++) {
                                int rem = ((c - j - k * d) % 10 + 10) % 10;
                                for (int l=rem; l<=9*(i-k); l+=10)
                                    ndp[i][(j + k * d + l) / 10] = max(ndp[i][(j + k * d + l) / 10], dp[i][j] + k);
                            }
                dp.swap(ndp);
            }
            ok = false;
            for (int i=1; i<10; i++)
                ok |= dp[i][0] >= i;
            cout << (ok ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}