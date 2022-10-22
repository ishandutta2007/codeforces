#include <iostream>
using namespace std;

bool dp[4002][4002];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p[4005];
        for(int i = 0; i < n * 2; i++) cin >> p[i];
        int d[4005];
        int l = p[0];
        int c = 1;
        int k = 0;
        for(int i = 1; i < n * 2; i++){
            if(p[i] > l){
                d[k] = c;
                l = p[i];
                c = 1;
                k++;
            }
            else c++;
        }
        for(int i = 0; i <= n * 2; i++){
            for(int j = 0; j <= n * 2; j++) dp[i][j] = false;
        }
        dp[0][0] = true;
        for(int i = 1; i <= k; i++){
            for(int j = 0; j <= n * 2; j++) dp[i][j] = dp[i - 1][j];
            for(int j = d[i - 1]; j < n * 2; j++) dp[i][j] |= dp[i - 1][j - d[i - 1]];
        }
        if(dp[k][n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}