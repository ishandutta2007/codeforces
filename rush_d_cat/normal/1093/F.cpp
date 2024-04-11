#include <iostream>
using namespace std;
typedef long long LL;

const int MOD=998244353;
const int N=100000+10;
int n,k,len,a[N];
LL dp[N][102],sum[N];

int cnt[102],tot=0;
int main() {
    scanf("%d%d%d",&n,&k,&len); len--;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp[0][0]=1;
    sum[0]=1;
    for(int i=0;i<n;i++){
        
        if(a[i]>=1) cnt[a[i]]++, tot++;
        if(i-len>=1 && a[i-len]>=1) cnt[a[i-len]]--, tot--;

        int l=1,r=k; if(a[i+1]!=-1) l=a[i+1],r=a[i+1];
        for(int j=l;j<=r;j++){
            (dp[i+1][j]+=dp[i][j])%=MOD;
            (dp[i+1][j]+=sum[i]-dp[i][j]+MOD)%=MOD;
            if(i-len>=0 && cnt[j]==tot)
            ((dp[i+1][j]-=sum[i-len]-dp[i-len][j])+=MOD)%=MOD;
        }   
        sum[i+1]=0;
        for(int j=0;j<=k;j++){
            //printf("dp[%d][%d]=%d\n", i+1,j,dp[i+1][j]);
            sum[i+1]=((sum[i+1]+dp[i+1][j])%MOD+MOD)%MOD;
        }
    }
    printf("%lld\n", sum[n]);
}
/*
i-len  [i-len+1   i] i+1
*/