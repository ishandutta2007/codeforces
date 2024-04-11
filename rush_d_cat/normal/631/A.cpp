#include<iostream>
using namespace std;
typedef __int64 ll;
const int MAX=1000+2;
ll a[MAX],b[MAX];
ll dp[MAX][MAX],dp1[MAX][MAX];
int main(){
    ll res=-1;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
         cin>>a[i];
         dp[i][i]=a[i];
    }
    for(int i=1;i<=n;i++){
         cin>>b[i];
         dp1[i][i]=b[i];
         res=max(res,a[i]+b[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=dp[i][j-1]|a[j];
            dp1[i][j]=dp1[i][j-1]|b[j];
            res=max(res,dp[i][j]+dp1[i][j]);
        }
    }
    cout<<res<<endl;
    return 0;
}