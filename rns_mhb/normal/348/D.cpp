#include <stdio.h>
#include <math.h>
typedef long long ll;
const int mod=1e9+7;
const int N=3009;
char s[N][N];
ll f[N][N],g[N][N];
int n,m;
int main() {
    //freopen("D.in","r",stdin);
    scanf("%d %d\n",&n,&m);
    for (int i=1;i<=n;i++) gets(s[i]+1);
    f[1][1]=g[1][1]=1;
    for (int i=2;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='.') f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
    for (int i=1;i<=n;i++) for (int j=2;j<=m;j++) if (s[i][j]=='.') g[i][j]=(g[i-1][j]+g[i][j-1])%mod;
    ll ans;
    ans=((f[n][m-1]*g[n-1][m]-f[n-1][m]*g[n][m-1])%mod+mod)%mod;
    printf("%d\n",int(ans));
}