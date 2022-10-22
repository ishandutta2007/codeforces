#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505;

int n, m, mod;
string str[N];
ll dp[N][N];

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    cin >> n >> m >> mod;
    vector<int> las;
//    for(int i = 0; i < m; i++) {
//        cin >> str[i];
//        vector<int> now;
//        int cur = 0;
//        for(int j = 0; j < n; j++) {
//            while(cur < las.size() && las[cur] < j) {
//                now.push_back(las[cur]);
//                cur++;
//            }
//            if(str[i][j] == '1') {
//                if(cur < las.size() && las[cur] == j) cur++;
//                else now.push_back(j);
//            }
//        }
//        las = now;
//    }
    for(int i = 0; i < m; i++) cin >> str[i];
    int cnt = 0;
    for(int j = 0; j < n; j++) {
        int cur_cnt = 0;
        for(int i = 0; i < m; i++) cur_cnt += str[i][j] == '1';
        if(cur_cnt == 1) cnt++;
    }
    dp[m][cnt / 2] = 1;
    for(int i = m+1; i <= n; i++) {
        for(int k = 0; k <= n / 2; k++) {
            int cnt[3] = {n - i - k + 1, k * 2, i - 1 - k};
            if(k + 1 <= n / 2 && cnt[0] >= 0) {
                dp[i][k+1] += 1LL * cnt[0] * (cnt[0] - 1) / 2 * dp[i-1][k] % mod;
                dp[i][k+1] %= mod;
            }
            if(k - 1 >= 0) {
                dp[i][k-1] += 1LL * cnt[1] * (cnt[1] - 1) / 2 * dp[i-1][k] % mod;
                dp[i][k-1] %= mod;
            }
            if(cnt[0] >= 0) {
                dp[i][k] += 1LL * cnt[0] * cnt[1] * dp[i-1][k] % mod;
                dp[i][k] %= mod;
            }
//            cout << cnt[0] << ", " << cnt[1] << ", " << cnt[2] << endl;
        }
    }
    cout << dp[n][0] << endl;

}