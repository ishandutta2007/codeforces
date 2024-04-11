#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int L = 840, S = 2290, M = 13800;

ll W;
ll b_cnt = 0;
ll cnt[9];
bool dp[M];


int main() {
    cin >> W;
    int sum = 0;
    for(int i = 1; i <= 8; i++) {
        cin >> cnt[i];
        ll bk = cnt[i] / (L / i);
        bk = max(0LL, bk - 1);
        b_cnt += bk;
        cnt[i] -= bk * (L / i);
//        sum += (L / i - 1) * i * 2;
    }
//    cout << sum << endl;
    dp[0] = true;
    for(int i = 1; i <= 8; i++) {
        for(int j = 0; j < cnt[i]; j++) {
            for(int m = M - 1; m >= i; m--) dp[m] |= dp[m - i];
        }
    }
    ll res = 0;
    for(int i = 0; i <= min(1LL * M - 1, W); i++) {
        if(!dp[i]) continue;
        ll bk = min(b_cnt, (W - i) / L);
        res = max(res, bk * L + i);
    }
    cout << res << endl;

}