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

const int INF = 1e9;

int dp[6][6][5][15626];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<vector<int>> c(n, vector<int>(m));
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int j=0; j<m; j++)
        cin >> b[j];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> c[i][j];

    vector<int> pw(n);
    pw[0] = 1;
    for (int i=1; i<n; i++)
        pw[i] = pw[i-1] * 5;

    auto get = [&] (int mask, int i) -> int {
        return mask / pw[i] % 5;
    };

    auto solve = [&] (auto &self, int i, int j, int flow, int mask) -> int {
        if (i == n) {
            if (j == m - 1)
                return mask == 0 ? 0 : INF;
            return self(self, 0, j + 1, b[j+1], mask);
        }
        int &ret = dp[i][j][flow][mask];
        if (ret != -1)
            return ret;
        ret = self(self, i + 1, j, flow, mask);
        int cap = get(mask, i);
        for (int x=0; x<=min(cap, flow); x++)
            ret = min(ret, c[i][j] + self(self, i + 1, j, flow - x, mask - x * pw[i]));
        return ret;
    };

    memset(dp, -1, sizeof(dp));
    int mask = 0;
    for (int i=0; i<n; i++)
        mask += a[i] * pw[i];
    int ret = solve(solve, 0, 0, b[0], mask);
    cout << (ret >= INF ? -1 : ret) << "\n";

    return 0;
}