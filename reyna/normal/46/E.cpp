//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn = 2015;
int mat[Maxn][Maxn];
long long dp[Maxn];
long long Max[Maxn];
long long rMax[Maxn];
int main(){
    int c = 0;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++)
            scanf("%d",&mat[i][j]);
    for(int j = 0; j <= m;j++){
        rMax[j] = -((long long)1 << 60);
        Max[j] = -((long long)1 << 60);
        dp[j] = -((long long)1 << 60);
    }
    for(int i = 0; i < m;i++){
        dp[i] = 0;
        if(i)
            dp[i] = dp[i-1];
        dp[i] += mat[0][i];
    }
    for(int i = m-1; i + 1;--i)
        rMax[i] = max(rMax[i+1],dp[i]);
    Max[0] = mat[0][0];
    for(int i = 1; i < m;i++)
        Max[i] = max(Max[i-1],dp[i]);
    for(int i = 1; i < n;i++){
        long long sum = 0;
        for(int j = 0; j <= m;j++){
            dp[j] = -((long long)1 << 60);
        }
        for(int j = 0; j < m;j++){
            sum += mat[i][j];
            if(i % 2){
                if(j != m-1){
                    dp[j] = sum + rMax[j+1];
                }
            }
            else
                if(j)
                    dp[j] = sum + Max[j-1];
                
        }
        for(int j = 0; j <= m;j++){
            rMax[j] = -((long long)1 << 60);
            Max[j] = -((long long)1 << 60);
        }
        for(int j = m-1; j + 1;--j)
            rMax[j] = max(rMax[j+1],dp[j]);
        Max[0] = dp[0];
        for(int j = 1; j < m;j++)
            Max[j] = max(Max[j-1],dp[j]);
    }
    long long ans = -((long long)1 << 60);
    for(int i = 0; i < m;i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}