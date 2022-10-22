#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, m;

string bit(int x) {
    string s = "";
    for (int i = 0; i < n; i++) {
        s += (char) ('0' + x % 2);
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

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
    cin >> n >> m;
    vector <int> masks(n, 0);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        masks[v] += (1 << u);
        masks[u] += (1 << v);
    }
//    for (int i = 0; i < n; i++) {
//        cout << bit(masks[i]) << "\n";
//    }
    vector <int> dp(1 << n, INF);
    vector <pair <int, int> > pred(1 << n, {-1, -1});
    for (int i = 1; i < (1 << n); i++) {
        bool can = true;
        for (int v = 0; v < n; v++) {
            if (((i >> v) & 1) == 0) continue;
            int mask = i ^ (1 << v);
            if ((mask & masks[v]) != mask) {
                can = false;
                break;
            }
        }
        if (can) {
            dp[i] = 0;
            //cout << bit(i) << "\n";
        }
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (((i >> j) & 1) == 0) continue;
            int nm = i | masks[j];
            if (dp[nm] > dp[i] + 1) {
                dp[nm] = dp[i] + 1;
                pred[nm] = {i, j};
            }
        }
    }
    int v = (1 << n) - 1;
    cout << dp[v] << "\n";
    vector <int> ans;
    while (dp[v]) {
        auto p = pred[v];
        v = p.first;
        ans.push_back(p.second);
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x + 1 << " ";
    }
}