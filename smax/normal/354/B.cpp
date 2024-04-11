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

const int MAXN = 20;
const int INF = 1e9;

int n, dp[2*MAXN][1<<MAXN];
vector<pair<int, int>> pos[2*MAXN][26];

int solve(int d, int mask, int cur) {
    int &ret = dp[d][mask];
    if (ret != -1)
        return ret;
    if (d == 2 * n - 2)
        return ret = cur == 0 ? 1 : cur == 1 ? -1 : 0;
    ret = d % 2 ? -INF : INF;
    for (int nxt=0; nxt<26; nxt++) {
        int nmask = 0;
        for (auto [r, c] : pos[d+1][nxt])
            if ((r > 0 && mask & (1 << (r - 1))) || (c > 0 && mask & (1 << r)))
                nmask |= 1 << r;
        if (nmask != 0) {
            if (d % 2)
                ret = max(ret, solve(d + 1, nmask, nxt));
            else
                ret = min(ret, solve(d + 1, nmask, nxt));
        }
    }
    return ret += cur == 0 ? 1 : cur == 1 ? -1 : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int st = -1;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        if (i == 0)
            st = s[0] - 'a';
        for (int j=0; j<n; j++)
            pos[i+j][s[j]-'a'].emplace_back(i, j);
    }

    memset(dp, -1, sizeof(dp));
    int ret = solve(0, 1, st);
    if (ret > 0) cout << "FIRST\n";
    else if (ret == 0) cout << "DRAW\n";
    else cout << "SECOND\n";

    return 0;
}