#include <iostream>
using namespace std;

typedef long long LL;
const int N=5002;
const LL MOD = 1e9 + 7;
int n; char s[N];
LL dp[N][N],sum[N],pre[N];
LL f[N<<1],inv[N<<1];
LL c(int a,int b){
    return f[a]*inv[b]%MOD*inv[a-b]%MOD;
}

int main(){ 
    inv[1]=1;
    for(int i=2;i<=10000;i++){
        inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    }
    f[0]=1; inv[0]=1;
    for(int i=1;i<=10000;i++){
        f[i]=f[i-1]*i%MOD;
        inv[i]=inv[i-1]*inv[i]%MOD;
    }

    scanf("%d%s",&n,s+1);
    dp[0][0]=1; sum[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = sum[j-1];
            if(pre[s[i]]) dp[i][j] -= dp[pre[s[i]]][j-1];
            dp[i][j]=(dp[i][j]%MOD+MOD)%MOD;
            //printf("dp[%d][%d]=%lld\n", i,j,dp[i][j]);
        }
        for(int j=1;j<=i;j++){
            sum[j] += dp[i][j];
            sum[j] -= dp[pre[s[i]]][j];
            sum[j] = (sum[j] % MOD + MOD) % MOD;
        }
        pre[s[i]]=i;
    }

    LL ans=0;
    for(int i=1;i<=n;i++){
        ans = ans + sum[i] * c(n-i + i-1, i-1) % MOD;
        ans = ans % MOD;
    }
    cout << ans << endl;
}