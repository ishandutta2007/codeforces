#include<bits/stdc++.h>
#define maxn 500500

using namespace std;
int dp[401][401][401],n,m,a[401];
long long ans,x,y,c,d;

int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++) dp[i][j][1]=a[j]-a[i];
        for (int k=2;k+i<=n;k++){
            int lst=i+k-1;
            for (int j=k+i;j<=n;j++){
                while (lst+1<j&&max(dp[i][lst][k-1],a[j]-a[lst])>max(dp[i][lst+1][k-1],a[j]-a[lst+1])) lst++;
                dp[i][j][k]=max(dp[i][lst][k-1],a[j]-a[lst]);
            }
        }
    }
    while (m--){
        scanf("%lld%lld%lld%lld",&x,&y,&c,&d);
        ans=max(ans,dp[x][y][min(y-x,d+1)]*c);
    }
    cout << ans << endl;
    return 0;
}