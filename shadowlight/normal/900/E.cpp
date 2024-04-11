#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m;
    string s, t;
    cin >> n >> s >> m;
    vector <vector <int> > prefa(n + 1, vector <int> (2, 0)), prefb(n + 1, vector <int> (2, 0));
    vector <int> prefv(n + 1, 0);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        for (int j = 0; j < 2; j++) {
            prefa[i + 1][j] = prefa[i][j];
            prefb[i + 1][j] = prefb[i][j];
        }
        prefv[i + 1] = prefv[i];
        if (c == 'a') {
            prefa[i + 1][i % 2]++;
        } else if (c == 'b') {
            prefb[i + 1][i % 2]++;
        } else {
            prefv[i + 1]++;
        }
    }
    vector <pair <int, int> > dp(n + 1, {0, 0});
    for (int j = m - 1; j < n; j++) {
        dp[j + 1] = dp[j];
        int pos = j - m + 1;
        int fl = pos % 2;
        if (prefa[j + 1][fl ^ 1] - prefa[pos][fl ^ 1] == 0 && prefb[j + 1][fl] - prefb[pos][fl] == 0) {
            //cout << j << " kek\n";
            auto p = dp[pos];
            p.first++;
            p.second -= prefv[j + 1] - prefv[pos];
            dp[j + 1] = max(dp[j + 1], p);
            //cout << j << " " << p.first << " " << p.second << "\n";
        }
        //cout << dp[j + 1].first << " " << dp[j + 1].second << "\n";
    }
    int maxk = 0, ans = 0;
    for (int j = 0; j <= n; j++) {
        if (maxk < dp[j].first) {
            maxk = dp[j].first;
            ans = -dp[j].second;
        } else if (maxk == dp[j].first) {
            ans = min(ans, -dp[j].second);
        }
    }
    cout << ans;
}