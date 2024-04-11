#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 205, mod = (int)1e9 + 7, K = 1005;

int n,k;
int a[N];
ll dp[2][N/2][K];

void add(ll &to, ll from) {
    to = (to + from) % mod;
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int la = 1, now = 0;
    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        swap(la, now);
        for(int j = 0; j <= n / 2; j++) fill(dp[now][j], dp[now][j] + k + 1, 0);
        for(int j = 0; j <= n / 2; j++) {
            for(int rem = 0; rem <= k; rem++) {
                int nrem = rem+j*(a[i]-a[i-1]);
                if(nrem > k) break;
                if(j >= 1) add(dp[now][j-1][nrem], dp[la][j][rem] * j % mod);
                add(dp[now][j+1][nrem], dp[la][j][rem]);
                add(dp[now][j][nrem], dp[la][j][rem] * (j + 1) % mod);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i <= k; i++) res = (res + dp[now][0][i]) % mod;
    cout << res << endl;

}