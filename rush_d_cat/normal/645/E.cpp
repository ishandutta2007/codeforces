#include <iostream>
#include <vector>
#include <cstring>
const int N = 2000000+10;
const int MOD = 1e9+7;
using namespace std;
typedef long long LL;
int n,m,k;
int dp[N][26]; char s[N];
int pre[26];

int main(){
    scanf("%d%d%s",&n,&k,s+1);
    m=strlen(s+1);
    for(int i=1;i<=m;i++){
        s[i]-='a'; pre[s[i]]=i;
        int sum=1;
        for(int j=0;j<k;j++){
            if(j!=s[i]) {
                dp[i][j]=dp[i-1][j];
                sum=(sum+dp[i-1][j])%MOD;
            }
        }
        dp[i][s[i]]=(sum+dp[i-1][s[i]])%MOD;
    }

    for(int i=m+1;i<=n+m;i++){
        int mn=N,bst;
        for(int j=0;j<k;j++){
            if(pre[j]<mn){
                mn=pre[j]; bst=j;
            }
        }
        pre[bst]=i;
        int sum=1;
        for(int j=0;j<k;j++){
            if(j!=bst) {
                dp[i][j]=dp[i-1][j];
                sum=(sum+dp[i-1][j])%MOD;
            }
        }
        dp[i][bst]=(sum+dp[i-1][bst])%MOD;
    }
    LL ans=0;
    for(int i=0;i<k;i++)ans=(ans+dp[n+m][i])%MOD;
    ans=(ans+1)%MOD;
    cout<<ans<<endl;
}