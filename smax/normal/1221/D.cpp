#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[300005][3];
 
int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i]>>b[i];
        dp[0][0] =0; dp[0][1] = b[0]; dp[0][2] = 2*b[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                dp[i][j] = LONG_LONG_MAX;
                for(int k=0;k<3;k++){
                    if(a[i]+j!=a[i-1]+k){
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+j*b[i]);
                    }
                }
            }
        }
        cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<"\n";
    }
}