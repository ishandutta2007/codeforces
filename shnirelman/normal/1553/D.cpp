//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*
2
aaaaaaa
a
aaaaaaaa
a
*/

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(m + 1, vector<int>(2, INF));
    dp[0][0] = dp[0][1] = -1;
    int mx = 0;
    vector<vector<vector<int>>> st(2, vector<vector<int>>(26));
    for(int i = 0; i < n; i++) {
        st[i % 2][s[i] - 'a'].push_back(i);
    }

    for(int i = 0; i < m; i++) {
//        if(st[t[i] - 'a'].empty()) {
//            break;
//        }

        int x = t[i] - 'a';

        for(int j = 0; j < 2; j++) if(dp[i][j ^ 1] < INF) {
            auto it = upper_bound(st[j][x].begin(), st[j][x].end(), dp[i][j ^ 1]);
            if(it == st[j][x].end()) {
                continue;
            }
            dp[i + 1][j] = min(dp[i + 1][j], *it);
        }
//        cout << i << ' ' << dp[i + 1][0] << ' ' << dp[i + 1][1] <<endl;

//        auto it = upper_bound(st[s[i] - 'a'].begin(), st[s[i] - 'a'].end(), mx);
//        it--;
//        dp[i] = *it + 1;
//
//        if(dp[i] == t.size() && (n - i - 1) % 2 == 0) {
//            cout << "YES" << '\n';
//            return;
//        }
//
//        mx = max(mx, dp[i]);

    }
    cout << (dp[m][n % 2 ^ 1] < INF  ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}