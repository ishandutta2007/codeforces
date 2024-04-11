#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 5, K = 505;

int n,k;
int cnt[N], card[N];
ll dp[K][5005];
int h[K];
ll res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < k * n; i++) {
        int c; cin >> c; c--; card[c]++;
    }
    for(int i = 0; i < n; i++) {
        int c; cin >> c; c--; cnt[c]++;
    }
    for(int i = 1; i <= k; i++) cin >> h[i];
    for(int i = 0; i < N; i++) {
        if(cnt[i] == 0) continue;
        for(int j = 0; j <= cnt[i]; j++) memset(dp[j], 0, sizeof(dp[j]));
        ll cur = 0;
        for(int j = 1; j <= cnt[i]; j++) {
            for(int t = 0; t <= card[i]; t++) {
                for(int take = 0; take <= min(k, t); take++) {
                    dp[j][t] = max(dp[j][t], dp[j-1][t-take] + h[take]);
                }
                cur = max(cur, dp[j][t]);
            }
        }
        res += cur;
    }
    cout << res << endl;
}