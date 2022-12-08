#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n, k, ans;
int a[1005];
int f[1005][1005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = -0x3f3f3f3f;
    sort(a + 1, a + 1 + n);
    for(int i = 1; i * (k - 1) <= a[n]; i++) {
        int now = 0;
        f[0][0] = 1;
        for(int j = 1; j <= n; j++) {
            while(a[j] - a[now] >= i) now++;
            f[j][0] = 1;
            for(int l = 1; l <= k; l++) {
                f[j][l] = (f[j - 1][l] + f[now - 1][l - 1]) % mod;
            }
        }
        ans = (ans + f[n][k]) % mod;
    }
    cout << ans << endl;
    return 0;
}