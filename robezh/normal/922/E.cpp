#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18;

int n,W,B,X;
int c[1050];
ll cost[1050];
ll dp[1050][10050];

int main(){
    cin >> n >> W >> B >> X;
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i]+10050, -INF);
    dp[0][0] = W;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> cost[i];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= (int)1e4; j++){
            for(int k = 0; k <= c[i]; k++){
                if(j-k >= 0 && dp[i-1][j-k] >= 0){
                    dp[i][j] = max(dp[i][j], min(dp[i-1][j-k] + X, W + 1LL*(j-k)*B) - 1LL*k*cost[i]);
                }
            }
        }
    }
    int maxres = 0;
    for(int i = 1; i <= n; i++) for(int j = maxres+1; j <= (int)1e4; j++) if(dp[i][j] >= 0) maxres = max(maxres, j);

    cout << maxres;
}