//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 45;
long long dp[3][3][Maxn];
long long mat[3][3];
int other(int a,int b){
    return 3 - a - b;
}
int main(){
    for(int i = 0; i < 3;i++)
        for(int j = 0; j < 3;j++)
            cin >> mat[i][j];
    int n;
    cin >> n;
    for(int i = 0; i< 3;i++)
        for(int j = 0; j < 3;j++){
            if(i == j)
                continue;
            dp[i][j][0] = mat[i][j];
            int k = other(i,j);
            dp[i][j][0] = min(mat[i][k]+mat[k][j],dp[i][j][0]);
//          cerr << dp[i][j][0] << ' ' << " Az " << i+1 << " Be " << j+1 << " Ba " << 1 << " Ta borj" << endl;
        }
    for(int i = 1; i < n+1;i++){
        for(int r = 0; r < 3;r++){
            for(int l = 0;l < 3;l++){
                if(r == l)
                    continue;
                int k = other(r,l);
                // Ya mire be k bad mire be j
                dp[r][l][i] = dp[r][l][i-1] + mat[r][k] + dp[l][r][i-1] + mat[k][l] + dp[r][l][i-1];
                // Ya saf mire be j
                dp[r][l][i] = min(dp[r][l][i],dp[r][k][i-1] + mat[r][l] + dp[k][l][i-1]);
//              cerr << dp[r][l][i] << ' ' << " Az " << r+1 << " Be " << l+1 << " Ba " << i+1 << " Ta borj" << endl;
            }
        }
        for(int s = 0; s < 9;s++)
            for(int r = 0; r < 3;r++)
                for(int l = 0; l < 3;l++)
                    if(r != l){
                        int k = other(r,l);
                        dp[r][l][i] = min(dp[r][l][i],dp[r][k][i]+dp[k][l][i]);
                    }
    }
    cout << dp[0][2][n-1] << endl;
    return 0;
}