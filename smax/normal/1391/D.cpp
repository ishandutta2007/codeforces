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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i=0; i<n; i++)
        cin >> grid[i];

    if (n >= 4 && m >= 4) {
        cout << "-1\n";
        return 0;
    }
    if (n == 1 || m == 1) {
        cout << "0\n";
        return 0;
    }

    vector<vector<int>> val;
    if (n <= m) {
        val.resize(n, vector<int>(m));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                val[i][j] = grid[i][j] - '0';
    } else {
        val.resize(m, vector<int>(n));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                val[j][i] = grid[i][j] - '0';
        swap(n, m);
    }

    if (n == 2) {
        vector<int> num;
        for (int j=0; j<m-1; j++)
            num.push_back((val[0][j] + val[0][j + 1] + val[1][j] + val[1][j + 1]) % 2);
        num.push_back(0);
        vector<vector<int>> dp(m - 1, vector<int>(2, INF));
        if (!num[0]) {
            dp[0][0] = dp[0][1] = 1;    // depending on how we toggle, we can enable next matrix
        } else {
            dp[0][num[1]] = 0;
            dp[0][1 - num[1]] = 1;
        }
        for (int j=1; j<m-1; j++) {
            // case 1: currently on
            dp[j][num[j+1]] = min(dp[j][num[j+1]], dp[j-1][1]);
            // case 2: currently off
            dp[j][1 - num[j+1]] = min(dp[j][1 - num[j+1]], dp[j-1][0] + 1);
        }
        cout << min(dp[m-2][0], dp[m-2][1]) << "\n";
    } else {    // n = 3
        vector<vector<int>> num(2);
        for (int j=0; j<m-1; j++)
            for (int i=0; i<2; i++)
                num[i].push_back((val[i][j] + val[i][j + 1] + val[i + 1][j] + val[i + 1][j + 1]) % 2);
        num[0].push_back(0);
        num[1].push_back(0);
        // dp[i][2][2] - is top on, is bottom on?
        vector<vector<vector<int>>> dp(m - 1, vector<vector<int>>(2, vector<int>(2, INF)));
        if (num[0][0] && num[1][0]) {
            dp[0][!num[0][1]][num[1][1]] = 2;   // just top
            dp[0][num[0][1]][!num[1][1]] = 2;   // just bottom
            dp[0][num[0][1]][num[1][1]] = 0;    // neither
            dp[0][!num[0][1]][!num[1][1]] = 2;  // toggle both
        } else if (num[0][0] && !num[0][1]) {
            dp[0][!num[0][1]][num[1][1]] = 2;
            dp[0][num[0][1]][!num[1][1]] = 1;
            dp[0][num[0][1]][num[1][1]] = 1;
            dp[0][!num[0][1]][!num[1][1]] = 2;
        } else if (!num[0][0] && num[1][0]) {
            dp[0][!num[0][1]][num[1][1]] = 1;
            dp[0][num[0][1]][!num[1][1]] = 2;
            dp[0][num[0][1]][num[1][1]] = 1;
            dp[0][!num[0][1]][!num[1][1]] = 2;
        } else {    // !num[0][0] && !num[1][0]
            dp[0][!num[0][1]][num[1][1]] = 2;
            dp[0][num[0][1]][!num[1][1]] = 2;
            dp[0][num[0][1]][num[1][1]] = 1;
            dp[0][!num[0][1]][!num[1][1]] = 1;
        }

//        for (int a=0; a<2; a++)
//            for (int b=0; b<2; b++)
//                DEBUG(a, b, dp[0][a][b])

        for (int j=1; j<m-1; j++) {
//            for (int a=0; a<2; a++)
//                for (int b=0; b<2; b++) {
            // case 1: both on
            dp[j][num[0][j+1]][num[1][j+1]] = min(dp[j][num[0][j+1]][num[1][j+1]], dp[j-1][1][1]);
            // case 2: both off
            dp[j][!num[0][j+1]][!num[1][j+1]] = min(dp[j][!num[0][j+1]][!num[1][j+1]], dp[j-1][0][0] + 1);
            // case 3: just bottom on
            dp[j][!num[0][j+1]][num[1][j+1]] = min(dp[j][!num[0][j+1]][num[1][j+1]], dp[j-1][0][1] + 1);
            // case 4: just top on
            dp[j][num[0][j+1]][!num[1][j+1]] = min(dp[j][num[0][j+1]][!num[1][j+1]], dp[j-1][1][0] + 1);
        }
        cout << min({dp[m-2][0][0], dp[m-2][0][1], dp[m-2][1][0], dp[m-2][1][1]}) << "\n";
    }

    return 0;
}