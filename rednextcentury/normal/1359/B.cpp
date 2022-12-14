#include <iostream>

using namespace std;
string s;
long long dp[100000];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        long long ret=0;
        for (int i=1;i<=n;i++){
            cin>>s;
            s="."+s;
            for (int i=1;i<=m;i++){
                if (s[i]=='*')dp[i]=dp[i-1];
                else {
                    if (i==1) dp[i]=dp[i-1]+x;
                    else {
                        if (s[i-1]=='.') dp[i]=min(dp[i-1]+x,dp[i-2]+y);
                        else dp[i]=dp[i-1]+x;
                    }
                }
            }
            ret+=dp[m];
        }
        cout<<ret<<endl;
    }
}