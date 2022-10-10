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

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> mp;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        mp[max(x, y)].emplace_back(x, -y);
    }

    vector<vector<pair<int, int>>> levels;
    for (auto &p : mp) {
        sort(p.second.begin(), p.second.end());
        levels.push_back(p.second);
    }

    int m = levels.size();
    vector<vector<long long>> dp(m + 1, vector<long long>(2, INF));
    dp[0][0] = 0;
    for (int i=0; i<m; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                dp[i+1][1-k] = min(dp[i+1][1-k], dp[i][j] +
                abs(levels[i][k ? (int) levels[i].size() - 1 : 0].first - (i > 0 ? levels[i-1][j ? (int) levels[i-1].size() - 1 : 0].first : 0)) +
                abs(levels[i][k ? (int) levels[i].size() - 1 : 0].second - (i > 0 ? levels[i-1][j ? (int) levels[i-1].size() - 1 : 0].second : 0)) +
                abs(levels[i][0].first - levels[i].back().first) + abs(levels[i][0].second - levels[i].back().second));
    cout << min(dp[m][0], dp[m][1]) << "\n";

    return 0;
}