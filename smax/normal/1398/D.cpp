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

int r[205], g[205], b[205];
long long dp[205][205][205];

long long solve(int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    return dp[i][j][k] = max({i > 0 && j > 0 ? r[i-1] * g[j-1] + solve(i - 1, j - 1, k) : 0,
                             i > 0 && k > 0 ? r[i-1] * b[k-1] + solve(i - 1, j, k - 1) : 0,
                             j > 0 && k > 0 ? g[j-1] * b[k-1] + solve(i, j - 1, k - 1) : 0});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int R, G, B;
    cin >> R >> G >> B;
    for (int i=0; i<R; i++)
        cin >> r[i];
    for (int i=0; i<G; i++)
        cin >> g[i];
    for (int i=0; i<B; i++)
        cin >> b[i];

    sort(r, r + R);
    sort(g, g + G);
    sort(b, b + B);

    memset(dp, -1, sizeof(dp));
    cout << solve(R, G, B) << "\n";

    return 0;
}