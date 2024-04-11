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
    int n;
    cin >> n;
    vector <int> a(n), dp(n), pred(n);
    map <int, int> pos;
    int val = 0, p = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (pos.count(x - 1)) {
            dp[i] = dp[pos[x - 1]] + 1;
            pred[i] = pos[x - 1];
        } else {
            dp[i] = 1;
        }
        if (!pos.count(x) || dp[pos[x]] < dp[i]) {
            pos[x] = i;
        }
        if (dp[i] > val) {
            val = dp[i];
            p = i;
        }
    }
    cout << val << "\n";
    vector <int> res;
    for (int i = val - 1; i >= 0; i--) {
        res.push_back(p);
        p = pred[p];
    }
    reverse(res.begin(), res.end());
    for (int x : res) {
        cout << x + 1 << " ";
    }
}