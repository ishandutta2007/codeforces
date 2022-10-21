#include <bits/stdc++.h>
using namespace std;

const int N = 5050, INF = (int)1e9;

int n;
int num[N];
int dp[N][N/2], pre[N][N/2];

int cost_l(int i){
    return max(0, num[i-1] - num[i] + 1);
}

int cost_r(int i){
    return max(0, num[i+1] - num[i] + 1);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];
    num[0] = num[n+1] = -INF;
    for(int i = 0; i < N; i++)
        fill(dp[i], dp[i] + N/2, INF), fill(pre[i], pre[i] + N/2, INF);

    for(int j = 1; j <= (n+1)/2; j++){
        for(int i = 1; i <= n; i++){
            if(j == 1){
                dp[i][j] = cost_l(i);

            }
            else{
                if(i >= 3) dp[i][j] = min(dp[i][j], pre[i-3][j-1] + cost_l(i));
                if(i >= 2) dp[i][j] = min(dp[i][j], dp[i-2][j-1] + max(cost_l(i), cost_r(i-2)));
            }
            pre[i][j] = min(pre[i-1][j], dp[i][j] + cost_r(i));
        }
    }
    for(int i = 1; i <= (n+1)/2; i++) cout << pre[n][i] << " ";

}