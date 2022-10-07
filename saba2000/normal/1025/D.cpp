#include<bits/stdc++.h>
using namespace std;
int f[1009][1009];
int dp[709][709][2];
int F[709][709];
int a[709];
main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i =0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(__gcd(a[i],a[j])>1) f[i][j] = 1;
            else f[i][j] = 0;
        }
    }

    for(int l = 0; l <= n; l++){
        for(int j = l - 1; j < n; j++){
            int i = j - l + 1;
            if(i > j)
            {
                dp[i][j][0] = 1, dp[i][j][1] = 1;
                continue;
            }
            for(int k = i; k <= j; k++){
                if(dp[i][k-1][0] && dp[k+1][j][1]){
                    F[i][j] = 1;
                    if(f[k][j+1]) dp[i][j][0] =1;
                    if(i && f[k][i-1]) dp[i][j][1] =1;
                }
            }
        }
    }
    if(F[0][n-1]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}