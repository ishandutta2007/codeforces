#include <iostream>
using namespace std;
typedef long long LL;
const int N=1002;
const LL MOD=1e9+7;
int n,m;
LL f[12][N],g[12][N];
int main(){
    scanf("%d%d",&n,&m);
    f[0][1]=1; g[0][n]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=j;k++){
                (f[i][j]+=f[i-1][k])%=MOD;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=j;k<=n;k++){
                (g[i][j]+=g[i-1][k])%=MOD;
            }
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans=ans+f[m][i]*g[m][j]%MOD;
            ans=ans%MOD;
        }
    }
    cout<<ans<<endl;
}