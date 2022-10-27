#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int N=1002;
int n,k,a[N],sum[N];
int dp[N][N];
LL cac(int d){
    for(int i=1;i<=n;i++)dp[1][i]=1;
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            sum[j]=(sum[j-1]+dp[i-1][j])%MOD;
        }
        int low=0; a[low]=-1e9;
        for(int j=1;j<=n;j++){
            while(a[j]-a[low]>=d) low++;
            if(low) dp[i][j]=sum[min(low-1,j-1)];
        }
    }
    LL res=0;
    for(int i=1;i<=n;i++)(res+=dp[k][i])%=MOD;
    //printf("d=%d, res=%d\n", d,res);
    return res;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    LL ans=0;
    for(int d=1;d*(k-1)<=a[n]-a[1];d++)
        (ans+=cac(d))%=MOD;
    cout<<ans<<endl;
}