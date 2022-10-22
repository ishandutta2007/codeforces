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
    string s;
    cin >> s;
    int n = s.size();
    int k = log2(n);
    int N = (1 << k);
    vector <vector <bool> > dp(n + 1, vector <bool> (N, 0));
    dp[0][0] = 1;
    string ans = "";
    int sz = n - (N - 1);
    vector <pair <int, int> > good;
    good.push_back({0, 0});
    while (ans.size() < sz) {
        char c = 'z';
        for (int j = 0; j < (int) good.size(); j++) {
            auto p = good[j];
            int i = p.first, mask = p.second;
            for (int len = 0; len < k; len++) {
                if ((1 << len) & mask) continue;
                if (!dp[i + (1 << len)][mask | (1 << len)]) {
                    good.push_back({i + (1 << len), mask | (1 << len)});
                    dp[i + (1 << len)][mask | (1 << len)] = 1;
                }
            }
            c = min(c, s[i]);
        }
        vector <pair <int, int> > ngood;
        ans += c;
        for (auto p : good) {
            int i = p.first, mask = p.second;
            if (s[i] == c) {
                ngood.push_back({i + 1, mask});
                dp[i + 1][mask] = 1;
            }
        }
        good = ngood;
    }
    cout << ans;
}