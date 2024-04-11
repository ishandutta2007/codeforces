#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const int N=52;
int n,T;
int t[N],x[N],c[5];
LL f[2][N][N][N*N+50];
LL g[2][N][N*N];
LL cnt[N][N][N];
LL dp[N][N][N][4],fac[N];
int main() {
    fac[0]=1; for(int i=1;i<N;i++) fac[i]=1LL*fac[i-1]*i%MOD;
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++) scanf("%d%d",&t[i],&x[i]), c[x[i]]++;
    f[0][0][0][0]=1,g[0][0][0]=1;
    for(int i=1;i<=n;i++){
        if(x[i]==1||x[i]==2){
            memset(f[1],0,sizeof(f[1]));
            for(int j=0;j<=c[1];j++){
                for(int k=0;k<=c[2];k++){
                    for(int s=0;s<=2500;s++){
                        if(s+t[i]<=2500){
                            if(x[i]==1) (f[1][j+1][k][s+t[i]] += f[0][j][k][s]) %= MOD;
                            if(x[i]==2) (f[1][j][k+1][s+t[i]] += f[0][j][k][s]) %= MOD;
                        }
                        (f[1][j][k][s] += f[0][j][k][s]) %= MOD;
                    }
                }
            }
            for(int j=0;j<=c[1];j++)for(int k=0;k<=c[2];k++)for(int s=0;s<=2500;s++)f[0][j][k][s]=f[1][j][k][s];
        } else {
            memset(g[1],0,sizeof(g[1]));
            for(int j=0;j<=c[3];j++){
                for(int s=0;s<=2500;s++){
                    (g[1][j+1][s+t[i]] += g[0][j][s]) %= MOD;
                    (g[1][j][s] += g[0][j][s]) %= MOD;
                }
            }
            for(int j=0;j<=c[3];j++)for(int s=0;s<=2500;s++)g[0][j][s]=g[1][j][s];
        }
    }
    LL ans=0;
    for(int j=0;j<=c[1];j++){
        for(int k=0;k<=c[2];k++){
            for(int s1=0;s1<=T;s1++){
                for(int l=0;l<=c[3];l++){
                    int s2=T-s1;
                    if(f[0][j][k][s1] && g[0][l][s2]) {
                        //printf("f[%d][%d][%d]=%d, g[%d][%d]=%d\n", j,k,s1,f[0][j][k][s1],l,s2,g[0][l][s2]);
                        (cnt[j][k][l] += 1LL*f[0][j][k][s1]*g[0][l][s2]) %= MOD;
                    }
                }
            }
        }
    }
    dp[0][0][0][0]=1;
    for(int i=0;i<=c[1];i++){
        for(int j=0;j<=c[2];j++){
            for(int k=0;k<=c[3];k++){
                for(int l=i==0?0:1;l<=3;l++){
                    //1
                    if(i<c[1] && l!=1) (dp[i+1][j][k][1] += dp[i][j][k][l]) %= MOD;
                    if(j<c[2] && l!=2) (dp[i][j+1][k][2] += dp[i][j][k][l]) %= MOD;
                    if(k<c[3] && l!=3) (dp[i][j][k+1][3] += dp[i][j][k][l]) %= MOD;
                }
            }
        }
    }
    for(int i=0;i<=c[1];i++)for(int j=0;j<=c[2];j++)for(int k=0;k<=c[3];k++)for(int l=1;l<=3;l++){
        if(cnt[i][j][k] && dp[i][j][k][l]) {
            //printf("# %d %d %d %d ,%d\n", i,j,k,l,dp[i][j][k][l]);
            //printf("$ %d %d %d, %d\n", i,j,k,cnt[i][j][k]);
            ans=ans+1LL*dp[i][j][k][l]*cnt[i][j][k]%MOD*fac[i]%MOD*fac[j]%MOD*fac[k]%MOD;
            ans=ans%MOD;
        }
    }
    cout<<ans<<endl;
}
/*
x*y*z


dp[i][j][k][s]

dp[i][l][t]

*/