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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int INF = 1e9;

// even, uneven, center, was reverse used, is it Alice's turn
// value: alice - bob
int dp[1005][1005][2][2][2];
bool vis[1005][1005][2][2][2];

int solve(int even, int uneven, bool center, bool rev, bool turn) {
    if (!even && !uneven && !center)
        return 0;
    int &ret = dp[even][uneven][center][rev][turn];
    if (vis[even][uneven][center][rev][turn])
        return ret;
    vis[even][uneven][center][rev][turn] = true;
    if (turn) {
        ret = INF;
        if (!rev && uneven > 0)
            ret = min(ret, solve(even, uneven, center, true, !turn));
        if (even > 0)
            ret = min(ret, solve(even - 1, uneven + 1, center, false, !turn) + 1);
        if (uneven > 0)
            ret = min(ret, solve(even, uneven - 1, center, false, !turn) + 1);
        if (center)
            ret = min(ret, solve(even, uneven, false, false, !turn) + 1);
    } else {
        ret = -INF;
        if (!rev && uneven > 0)
            ret = max(ret, solve(even, uneven, center, true, !turn));
        if (even > 0)
            ret = max(ret, solve(even - 1, uneven + 1, center, false, !turn) - 1);
        if (uneven > 0)
            ret = max(ret, solve(even, uneven - 1, center, false, !turn) - 1);
        if (center)
            ret = max(ret, solve(even, uneven, false, false, !turn) - 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int even = 0, uneven = 0;
        for (int i=0; i<n/2; i++) {
            if (s[i] == '0') {
                if (s[n-i-1] == '0') even++;
                else uneven++;
            } else if (s[n-i-1] == '0') {
                uneven++;
            }
        }
        bool center = n % 2 && s[n/2] == '0';
        int ret = solve(even, uneven, center, false, true);
        if (ret > 0) cout << "BOB\n";
        else if (ret < 0) cout << "ALICE\n";
        else cout << "DRAW\n";
    }

    return 0;
}