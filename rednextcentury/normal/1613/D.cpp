#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1000000][2][2];
int a[1000000];
bool vis[1000000];
ll mod = 998244353 ;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        ll numOnes = 0;
        for (int i=1;i<=n;i++)cin>>a[i], numOnes += a[i]==1;
        for (int i=1;i<=n;i++) a[i]+=2;
        for (int i=0;i<=n+10;i++) for (int j=0;j<2;j++) for(int k=0;k<2;k++)dp[i][j][k]=0;
        ll ret = 0;
        for (int i=1;i<=n;i++) {
            dp[a[i]][0][0] = (dp[a[i]][0][0]*2 + dp[a[i]-1][0][0] + (a[i]==2))%mod;
            dp[a[i]][1][0] = (dp[a[i]][1][0]*2 + dp[a[i]-2][0][0] + dp[a[i]-2][1][1])%mod;
            dp[a[i]][1][1] = (dp[a[i]][1][1]*2 + dp[a[i]+2][1][0])%mod;
        }
        for (int i=n+5;i>=0;i--) {
            ret = (ret+dp[i][0][0]+dp[i][1][0]+dp[i][1][1])%mod;
        }
        ll add = 1;
        for (int i=0;i<numOnes;i++) add = (add*2)%mod;
        add --;
        add += mod;
        add%=mod;
        ret = (ret+add)%mod;
        cout<<ret<<endl;
    }
}