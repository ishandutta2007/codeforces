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

const int MAXA = 1505;
const int MAXN = 505;

int a[MAXN], dp[MAXA][MAXN], best[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));
    for (int i=1; i<MAXA; i++)
        for (int j=0; j<n; j++) {
            if (a[j] == i)
                dp[i][j] = j + 1;
            else if (dp[i-1][j] != -1)
                dp[i][j] = dp[i-1][dp[i-1][j]];
            else
                dp[i][j] = -1;
        }

    memset(best, 127, sizeof(best));
    best[n] = 0;
    for (int j=n-1; j>=0; j--)
        for (int i=1; i<MAXA; i++)
            if (dp[i][j] != -1)
                best[j] = min(best[j], 1 + best[dp[i][j]]);
    cout << best[0] << "\n";

    return 0;
}