//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 2e3+20;
const int Mod = 1e9+7;
long long dp[Maxn][2];
int arr[Maxn];
int main(){
    int n,k;
    cin >> n >> k;
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int now = 1;
    for(int i = 0; i < n;i++){
        int need = k - arr[i];
        for(int j = k+1; j >= 0;j--){
    //      cerr << i << " | 1 | " << j << " : " << dp[j][now] << endl;
            if(j == need-1)
                dp[j][now] = ((j+1) * dp[j+1][1-now]) + dp[j][1-now] + (j * dp[j][1-now]);
            else if(j == need)
                if(j)
                    dp[j][now] = dp[j][1-now] + dp[j-1][1-now];
                else
                    dp[j][now] = dp[j][1-now];
//          else if(j == need+1)
//              dp[j][now] = (j * dp[j][1-now]);
            else
                dp[j][now] = 0;
            dp[j][now] %= Mod;
    //      cerr << i << " | 2 | " << j << " : " << dp[j][now] << endl;
        }
        now = 1 - now;
    }
    cout << dp[0][1-now] << endl;
    return 0;
}