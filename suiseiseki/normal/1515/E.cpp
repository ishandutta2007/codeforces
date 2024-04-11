#include <cstdio>
const int Maxn=400;
int f[Maxn+5][Maxn+5];
int n,Mod;
int pow_2[Maxn+5];
int C[Maxn+5][Maxn+5];
int main(){
    scanf("%d%d",&n,&Mod);
    pow_2[0]=1;
    for(int i=1;i<=n;i++){
        pow_2[i]=(pow_2[i-1]<<1)%Mod;
    }
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
        }
    }
    for(int i=1;i<=n;i++){
        f[i][i]=pow_2[i-1];
        for(int j=1;j<=i;j++){
            for(int k=1;k<i;k++){
                f[i][j]=(f[i][j]+1ll*pow_2[k-1]*C[j][k]%Mod*f[i-k-1][j-k])%Mod;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=(ans+f[n][i])%Mod;
    }
    printf("%d\n",ans);
    return 0;
}