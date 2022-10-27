#include<iostream>
using namespace std;
int dp[5000+2][5000+2];//
int a[5000+2],ans[5000+2];
int main(){
    int n;cin>>n;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][i]=a[i]; //i to i
    }
    for(int i=1;i<=n;i++){
        int times[5000+2];//
        memset(times,0,sizeof(times));
        for(int j=i;j<=n;j++){
            if(i==j)
            {
                times[a[i]]++;
                continue;
            }
            else
            {
                if(a[j]==dp[i][j-1])
                {
                    times[a[j]]++;
                    dp[i][j]=a[j];
                }
                else
                {
                    times[a[j]]++;
                    if(times[a[j]]>=times[dp[i][j-1]])
                    {
                        if(times[a[j]]==times[dp[i][j-1]])
                        {
                            if(a[j]>dp[i][j-1]) dp[i][j]=dp[i][j-1];
                            else dp[i][j]=a[j];
                        }else{
                            dp[i][j]=a[j];
                        }
                    }else
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans[dp[i][j]]++;
           // cout<<dp[i][j]<<endl;
        }
    }
    for(int i=1;i<=n-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[n]<<endl;
    return 0;
}