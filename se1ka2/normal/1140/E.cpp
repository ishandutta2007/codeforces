#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main()
{
    ll n, k;
    cin >> n >> k;
    int a[100002], b[100002];
    for(int i = 0; i < n; i++){
        if(i % 2) cin >> b[i / 2];
        else cin >> a[i / 2];
    }
    ll m = (n + 1) / 2;
    for(int i = 0; i < m - 1; i++){
        if(a[i] != -1 && a[i] == a[i + 1]){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i = 0; i < m; i++){
        if(a[i] == -1){
            int j;
            if(i == 0){
                for(j = i; j < m; j++) if(a[j] != -1) break;
                if(j == m){
                    ans = ans * k % MOD;
                    for(int l = 1; l < m; l++) ans = ans * (k - 1) % MOD;
                }
                else{
                    ll dp[100002][2];
                    dp[1][0] = k - 1;
                    dp[1][1] = 1;
                    for(int l = 2; l <= j - i; l++){
                        dp[l][0] = (dp[l - 1][0] * (k - 2) % MOD + dp[l - 1][1] * (k - 1) % MOD) % MOD;
                        dp[l][1] = dp[l - 1][0];
                    }
                    ans = ans * dp[j - i][0] % MOD;
                }
            }
            else{
                for(j = i; j < m; j++) if(a[j] != -1) break;
                if(j == m){
                    ll dp[100002][2];
                    dp[0][0] = 0;
                    dp[0][1] = 1;
                    for(int l = 1; l <= j - i; l++){
                        dp[l][0] = (dp[l - 1][0] * (k - 2) % MOD + dp[l - 1][1] * (k - 1) % MOD) % MOD;
                        dp[l][1] = dp[l - 1][0];
                    }
                    ans = ans * ((dp[j - i][0] + dp[j - i][1]) % MOD) % MOD;
                }
                else{
                    if(a[i - 1] == a[j]){
                        ll dp[100002][2];
                        dp[0][0] = 0;
                        dp[0][1] = 1;
                        for(int l = 1; l <= j - i; l++){
                            dp[l][0] = (dp[l - 1][0] * (k - 2) % MOD + dp[l - 1][1] * (k - 1) % MOD) % MOD;
                            dp[l][1] = dp[l - 1][0];
                        }
                        ans = ans * dp[j - i][0] % MOD;
                    }
                    else{
                        ll dp[100002][3];
                        dp[0][0] = 0;
                        dp[0][1] = 1;
                        dp[0][2] = 0;
                        for(int l = 1; l <= j - i; l++){
                            dp[l][0] = (dp[l - 1][0] * (k - 3) % MOD +
                                        (dp[l - 1][1] + dp[l - 1][2]) % MOD * (k - 2) % MOD) % MOD;
                            dp[l][1] = (dp[l - 1][0] + dp[l - 1][2]) % MOD;
                            dp[l][2] = (dp[l - 1][0] + dp[l - 1][1]) % MOD;
                        }
                        ans = ans * ((dp[j - i][0] + dp[j - i][1]) % MOD) % MOD;
                    }
                }
            }
            i = j;
        }
    }
    m = n / 2;
    for(int i = 0; i < m - 1; i++){
        if(b[i] != -1 && b[i] == b[i + 1]){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < m; i++){
        if(b[i] == -1){
            int j;
            if(i == 0){
                for(j = i; j < m; j++) if(b[j] != -1) break;
                if(j == m){
                    ans = ans * k % MOD;
                    for(int l = 1; l < m; l++) ans = ans * (k - 1) % MOD;
                }
                else{
                    ll dp[100002][2];
                    dp[1][0] = k - 1;
                    dp[1][1] = 1;
                    for(int l = 2; l <= j - i; l++){
                        dp[l][0] = (dp[l - 1][0] * (k - 2) % MOD + dp[l - 1][1] * (k - 1) % MOD) % MOD;
                        dp[l][1] = dp[l - 1][0];
                    }
                    ans = ans * dp[j - i][0] % MOD;
                }
            }
            else{
                for(j = i; j < m; j++) if(b[j] != -1) break;
                if(j == m){
                    ll dp[100002][2];
                    dp[0][0] = 0;
                    dp[0][1] = 1;
                    for(int l = 1; l <= j - i; l++){
                        dp[l][0] = (dp[l - 1][0] * (k - 2) % MOD + dp[l - 1][1] * (k - 1) % MOD) % MOD;
                        dp[l][1] = dp[l - 1][0];
                    }
                    ans = ans * ((dp[j - i][0] + dp[j - i][1]) % MOD) % MOD;
                }
                else{
                    if(b[i - 1] == b[j]){
                        ll dp[100002][2];
                        dp[0][0] = 0;
                        dp[0][1] = 1;
                        for(int l = 1; l <= j - i; l++){
                            dp[l][0] = (dp[l - 1][0] * (k - 2) % MOD + dp[l - 1][1] * (k - 1) % MOD) % MOD;
                            dp[l][1] = dp[l - 1][0];
                        }
                        ans = ans * dp[j - i][0] % MOD;
                    }
                    else{
                        ll dp[100002][3];
                        dp[0][0] = 0;
                        dp[0][1] = 1;
                        dp[0][2] = 0;
                        for(int l = 1; l <= j - i; l++){
                            dp[l][0] = (dp[l - 1][0] * (k - 3) % MOD +
                                        (dp[l - 1][1] + dp[l - 1][2]) % MOD * (k - 2) % MOD) % MOD;
                            dp[l][1] = (dp[l - 1][0] + dp[l - 1][2]) % MOD;
                            dp[l][2] = (dp[l - 1][0] + dp[l - 1][1]) % MOD;
                        }
                        ans = ans * ((dp[j - i][0] + dp[j - i][1]) % MOD) % MOD;
                    }
                }
            }
            i = j;
        }
    }
    cout << ans << endl;
}