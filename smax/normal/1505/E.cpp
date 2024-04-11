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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i=0; i<h; i++)
        cin >> grid[i];

    vector<vector<int>> dp(h, vector<int>(w, -1));

    auto solve = [&] (auto &self, int r, int c) -> int {
        int &ret = dp[r][c];
        if (ret != -1)
            return ret;
        if (r == h - 1 && c == w - 1)
            return ret = grid[r][c] == '*';
        ret = grid[r][c] == '*';
        array<int, 4> best{INT_MAX, INT_MAX, h - 1, w - 1};
        for (int i=r; i<h; i++)
            for (int j=c; j<w; j++)
                if ((i != r || j != c) && grid[i][j] == '*')
                    best = min(best, {i - r + j - c, self(self, i, j), i, j});
        DEBUG(r, c, ret, best);
        return ret += self(self, best[2], best[3]);
    };

    cout << solve(solve, 0, 0) << "\n";

    return 0;
}