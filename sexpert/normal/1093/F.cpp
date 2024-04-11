#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAXK = 1e2 + 5;
const ll MOD = 998244353;
ll dp[MAXN][MAXK], dpsum[MAXN];
int cnt[MAXK];

int main() {
    int n, k, len;
    cin >> n >> k >> len;
    if(len == 0) {
        cout << 0 << endl;
        return 0;
    }
    dpsum[0] = 1;
    deque<int> window;
    for(int pos = 1; pos <= n; pos++) {
        // sw code.
        int x;
        cin >> x;
        if(x < 0)
            x++;
        if(pos >= len + 1) {
            int u = window.front();
            window.pop_front();
            cnt[u]--;
        }
        for(int lst = 1; lst <= k; lst++) {
            if(x != lst && x != 0)
                continue;
            dp[pos][lst] = dpsum[pos - 1];
            if(cnt[0] + cnt[lst] == len - 1) {
                dp[pos][lst] -= (dpsum[pos - len] - dp[pos - len][lst]);
            }
            if(dp[pos][lst] < 0)
                dp[pos][lst] = (dp[pos][lst] + MOD)%MOD;
            dpsum[pos] = (dpsum[pos] + dp[pos][lst])%MOD;
        }
        window.push_back(x);
        cnt[x]++;
    }
    /*for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    cout << dpsum[n] << endl;
}