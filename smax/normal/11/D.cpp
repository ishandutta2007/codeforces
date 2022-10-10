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

bool adj[25][25];
long long dp[1<<19][25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = true;
    }

    long long ret = 0;
    for (int mask=1; mask<1<<n; mask++) {
        int k = __builtin_ctz(mask);
        if (__builtin_popcount(mask) == 1) {
            dp[mask][k] = 1;
        } else {
            for (int i=0; i<n; i++)
                if (mask & (1 << i) && i != k) {
                    for (int j=0; j<n; j++)
                        if (mask & (1 << j) && adj[i][j])
                            dp[mask][i] += dp[mask ^ (1 << i)][j];
                    if (__builtin_popcount(mask) >= 3 && adj[i][k])
                        ret += dp[mask][i];
                }
        }
    }
    cout << ret / 2 << "\n";

    return 0;
}