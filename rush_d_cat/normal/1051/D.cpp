#include <iostream>
using namespace std;
const int MOD = 998244353;
int n,k;
int dp[1002][2002][5];
void add(int &x, int y) {
    x = (y + x) % MOD;
}

int main() {
    scanf("%d%d",&n,&k);
    dp[1][1][0] = 1;
    dp[1][1][3] = 1;
    dp[1][2][2] = 1;
    dp[1][2][1] = 1;
    for(int i=1;i<n;i++) {
        for(int j=1;j<=2*i;j++) {
            for(int s=0;s<4;s++) {
                for(int nex=0;nex<4;nex++) {
                    int val = nex ^ s;
                    if (val == 3) {
                        if(s==1||s==2)
                            add(dp[i+1][j+2][nex],dp[i][j][s]);
                        else
                            add(dp[i+1][j+1][nex],dp[i][j][s]);
                    } else if(val == 0){
                        add(dp[i+1][j][nex],dp[i][j][s]);
                    } else {
                        if(s==0||s==3) 
                            add(dp[i+1][j+1][nex], dp[i][j][s]);
                        else
                            add(dp[i+1][j][nex], dp[i][j][s]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<4;i++) add(ans, dp[n][k][i]);
    cout << ans << endl;
}